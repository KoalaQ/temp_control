#include <iom128v.h>
#include "uart.h"

//常量定义
#define BAUDRATE1       115200	//波特率
//#define BAUDRATE2       9600	//波特率
#define F_CPU		7372800//晶振频率

//变量定义
extern unsigned char send_buf[600];
extern unsigned char receive_buf[600];
extern unsigned int send_len;
extern unsigned int receive_len;

unsigned char uart_timeout_flag1;
unsigned char uart_timeout_flag2;

//串口1对应程序
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//USART 初始化
void init_USART1(void)
{
    //USART 115200 8, n,1  PC上位机软件(超级终端等)也要设成同样的设置才能通讯
    UCSR0C = (1<<USBS0)|(3<<UCSZ00);
    
  //异步，8位数据，无奇偶校验，一个停止位，无倍速   
    //U2X=0时的公式计算
    UBRR0L= (F_CPU/BAUDRATE1/16-1)%256;
    UBRR0H= (F_CPU/BAUDRATE1/16-1)/256;

    UCSR0A = 0x00;

    //使能接收中断，使能接收，使能发送
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    
}

//向串口1写数
void put_c1(unsigned char c)
{
	while( !(UCSR0A & (1<<UDRE0)) );
	UDR0=c;	
}

//从串口1读数
unsigned char USART_Receive1( void )
{
   unsigned int j=0;
   uart_timeout_flag1=0; 
  //等待接受标志
  while ( !(UCSR0A & (1<<RXC0)) ){
    if(j==32000) //判断超时，并设置标志
    { uart_timeout_flag1=1;   
    return FAILURE;}
	else 
		j++;
    ;}
  //读接收数据  
  return UDR0;
}

//从串口接收数据串
unsigned char receiveStrfromCom(void)
{
  unsigned char k;

  while(1)
  {
    ///以下为从串口接收数据的过程
    send_buf[0]=USART_Receive1();
    //若接收的不是命令头则继续等待
    if(send_buf[0]!=0x02)continue;
      
    for(k=1;k<5;k++)
    {
        send_buf[k]=USART_Receive1(); 
        if(uart_timeout_flag1==1)
        {  
//          ComSendResponse(send_buf[3],EXE_TIME_OUT,1);
          return FAILURE;
        }  
    }
    
    send_len=send_buf[4];
    
    for(k=5;k<send_len+6;k++)
    {
        send_buf[k]=USART_Receive1(); 
        if(uart_timeout_flag1==1)
        {  
//           ComSendResponse(send_buf[3],EXE_TIME_OUT,1);
           return FAILURE; 
        }  
    }  
    return SUCCESS;

  }  
  return FAILURE;
} 

//向串口输出数据串
void outStrtoCom(unsigned char *pData,unsigned int length)
{
	unsigned char i;
	for(i=0;i<length;i++)
		put_c1(pData[i]);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*-----------------------------------------------
函数名： 　MAC_CalCrc16
功  能：  以字节为单位计算len个数的CRC16校验和，首字节
		  为pInput[0].
参  数：  pInput			为需要计算CRC的数据的指针
          pCrc16			为指向存储CRC值的数组
          ucLen				为需要计算CRC的数据长度
返回值：　无　
作  者：　lz
日  期：  2008-06-18
------------------------------------------------*/
void MAC_CalCrc16(unsigned char  *pInput, unsigned char * pCrc16, unsigned char ucLen)   
{   
    unsigned int value_CRC=0xffff;
    unsigned char i;
    unsigned char j;

	for( i=0; i<ucLen; i++ )
	{	
		value_CRC = value_CRC ^((unsigned int)pInput[i]);
		for (j = 0; j < 8; j++)
		{
			if (value_CRC & 0x0001)
			{
				value_CRC = (value_CRC >> 1) ^ 0x8408;
			}
			else
			{
				value_CRC = (value_CRC >> 1);
			}
		}
	}
	
  	pCrc16[0] = (unsigned char)(value_CRC>>8);
	pCrc16[1] = (unsigned char)(value_CRC);
	
	return;
}


/*-----------------------------------------------
函数名：	MAC_CheckCrc16
功  能：  校验一帧长度为ucLen的数据，pInput[ucLen]
          pInput[ucLen+1]是这帧数据的校验字节。
参  数：  pInput      校验帧的首地址
          ucLen 　　　需校验的数据帧的长度 
返回值：　0表示校验通过，1表示校验失败　
作  者：　lz
日  期：  2008-06-18
------------------------------------------------*/
unsigned char MAC_CheckCrc16(unsigned char * pInput, unsigned char ucLen)
{
	unsigned char CrcChk[2];

	MAC_CalCrc16(pInput,CrcChk,ucLen-2);

	if (CrcChk[0]!=pInput[ucLen-2] || CrcChk[1]!=pInput[ucLen-1])
	{
		return FAILURE; // crc16 fail!
	}
	
	return SUCCESS; // crc16 ok!
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//发送命令响应结果
void ComSendResponse(unsigned char CmdData,unsigned char statusdata,unsigned char LenData)
{
    unsigned char crc_buf[2];
    
    receive_buf[5]= statusdata;

    receive_buf[4]=LenData;

    receive_buf[3]=CmdData;
    
    receive_buf[1]=0x00;receive_buf[2]=0x01;

    receive_buf[0]=0x02;
    
    MAC_CalCrc16(receive_buf, crc_buf,LenData+5); 
    
    receive_buf[LenData+5]=crc_buf[0];
    
    receive_buf[LenData+6]=crc_buf[1];//数据包尾 
    
    init_USART1(); 
    outStrtoCom(receive_buf,LenData+7); 
   
    return;
}

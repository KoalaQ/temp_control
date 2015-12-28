#include <iom128v.h>
#include "uart.h"
#include "temp.h"
#include "main.h"
#define fosc  800000  //晶振8MHZ
#define baud 9600  //波特率
void read_cmd(void);

void uart0_init(void)
{
UCSR0B = 0x00; //关闭UART00
UCSR0A = 0x00; //不使用倍速发送（异步）
UCSR0C =(1<<UCSZ01)|(1<<UCSZ00); //数据位为8位
//UBRR0L=(fosc/16/(baud+1))%6; //异步正常情况下的计算公式
//UBRR0H=(fosc/16/(baud+1))/256;
UBRR0L=103; //异步正常情况下的计算公式.9600
UBRR0H=0x00;
UCSR0B |=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0); //接收使能和发送使能.接收终端打开

}

void putchar0(unsigned char c)
{
while (!(UCSR0A&(1<<UDRE0)));//表明发送器已经准备就绪
UDR0=c; //将要发送的数据装入UDR0寄存器
}


unsigned char getchar0(void)
{
  while(!(UCSR0A& (1<<RXC0)));//表明已经接收完毕
  return UDR0;
}
//读取中断
#pragma interrupt_handler int_ruart0:19
void int_ruart0(void){
   uchar data;
   UCSR0B &=~(1<<RXCIE0); //关中断
   data=UDR0;
   if(read_data_cmd=='z'){//空指令
     if(data>='a' && data<='i'){//指令，记录指令
	   read_data_cmd=data;
	 }//其他不处理，丢弃
	 
   }else{
      if(data==read_data_cmd){//指令，当前指令内容发送完毕
	    read_cmd();//执行获得数据的方法
		read_data_cur=0;
	   read_data_cmd='z';
	 }else if(data>='0' && data<='9'){//数字参数，接收。使用串口工具，发送的是ascii侣�
	    read_data_cache[read_data_cur]=data-0x30;
		read_data_cur++;
		if(read_data_cur>131){//发送数据缓存溢出。上位机发送数据不对。丢弃所有
		  read_data_cur=0;
	      read_data_cmd='z';
		}
	 }else if(data>='a' && data<='i'){
	  //为其他命令字，记录。上位机符合规范发送不会出现此情况。
	  //预防硬件发送数据跑偏，丢弃上一命令字，按新命令字运行
	   read_data_cur=0;
	   read_data_cmd=data;
	 }else{//接收出错，更改指令字为空，抛弃当前数据 
	   read_data_cur=0;
	   read_data_cmd='z';
	 }
   }
   UCSR0B |=1<<RXCIE0; //开中断
}
//发送中断
#pragma interrupt_handler int_suart0:20
void int_suart0(void){
   UCSR0B &=~(1<<UDRIE0); //关中断
   if(send_data_cur<send_data_length){//还有数据存在，继续发送
      UDR0=send_data_cache[send_data_cur];
	  send_data_cur++;
	  UCSR0B |=(1<<UDRIE0); //开中断
   }else{//没有数据啦，清空游标。关中断
    send_data_length=0;
    send_data_cur=0;
   } 
  
}

void puts0(char *s)
{
  while (*s)
  {
    putchar0(*s);
    s++;
  }
  putchar0(0x0a);//回车换行
//putchar0(0x0d);
}
void cmd_oper(uint t){
   switch(read_data_cache[0]){
	  case 0://开始
	    set_start(t);
	    break;
	  case 1://停止
	    set_stop(t);
	    break;
	  case 2://重置
	    reset_temp_data(t);
	  case 3://发送温度参数到串口
	    send_temp_data(t);
	    break;
	}
	
}
void read_cmd(void){
    PORTE=~PORTE;
    switch(read_data_cmd){
	  case 'a':
	    cmd_oper(0);
	    break;
	  case 'b':
	    cmd_oper(1);
	    break;
	 case 'c':
	    cmd_oper(2);
	    break;
	 case 'd':
	    cmd_oper(3);
	    break;
     case 'e':
	    set_temp_data(0,read_data_cache);
	    break;
	 case 'f':
	    set_temp_data(1,read_data_cache);
	    break;
	 case 'g':
	    set_temp_data(2,read_data_cache);
	    break;
	 case 'h':
	    set_temp_data(3,read_data_cache);
	    break;
	 case 'i':
	 switch(read_data_cache[0]){
	  case 0://全部开始
	     set_all_start();
	     break;
	   case 1://全部停止
	     set_all_stop();
	     break;
	   case 2://全部重置
	     reset_temp_data(0);
		 reset_temp_data(1);
		 reset_temp_data(2);
		 reset_temp_data(3);
	     break;
	  }
	    break;
	 default :
	  break;
	}
}


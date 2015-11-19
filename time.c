#include<iom128v.h>
#include "time.h"
#include "delay.h"
#include "lcd.h"
//寄存器宏定义
#define WRITE_SECOND 0x80
#define WRITE_MINUTE 0x82 
#define WRITE_HOUR 0x84
#define WRITE_DAY 0x86
#define WRITE_MONTH 0x88 
#define WRITE_WEEK 0x8A
#define WRITE_YEAE 0x8C
#define WRITE_PROTECT 0x8E 

#define READ_SECOND 0x81 
#define READ_MINUTE 0x83 
#define READ_HOUR 0x85 
#define READ_DAY 0x87
#define READ_MONTH 0x89
#define READ_WEEK 0x8B
#define READ_YEAE 0x8D
#define READ_PROTECT 0x8F


#define  SCLK_H  PORTD|=1<<PD0 //
#define  SCLK_L  PORTD&=~(1<<PD0) //
#define  DIO    PORTD&(~(1<<PD1)) //会获得PB1的值，判断是否等于0来确定值
#define  DIO_H   PORTD|=1<<PD1 //
#define  DIO_L  PORTD&=~(1<<PD1)  //
#define  CE_H    PORTD|=1<<PD2
#define  CE_L   PORTD&=~(1<<PD2) 
//地址、数据发送子程序
void Write1302  ( unsigned char  addr,unsigned char dat )
{ 
  unsigned char  i,temp; 
  CE_L; //CE引脚为低，数据传送中止
  SCLK_L;//清零时钟总线?
  CE_H;//CE引脚为高，逻辑控制有效
  //发送地址?
    for ( i=8; i>0; i-- ) //循环8次移位
    { 
       SCLK_L;
	   temp=addr;
       if((temp&0x01))//每次传输低字节
	   {
	   	DIO_H;
	   }else{
	   DIO_L;
	   }
       addr>>=1;//右移一位
			  SCLK_H;
 }
//发送数据?
for(i=8;i>0;i--){
   SCLK_L; 
   temp=dat;
   if((temp&0x01))//每次传输低字节
	   {
	   	DIO_H;
	   }else{
	   DIO_L;
	   }
	dat>>=1;
    SCLK_H;
  }
   CE_L;
}
//数据读取子程序
unsigned char Read1302( unsigned char addr ){
   unsigned char i,temp,data=0;
   CE_L;
   SCLK_L;
   CE_H;//发送地址?
   for(i=8;i>0;i--)//循环8次移位
   {
      
	   temp=addr;
      if((temp&0x01))//每次传输低字节
	   {
	   	DIO_H;
	   }else{
	   DIO_L;
	   }
	   SCLK_L;
       addr>>=1;//右移一位
	  SCLK_H;
   }
//读取数据
DDRD&=0xFD;
 for(i=0;i<8;i++)
  {
     SCLK_H;
	 SCLK_L;
	 delay_ms(1);
   	 data |=(((PIND&(1<<PD1))>>1)<<i);
           
    }
	///PORTE=data;
   DDRD|=0x07;
    CE_L;
    // temp = data>>4;
   // data &= 0x0f;
    //data = temp*10 + data;
	
    return(data);
}
//初始化DS1302?
void Initial_time(void) {
   DDRD|=0x07;
   PORTD=0x00;
  // Write1302(WRITE_PROTECT,0X00);//禁止写保护
   //Write1302(WRITE_SECOND,0x00);//秒位初始化
   //Write1302(WRITE_MINUTE,0x50);//分钟初始化
  // Write1302(WRITE_HOUR,0xa4);//小时初始化
   Write1302(WRITE_PROTECT,0x80);//写保护
}
//显示时间，时分秒
void showTimeLcd(void){
   //PORTE=~Read1302(0x81);
	if(Read1302(0x85)&0x80){
	if( (Read1302(0x85)>>4)&0x01 )
	{
	 lcd_write_char(0x00,1,0x30|((Read1302(0x85)>>4)&0x01));
	 lcd_write_char_con(1,0x30|(Read1302(0x85)&0x0F));
	}else{
	 lcd_write_char(0x00,1,' ' );
	 lcd_write_char_con(1,0x30|(Read1302(0x85)&0x0F));
	}

	   if(((Read1302(0x85))&0x20)){
	      lcd_write_char(0x05,1, 'P');
	     lcd_write_char_con(1, 'M');
	   }else{
	     lcd_write_char(0x05,1, 'A');
	     lcd_write_char_con(1, 'M');
	    }
	}else{
	 lcd_write_char(0x00,1, 0x30|((Read1302(0x85)>>4)&0x03));
	 lcd_write_char_con(1,0x30|(Read1302(0x85)&0x0F)); 
	}
	
	lcd_write_char(0x01,1,':');
	
	lcd_write_char_con(1, 0x30|Read1302(0x83)>>4);
	lcd_write_char_con(1,0x30|(Read1302(0x83)&0x0F));

	lcd_write_char_con(1,':');
	
	 lcd_write_char_con(1, 0x30|(Read1302(0x81)>>4));
	lcd_write_char_con(1,0x30|(Read1302(0x81)&0x0F));
}







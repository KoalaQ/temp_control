#include<iom128v.h>
#include "time1307.h"
#include "delay.h"
#include "lcd.h"
#include "main.h"
//寄存器宏定义
#define SECOND 0x00
#define MINUTE 0x01 
#define HOUR 0x02
#define DAY 0x04
#define MONTH 0x05 
#define WEEK 0x03
#define YEAE 0x06
#define CIBTPOL 0x07 
#define  WRITEDS1307    0xD0
#define     READDS1307    0xD1


#define  SCL_H  PORTD|=1<<PD0 //
#define  SCL_L  PORTD&=~(1<<PD0) //
#define  SDA_H   PORTD|=1<<PD1 //
#define  SDA_L  PORTD&=~(1<<PD1)  //
/* unsigned char set_rtc_code[7];
unsigned char rtc_address[7]={0x00,0x01,0x02,0x03,0x04,0x05,0x06};
unsigned char read_rtc_code[7];
unsigned char wr_j1j3_code[7];
unsigned char jk[7]={0,0,0,2,0,0,9};//设置时钟初始值*/

unsigned  char BP;


void I2C_start(void){//启动IIC总线
   SDA_H;
   SCL_H;
   delay_us(8);
   SDA_L;
   delay_us(8);
   SCL_L;
   
}
void I2C_stop(void){//启动IIC总线
   SDA_L;
   SCL_H;
   delay_us(8);
   SDA_H;
   delay_us(8);
   SCL_L;
   
}
void I2C_send_ack(void){//应答ack
  SDA_L;
  SCL_H;
  delay_us(8);
  SCL_L;
} 
void I2C_send_noack(void){
  SDA_H;
  SCL_H;
   delay_us(8);
   SCL_L;
}
void I2C_write_byte(unsigned char IIC_data){
   unsigned char i;
  // BP=0;
   for(i=0;i<8;i++){//循环输出数据
      SCL_L;
	   if(((IIC_data<<i)&0x80)){
	      SDA_H;
	   }else{
	   	  SDA_L;
	   }
	   delay_us(4);
	   SCL_H;
	   delay_us(4);
	   SCL_L;
   }
   //读取ACK
   delay_us(4);
   DDRD &=~(0x02);//发送完，等待输入信号
   delay_us(4);
   if((PIND&(1<<PD1))){
    //正常
   }//读取，如果发送的是noack，
   SCL_H;
   delay_us(4);
   SCL_L;
   DDRD |=0x02;
}
unsigned char I2C_read_byte(void){
  unsigned char i,dat;
  DDRD &=~(0x02);
  dat=0;
  for (i=0;i<8;i++)
    {
      dat=dat<<1;
      SCL_H;
      delay_us(4);
     if((PIND&(1<<PD1)))
     {
       dat++;
	  // PORTE=~PORTE;
     }
       SCL_L;  
    }  
  DDRD |=0x02;
  return dat;
}
/***********************************************************************/
/******************************** DS1307 写数据  ****************/
void Write1307(unsigned char add,unsigned char dat)
{
  I2C_start();
  I2C_write_byte(WRITEDS1307);
  I2C_write_byte(add);
  I2C_write_byte(dat);
  I2C_stop();
}
/***********************************************************************/
unsigned int Read1307(unsigned char add)
{
  
  unsigned int dat;
  I2C_start();
  I2C_write_byte(WRITEDS1307);
  I2C_write_byte(add);
  I2C_start();
  I2C_write_byte(READDS1307);
  dat=I2C_read_byte(); 
  I2C_send_noack();
  I2C_stop();      
  return (dat);
 }
//年、月、日、星期、时、分、秒。星期没有写入
void setTime(uint year,uint month,uint day,uint hour,uint minute,uint second){
   Write1307(0x00,second);//
   Write1307(0x01,minute);//
   Write1307(0x02,hour);//
   //Write1307(0x03,0X01);//
   Write1307(0x04,day);//
   Write1307(0x05,month);//
   Write1307(0x06,year);
}
void Initial_time(void){//初始化输出、方波、中断
   DDRD|=0x07;
   PORTD=0x00;
  /* Write1307(0x00,0X00);//
   Write1307(0x01,0X00);//
   Write1307(0x02,0X12);//
   Write1307(0x03,0X01);//
   Write1307(0x04,0X21);//
   Write1307(0x05,0X05);//
   Write1307(0x06,0X15);//*/
    Write1307(0x07,0x10);
   
   EIMSK |= 0x04;//开中断2
   EICRA |=0x30;
   
}
//显示时间，年月日时分秒，用于page调用。没有改变AC，会接着写
void showTime_page(uint y){
   //PORTE=~Read1302(0x81);
   uchar time_cacah;
 //年
    time_cacah=Read1307(0x06);
    lcd_write_str_con(y, "20");
    lcd_write_char_con(y, 0x30|((time_cacah>>4)&0x0F));
    lcd_write_char_con(y,0x30|(time_cacah&0x0F)); 
	lcd_write_char_con(y,'-');
	 //月
	 time_cacah=Read1307(0x05);
	 lcd_write_char_con(y, 0x30|((time_cacah>>4)&0x01));
     lcd_write_char_con(y,0x30|(time_cacah&0x0F)); 
	 lcd_write_char_con(y,'-');
	 //日
	 time_cacah=Read1307(0x04);
	 lcd_write_char_con(y, 0x30|((time_cacah>>4)&0x03));
     lcd_write_char_con(y,0x30|(time_cacah&0x0F)); 
	 lcd_write_char_con(y,' ');
	//时
	time_cacah=Read1307(0x02);
	 lcd_write_char_con(y, 0x30|((time_cacah>>4)&0x03));
	 lcd_write_char_con(y,0x30|(time_cacah&0x0F)); 
	 lcd_write_char_con(y,':');
	//分
	time_cacah=Read1307(0x01);
	 lcd_write_char_con(y, 0x30|time_cacah>>4);
	 lcd_write_char_con(y,0x30|(time_cacah&0x0F));
	 lcd_write_char_con(y,':');
	//秒
	time_cacah=Read1307(0x00);
	 lcd_write_char_con(y, 0x30|(time_cacah>>4));
	 lcd_write_char_con(y,0x30|(time_cacah &0x0F));
}




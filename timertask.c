#include<iom128v.h>
#include "timertask.h"
#include "time.h"
#include "main.h"
#include "lcd.h"
#include "delay.h"
#include "main.h"
#include "temp.h"
#include "out.h"
unsigned int secondflag=64;//8位定时器全计时64次为1s
unsigned char time_h_1, time_l_1,time_h_3, time_l_3,time_0, time_2,i;
//************************************************
//16位定时器，定时器1
//*************************************************
/*
  计数器1，16位的。普通计时，1024分频。在16M下约0.061ms计数一次。共4s钟,
  自行计算时间传入。传入高低八位
*/
void Timerinit_1(uchar time_h,uchar time_l){
    time_h_1=time_h;
	time_l_1=time_l;
	 TCCR1B=0x00;
	//写入初值
    TCNT1H=time_h;
    TCNT1L=time_l;
	//普通计数，1024分频
    TCCR1A=0x00;
    TCCR1B=0x05;
	 TIMSK|=0x04;//开定时器1溢出中断,16位的
}
//************************************************
//16位定时器，定时器3
//*************************************************
/*
  计数器1，16位的。普通计时，1024分频。在16M下约0.061ms计数一次。共4s钟,
  自行计算时间传入。传入高低八位
*/
void Timerinit_3(uchar time_h,uchar time_l){
 	time_h_3=time_h;
	time_l_3=time_l;
	//写入初值
	 TCCR3B=0x00;
    TCNT3H=time_h;
    TCNT3L=time_l;
	//普通计数，1024分频
    TCCR3A=0x00;
    TCCR3B=0x05;
	ETIMSK |=0x04;//开外部中断
}
//************************************************
//8位定时器，定时器0
//*************************************************

/*
  计数器0，8位的。普通计时，1024分频。
  自行计算时间传入。
*/
void Timerinit_0(uchar time){
    time_0=time;
	//写入初值
    TCNT0=time;
	TIMSK|=0x01;//开定时器0溢出中断,8位的
	 TCCR0=0x07;//普通计数，1024分频
	 
}
//************************************************
//8位定时器，定时器2
//*************************************************
/*
  计数器0，8位的。普通计时，1024分频。
  自行计算时间传入。
*/
void Timerinit_2(uchar time){
    time_2=time;
	//写入初值
    TCNT2=time;
	TIMSK|=0x40;//开定时器2溢出中断,8位的
	//普通计数，1024分频
    TCCR2=0x05;
}
#pragma interrupt_handler int_timer0:17
void int_timer0(void){ 
		TCCR0=0x00;
  if(t0_flag==0){
		waitflag--;
	    lcd_write_char(10,0,0x30+(waitflag/100));
	    lcd_write_char(11,0,'s');	
	    if(waitflag>1){
	      TCNT0=0x00;
	      TCCR0=0x07;
	    }
	}else{
	  waitflag--;
	    if(waitflag==1){
		  waitflag=32;
	      tempcontrol();//执行温度调节
	    }
	   TCNT0=0x00;
	   TCCR0=0x07;
	}
		return;
}
//溢出中断。
#pragma interrupt_handler int_timer1:15
void int_timer1(void){
		 TCCR1B=0x00;
		 out_port();
		TCNT1H=time_h_1;
         TCNT1L=time_l_1;
		 TCCR1B=0x05;
		return;
}
#pragma interrupt_handler int_timer2:11
void int_timer2(void){
      //PORTE=~PORTE;
		TCCR2=0x00;
		if(secondflag==0){
		  secondflag=64;
		  int_int2();
		}
		secondflag--;
		TCNT2=time_2;
		TCCR2=0x05;
		return;
}
//16位定时器，定时器3溢出中断。
#pragma interrupt_handler int_timer3:30
void int_timer3(void){
     TCCR3B=0x00;
	 send_data_cache[0]=0x00;
     send_data_cache[1]=0xFF;//A
	 send_data_cache[2]=0xFF;//A
	 
	 send_data_cache[3]=((int)temps[0].actualtemp)>>8;//温度
	 send_data_cache[4]=((int)temps[0].actualtemp)&0xFF;
	 send_data_cache[5]=temps[0].flag;//标志位
	 send_data_cache[6]=temps[0].needtime>>8;//需要时间
	 send_data_cache[7]=temps[0].needtime&8;
	 send_data_cache[8]=temps[0].status;//状态
	 send_data_cache[9]=temps[0].nowtime>>8;//已运行时间
	 send_data_cache[10]=temps[0].nowtime&0xFF;	 
     
	 
	 send_data_cache[11]=((int)temps[1].actualtemp)>>8;//温度
	 send_data_cache[12]=((int)temps[1].actualtemp)&0xFF;
	 send_data_cache[13]=temps[1].flag;//标志位
	 send_data_cache[14]=temps[1].needtime>>8;//需要时间
	 send_data_cache[15]=temps[1].needtime&8;
	 send_data_cache[16]=temps[1].status;//状态
	 send_data_cache[17]=temps[1].nowtime>>8;//已运行时间
	 send_data_cache[18]=temps[1].nowtime&0xFF;	 
     

	 send_data_cache[19]=((int)temps[2].actualtemp)>>8;//温度
	 send_data_cache[20]=((int)temps[2].actualtemp)&0xFF;
	 send_data_cache[21]=temps[2].flag;//标志位
	 send_data_cache[22]=temps[2].needtime>>8;//需要时间
	 send_data_cache[23]=temps[2].needtime&8;
	 send_data_cache[24]=temps[2].status;//状态
	 send_data_cache[25]=temps[2].nowtime>>8;//已运行时间
	 send_data_cache[26]=temps[2].nowtime&0xFF;	 
     
	
	 send_data_cache[27]=((int)temps[3].actualtemp)>>8;//温度
	 send_data_cache[28]=((int)temps[3].actualtemp)&0xFF;
	 send_data_cache[29]=temps[3].flag;//标志位
	 send_data_cache[30]=temps[3].needtime>>8;//需要时间
	 send_data_cache[31]=temps[3].needtime&8;
	 send_data_cache[32]=temps[3].status;//状态
	 send_data_cache[33]=temps[3].nowtime>>8;//已运行时间
	 send_data_cache[34]=temps[3].nowtime&0xFF;	 
     
	 send_data_cache[35]=0x00;//状态
	
	 send_data_cache[36]=0xFE;//A
	 send_data_cache[37]=0xFE;//A
	 
	 
	 send_data_length=38;
	 UCSR0B |=(1<<UDRIE0); //发送使能。测试使用
	  TCNT3H=time_h_3;
      TCNT3L=time_l_3;
      TCCR3B=0x05;
	  return;                                
}
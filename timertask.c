#include<iom128v.h>
#include "timertask.h"
#include "time.h"
#include "lcd.h"
#include "delay.h"
unsigned char time_h_1, time_l_1,time_h_3, time_l_3,time_0, time_2,i;
//************************************************
//16λ��ʱ������ʱ��1
//*************************************************
/*
  ������1��16λ�ġ���ͨ��ʱ��1024��Ƶ����16M��Լ0.061ms����һ�Ρ���4s��,
  ���м���ʱ�䴫�롣����ߵͰ�λ
*/
void Timerinit_1(uchar time_h,uchar time_l){
    time_h_1=time_h;
	time_l_1=time_l;
	 TCCR1B=0x00;
	//д���ֵ
    TCNT1H=time_h;
    TCNT1L=time_l;
	//��ͨ������1024��Ƶ
    TCCR1A=0x00;
    TCCR1B=0x05;
	 TIMSK|=0x04;//����ʱ��1����ж�,16λ��
}
//************************************************
//16λ��ʱ������ʱ��3
//*************************************************
/*
  ������1��16λ�ġ���ͨ��ʱ��1024��Ƶ����16M��Լ0.061ms����һ�Ρ���4s��,
  ���м���ʱ�䴫�롣����ߵͰ�λ
*/
void Timerinit_3(uchar time_h,uchar time_l){
 	time_h_3=time_h;
	time_l_3=time_l;
	//д���ֵ
	 TCCR3B=0x00;
    TCNT3H=time_h;
    TCNT3L=time_l;
	//��ͨ������1024��Ƶ
    TCCR3A=0x00;
    TCCR3B=0x05;
	ETIMSK |=0x04;//���ⲿ�ж�1
}
//************************************************
//8λ��ʱ������ʱ��0
//*************************************************

/*
  ������0��8λ�ġ���ͨ��ʱ��1024��Ƶ��
  ���м���ʱ�䴫�롣
*/
void Timerinit_0(uchar time){
    time_0=time;
	//д���ֵ
    TCNT0=time;
	TIMSK|=0x01;//����ʱ��0����ж�,8λ��
	 TCCR0=0x07;//��ͨ������1024��Ƶ
}
//************************************************
//8λ��ʱ������ʱ��2
//*************************************************
/*
  ������0��8λ�ġ���ͨ��ʱ��1024��Ƶ��
  ���м���ʱ�䴫�롣
*/
void Timerinit_2(uchar time){
    time_2=time;
	//д���ֵ
    TCNT2=time;
	TIMSK|=0x40;//����ʱ��0����ж�,8λ��
	//��ͨ������1024��Ƶ
    TCCR2=0x05;
}
#pragma interrupt_handler int_timer0:17
void int_timer0(void){ 
		TCCR0=0x00;
		//adc_init_once();
		for(i=0;i<5;i++){
  		 lcd_write_char(0x01,3,0x30+i);	
		 delay_ms(100);		
        }
		TCNT0=time_0;
		TCCR0=0x07;
		return;
}
//����жϡ�
#pragma interrupt_handler int_timer1:15
void int_timer1(void){
		 TCCR1B=0x00;
		//adc_init_once();
		for(i=0;i<5;i++){
  		 lcd_write_char(0x03,3,0x30+i);	
		 delay_ms(100);		
        }
		TCNT1H=time_h_1;
         TCNT1L=time_l_1;
		 TCCR1B=0x05;
		return;
}
#pragma interrupt_handler int_timer2:11
void int_timer2(void){
      PORTE=~PORTE;
		TCCR2=0x00;
		for(i=0;i<5;i++){
  		 lcd_write_char(0x00,3,0x30+i);	
		 delay_ms(100);		
        }
		TCNT2=time_2;
		TCCR2=0x05;
		return;
}
//16λ��ʱ������ʱ��3����жϡ�
#pragma interrupt_handler int_timer3:30
void int_timer3(void){
    TCCR1B=0x00;
     for(i=0;i<5;i++){
  		 lcd_write_char(0x02,3,0x30+i);	
		 delay_ms(100);		
        }
	TCNT3H=time_h_3;
    TCNT3L=time_l_3;
	 TCCR1B=0x05;
}
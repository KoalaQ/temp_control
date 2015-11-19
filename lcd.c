#include<iom128v.h>
#include "lcd.h"
#include "delay.h"
#define rs_l PORTG&=~(1<<PG1)
#define rs_h PORTG|=1<<PG1
#define rw_l PORTG&=~(1<<PG0)
#define rw_h PORTG|=1<<PG0
#define ep1_l PORTG&=~(1<<PG3)
#define ep1_h PORTG|=1<<PG3
#define ep2_l PORTF&=~(1<<PF0)
#define ep2_h PORTF|=1<<PF0
//***********************************
//�ϰ���Ļ
//**********************************
/*
 ��æ��������󣬶���BF
*/
uint lcd_bz_1(void){
	uint result;
	DDRA=0x00;
	rs_l;
	rw_h;
	ep1_h;
	delay_ms(1);
	result=PINA&(1<<PINA7);
	DDRA=0xFF;
	ep1_l;
	return result;
}
void lcd_wcmd_1(uchar cmd){
	 while(lcd_bz_1());
	 rs_l;
	 rw_l;
	 ep1_l;
	 delay_ms(1);
	 PORTA=cmd;
	 delay_ms(2);
	 ep1_h;
	 delay_ms(1);
	 ep1_l;
	 return;
}
/*
д�������,char
*/
void lcd_wdat_1(uchar dat){
	 while(lcd_bz_1());
	 rs_h;
	 rw_l;
	 ep1_l;
	 PORTA=dat;
	 delay_ms(2);
	 ep1_h;
	 delay_ms(2);
	 ep1_l;
}

/*����ʾ*/
void lcd_clear_1(void) 
{
	lcd_wcmd_1(0x01);
	delay_ms(5);
}
//***********************************
//    �°���Ļ
//***********************************
uint lcd_bz_2(void){
	uint result;
	DDRA=0x00;
	rs_l;
	rw_h;
	ep2_h;
	delay_ms(1);
	result=PINA&(1<<PINA7);
	DDRA=0xFF;
	ep2_l;
	return result;
}
void lcd_wcmd_2(uchar cmd){
	 while(lcd_bz_2());
	 rs_l;
	 rw_l;
	 ep2_l;
	 delay_ms(1);
	 PORTA=cmd;
	 delay_ms(2);
	 ep2_h;
	 delay_ms(1);
	 ep2_l;
}
//  д�������,char
void lcd_wdat_2(uchar dat){
	 while(lcd_bz_2());
	 rs_h;
	 rw_l;
	 ep2_l;
	 PORTA=dat;
	 delay_ms(2);
	 ep2_h;
	 delay_ms(2);
	 ep2_l;
}
/*����ʾ*/
void lcd_clear_2(void) 
{
	
	lcd_wcmd_2(0x01);

	delay_ms(5);

}

//*************************************************
//					д�ַ�
//***************************************************
/*
  ����y������ lcd_wdat��������������ʱת��Ϊchar��ֱ������д��ʹ��
*/
void lcd_write_char_con(unsigned char y,unsigned char data) 
{
	
    if (y == 0) 
    {
    	
		 lcd_wdat_1( data);
    }
    else  if(y==1)
    {
    	
		 lcd_wdat_1( data);
    }else  if(y==2)
    {
    	
		 lcd_wdat_2( data);
    }else  if(y==3)
    {
    	
		 lcd_wdat_2( data);
    }
   return; 
}
/*
  ����x,y��д���λ��
*/
void lcd_write_pos(unsigned char x,unsigned char y) 
{
	
    if (y == 0) 
    {
    	lcd_wcmd_1(0x80 + x);
    }
    else  if(y==1)
    {
    	lcd_wcmd_1(0x90 + x);
    }else  if(y==2)
    {
    	lcd_wcmd_2(0x80 + x);
    }else  if(y==3)
    {
    	lcd_wcmd_2(0x90 + x);
    }
   return; 
}
/*
  ����x,y������ lcd_wdat��������������ʱת��Ϊchar
*/
void lcd_write_char(unsigned char x,unsigned char y,unsigned char data) 
{
	
    if (y == 0) 
    {
    	lcd_wcmd_1(0x80 + x);
		 lcd_wdat_1( data);
    }
    else  if(y==1)
    {
    	lcd_wcmd_1(0x90 + x);
		 lcd_wdat_1( data);
    }else  if(y==2)
    {
    	lcd_wcmd_2(0x80 + x);
		 lcd_wdat_2( data);
    }else  if(y==3)
    {
    	lcd_wcmd_2(0x90 + x);
		 lcd_wdat_2( data);
    }
   return; 
}
/*
  ����x,y������ lcd_wdat������������ͨ��ָ������ַ�������̫�ã������Լ�ѭ������
*/
void lcd_write_str(unsigned char x,unsigned char y,unsigned char *s) 
{
	
    if (y == 0) 
    {
    	lcd_wcmd_1(0x80 + x);
		 while (*s) 
       {
    	lcd_wdat_1( *s);
    	s ++;
        }
    }
    else  if(y==1)
    {
    	lcd_wcmd_1(0x90 + x);
		 while (*s) 
        {
    	lcd_wdat_1( *s);
    	s ++;
       }
    }else  if(y==2)
    {
    	lcd_wcmd_2(0x80 + x);
		  while (*s) 
       {
    	lcd_wdat_2( *s);
    	s ++;
       }
    }else  if(y==3)
    {
    	lcd_wcmd_2(0x90 + x);
		  while (*s) 
       {
    	lcd_wdat_2( *s);
    	s ++;
       }
    }
   
}
//****************************
//  ��������,.��֪����û���ã��ȷ�����
//****************************
/**
 ����������󣬶�AC��ַ
*/
uchar read_ac_1(void){
	uint result;
	DDRA=0x00;
	rs_l;
	rw_h;
	ep1_h;
	delay_ms(1);
	result=PINA&(~(1<<PINA7));
	DDRA=0xFF;
	ep1_l;
	return result;
}
uchar read_ac_2(void){
	uint result;
	DDRA=0x00;
	rs_l;
	rw_h;
	ep2_h;
	delay_ms(1);
	result=PINA&(~(1<<PINA7));
	DDRA=0xFF;
	ep2_l;
	return result;
}
/*
 �����ݳ�������󣬶��롣ʹ��read_data���������趨��ֵ���ٳԵ��ñ�������ʹac
 �ƶ�һ�Σ�8��ȡλ������
*/
uchar date_cmd_1(void){
	uint result;
	DDRA=0x00;
	rs_h;
	rw_h;
	ep1_h;
	delay_ms(1);
	result=PINA;
	DDRA=0xFF;
	ep1_l;
	return result;
}
uchar date_cmd_2(void){
	uint result;
	DDRA=0x00;
	rs_h;
	rw_h;
	ep2_h;
	delay_ms(1);
	result=PINA;
	DDRA=0xFF;
	ep2_l;
	return result;
}
//**************************
//��ȡ������ע���acλ��
//**************************
uchar read_data_xy(unsigned char x,unsigned char y){
	if (y == 0) {
    	lcd_wcmd_1(0x80 + x);
		delay_us(10);
		return date_cmd_1();
		
    }else  if(y==1){
    	lcd_wcmd_1(0x90 + x);
		delay_us(10);
		return date_cmd_1();
    }else  if(y==2){
    	lcd_wcmd_2(0x80 + x);
		delay_us(10);
		return date_cmd_2();
    }else  if(y==3){
    	lcd_wcmd_2(0x90 + x);
		delay_us(10);
		return date_cmd_2();
    }
	
	return 0x00;
}
uchar read_data_1(unsigned char addr){
	
    	lcd_wcmd_1(addr);
    	return date_cmd_1();
}
uchar read_data_2(unsigned char addr){
    	lcd_wcmd_1(addr);
		return date_cmd_2();
}


/*��ʼ������*/
void lcd_init(void){
	 //��ʼ���˿ڹ���
	 DDRA |=0xFF;
	 PORTA=0xFF;
	 DDRG |=0x0F;
	 PORTG|=0x0F;
	 DDRF|=0x01;
	 PORTF|=0x01;
	 //lcd_wcmd(0x38);//��ʼ������,8λ������ָ��
	 lcd_wcmd_1(0x30);//��ʼ������,8λ������ָ��
	 delay_us(1);
	  lcd_wcmd_1(0x08);//����ʾ
	 delay_us(1);
	  lcd_wcmd_1(0x01);//����ʾ
	 delay_us(1);
	  lcd_wcmd_1(0x06);//����ģʽ������
	  delay_us(1);
	  lcd_wcmd_1(0x0c);//��ʼ�����,����ʾ
	
	 delay_us(1);
	  lcd_wcmd_2(0x30);//��ʼ������,8λ������ָ��
	 delay_us(1);
	 lcd_wcmd_2(0x08);//����ʾ
	 delay_us(1);
	 lcd_wcmd_2(0x01);//����ʾ
	 delay_us(1);
	 lcd_wcmd_2(0x06);//����ģʽ������
	  delay_us(1);
	 lcd_wcmd_2(0x0c);//��ʼ�����,����ʾ
}
//************
// �����ʾ����,Ĭ�ϳ�ʼ�����ǹرա��ϰ��� 0:�ر�,1�����α�,2���α귴��,3�����αꡢ����
// �°���  4:�ر�,5�����α�,6���α귴��,7�����αꡢ����
//************
void cur_set(uint type){
	 if(type==0){
	 	lcd_wcmd_1(0x0c);	 
	 }else if(type==1){
	     lcd_wcmd_1(0x0e);
	 }else if(type==2){
	    lcd_wcmd_1(0x0d);
	 }else if(type==3){
	    lcd_wcmd_1(0x0f);
	 }else if(type==4){
	    lcd_wcmd_2(0x0c);
	 }else if(type==5){
	    lcd_wcmd_2(0x0e);
	 }else if(type==6){
	    lcd_wcmd_2(0x0d);
	 }else if(type==7){
	    lcd_wcmd_2(0x0f);
	 }
}

//***********************************************************************
//      Һ����ʾ�����ʼ��
//***********************************************************************
void lcd_Desk(void)
{ 
  uint i=0;   
 // lcd_clear();
  //lcd_write_str(0,0,"ADC0:");
  lcd_write_str(0,0,"Hello World!");
   //lcd_write_str(0,1,"�ڶ��в���");
  // lcd_write_str(0,2,"�����Ҳ���");
   //lcd_write_str(0,3,"�����Ҳ���");
  /*for(i=0;i<10;i++){
  		lcd_write_char(0x0b,0,0x30+i);	
		delay_ms(100);		
  }*/
  
}
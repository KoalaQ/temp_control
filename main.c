
#include<iom128v.h>
#include "main.h"
#include "lcd.h"
#include "time.h"
#include "key.h"
#include "delay.h"
#include "timertask.h"
#include "eeprom.h"
unsigned int temp_h=0;
unsigned int temp_l=0;
 unsigned char send_buf[600];
 unsigned char receive_buf[600];
 unsigned int send_len;
 unsigned int receive_len;
//*************************************************************************
//			������
//*************************************************************************
void main(void)
{ 
  uchar data;
  DDRE=0xFF;
  SREG|=0x80;//���ж�
  lcd_init();
  /*Initial_time();
   lcd_Desk(); 
   delay_us(10);
    data=read_data_xy(0,0);
  data=read_data_xy(0,0);
  lcd_write_char(2,2,data);
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
   //Timerinit_1(0x00,0x00);
   Timerinit_3(0x88,0x88);
   //Timerinit_0(0x88);
  // Timerinit_2(0x01);*/
 // EEPROM_write(0x00,0x00,0x02);
  data=EEPROM_read(0x00,0x00);
   lcd_write_char(8,0,0x30|data);
   EEPROM_write(0x00,0x00,data+1);
  PORTE=~data;
  while(1){
   
   
   
   showTimeLcd();
    lcd_write_char(0,2,KeyScan_once());
	/*cur_set(0);
	delay_ms(3000);
	cur_set(1);
	delay_ms(3000);
	cur_set(2);
	delay_ms(3000);
	cur_set(3);
	delay_ms(3000);
	cur_set(4);
	delay_ms(3000);
	cur_set(5);
	delay_ms(3000);
	cur_set(6);
	delay_ms(3000);
	cur_set(7);
	delay_ms(3000);*/
  }
 

 /* SREG|=0x80;
  //ADCSRA=0x8E;  
  DDRE=0xFF;
  PORTE=0xFF;
  lcd_init();                         	//Һ��������ʼ������
  lcd_clear();                        	//����
  lcd_Desk();//adc��ʼ������
  //adc_init();
   // adc_init_once() ;                    	
                          //����ȫ���ж�
 //Timerinit_1(0xFF,0xF0);
 Initial_time();
 Timerinit_3( 0xCC, 0xC5);//16M,0.8s
 //Timerinit_3( 0xE6, 0x62);//8M,0.8s
 
 //��ʼ������
 //KeyInit();*/
 

}
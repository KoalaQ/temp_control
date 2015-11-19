#include<iom128v.h>
#include "max6675.h"
#include "main.h"
#include "delay.h"
#define sck_h_1 PORTE|=(1<<PE3) 
#define sck_l_1 PORTE&=~(1<<PE3) 
#define cs_h_1 PORTE|=1<<PE4 
#define cs_l_1 PORTE&=~(1<<PE4) 

#define sck_h_2 PORTE|=(1<<PE6) 
#define sck_l_2 PORTE&=~(1<<PE6) 
#define cs_h_2 PORTE|=1<<PE7 
#define cs_l_2 PORTE&=~(1<<PE7) 

#define sck_h_3 PORTF|=(1<<PF0) 
#define sck_l_3 PORTF&=~(1<<PF0) 
#define cs_h_3 PORTF|=1<<PF2 
#define cs_l_3 PORTF&=~(1<<PF2) 

#define sck_h_4 PORTF|=(1<<PF4) 
#define sck_l_4 PORTF&=~(1<<PF4) 
#define cs_h_4 PORTF|=1<<PF5 
#define cs_l_4 PORTF&=~(1<<PF5) 
/*
仿真中没有读出数据，也没有实物

*/
void readTemp_1(void){
	   uint i;
	   DDRE&=0xFB;
	   sck_l_1;
	   cs_l_1;
	   delay_us(1);
	   for(i=0;i<8;i++){
			sck_h_1;
			delay_us(10);
	    	temp_h=temp_h|(PINE&0x04);
			temp_h<<=1;
			sck_l_1;
			delay_us(1);
			
	   }
	   for(i=0;i<8;i++){
			sck_h_1;
			delay_us(10);
	    	temp_l=temp_l|(PINE&0x04);
			temp_l<<=temp_l;
			sck_l_1;
			delay_us(1);
	   }
	   delay_us(1);
	  // temp_l=0x55;
	   return ;
}
void readTemp_2(void){
	   uint i;
	   DDRE&=0xDF;
	   sck_l_2;
	   cs_l_2;
	   delay_us(1);
	   for(i=0;i<8;i++){
			sck_h_2;
			delay_us(10);
	    	temp_h=temp_h|(PINE&0x20);
			temp_h<<=1;
			sck_l_2;
			delay_us(1);
			
	   }
	   for(i=0;i<8;i++){
			sck_h_2;
			delay_us(10);
	    	temp_l=temp_l|(PINE&0x20);
			temp_l<<=temp_l;
			sck_l_2;
			delay_us(1);
	   }
	   delay_us(1);
	  // temp_l=0x55;
	   return ;
}
void readTemp_3(void){
	   uint i;
	   DDRF&=0xFE;
	   sck_l_3;
	   cs_l_3;
	   delay_us(1);
	   for(i=0;i<8;i++){
			sck_h_3;
			delay_us(10);
	    	temp_h=temp_h|(PINF&0x01);
			temp_h<<=1;
			sck_l_3;
			delay_us(1);
			
	   }
	   for(i=0;i<8;i++){
			sck_h_3;
			delay_us(10);
	    	temp_l=temp_l|(PINF&0x01);
			temp_l<<=temp_l;
			sck_l_3;
			delay_us(1);
	   }
	   delay_us(1);
	  // temp_l=0x55;
	   return ;
}
void readTemp_4(void){
	   uint i;
	   DDRF&=0xF7;
	   sck_l_4;
	   cs_l_4;
	   delay_us(1);
	   for(i=0;i<8;i++){
			sck_h_4;
			delay_us(10);
	    	temp_h=temp_h|(PINF&0x80);
			temp_h<<=1;
			sck_l_4;
			delay_us(1);
			
	   }
	   for(i=0;i<8;i++){
			sck_h_4;
			delay_us(10);
	    	temp_l=temp_l|(PINF&0x80);
			temp_l<<=temp_l;
			sck_l_4;
			delay_us(1);
	   }
	   delay_us(1);
	  // temp_l=0x55;
	   return ;
}
uchar readOC(void){
	  DDRD&=0x07;
	  return PIND&(0xF8);
}

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

#define sck_h_3 PORTF|=(1<<PF1) 
#define sck_l_3 PORTF&=~(1<<PF1) 
#define cs_h_3 PORTF|=1<<PF2 
#define cs_l_3 PORTF&=~(1<<PF2) 

#define sck_h_4 PORTF|=(1<<PF4) 
#define sck_l_4 PORTF&=~(1<<PF4) 
#define cs_h_4 PORTF|=1<<PF5 
#define cs_l_4 PORTF&=~(1<<PF5) 
void readTemp_1(void){
	   uint i;
	   sck_h_1;
	   cs_h_1;
	   delay_us(1);
	   cs_l_1;
	   delay_us(1);
	   sck_l_1;
	   delay_us(1);
	   sck_h_1;
	  for(i=0;i<8;i++){
			sck_l_1;
			delay_us(1);
			temp_h=temp_h<<1;
	    	temp_h=temp_h|((PINE&0x04)>>2);
			sck_h_1;
			delay_us(1);
			
	   }
	   for(i=0;i<8;i++){
			sck_l_1;
			delay_us(1);
			temp_l<<=1;
	    	temp_l=temp_l|((PINE&0x04)>>2);
			sck_h_1;
			delay_us(1);
	   }
	    cs_h_1;
	   delay_us(10);
	  // temp_l=0x55;
	   return ;
}
void readTemp_2(void){
	   uint i;
	   sck_h_2;
	   cs_h_2;
	   delay_us(1);
	   cs_l_2;
	   delay_us(1);
	   sck_l_2;
	   delay_us(1);
	   sck_h_2;
	  for(i=0;i<8;i++){
			sck_l_2;
			delay_us(1);
			temp_h=temp_h<<1;
	    	temp_h=temp_h|((PINE&0x20)>>5);
			sck_h_2;
			delay_us(1);
			
	   }
	   for(i=0;i<8;i++){
			sck_l_2;
			delay_us(1);
			temp_l<<=1;
	    	temp_l=temp_l|((PINE&0x20)>>5);
			sck_h_2;
			delay_us(1);
	   }
	    cs_h_2;
	   delay_us(10);
	  // temp_l=0x55;
	   return ;
}
void readTemp_3(void){
	   uint i;
	   sck_h_3;
	   cs_h_3;
	   delay_us(1);
	   cs_l_3;
	   delay_us(1);
	   sck_l_3;
	   delay_us(1);
	   sck_h_3;
	  for(i=0;i<8;i++){
			sck_l_3;
			delay_us(1);
			temp_h=temp_h<<1;
	    	temp_h=temp_h|(PINF&0x01);
			sck_h_3;
			delay_us(1);
			
	   }
	   for(i=0;i<8;i++){
			sck_l_3;
			delay_us(1);
			temp_l<<=1;
	    	temp_l=temp_l|(PINF&0x01);
			sck_h_3;
			delay_us(1);
	   }
	    cs_h_3;
	   delay_us(10);
	  // temp_l=0x55;
	   return ;
}
void readTemp_4(void){
	  uint i;
	   sck_h_4;
	   cs_h_4;
	   delay_us(1);
	   cs_l_4;
	   delay_us(1);
	   sck_l_4;
	   delay_us(1);
	   sck_h_4;
	  for(i=0;i<8;i++){
			sck_l_4;
			delay_us(1);
			temp_h=temp_h<<1;
	    	temp_h=temp_h|((PINE&0x08)>>3);
			sck_h_4;
			delay_us(1);
			
	   }
	   for(i=0;i<8;i++){
			sck_l_4;
			delay_us(1);
			temp_l<<=1;
	    	temp_l=temp_l|((PINE&0x08)>>3);
			sck_h_4;
			delay_us(1);
	   }
	    cs_h_4;
	   delay_us(10);
	  // temp_l=0x55;
	   return ;
}
//传入的int：0、1、2、3对应温度的读取
void readTemp(uint n){
   switch(n){
    case 0:
	  readTemp_1();
	  break;
	case 1:
	  readTemp_2();
	  break;
	case 2:
	  readTemp_3();
	  break;
	case 3:
	  readTemp_4();
	  break;
   }
}

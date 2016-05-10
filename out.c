#include<iom128v.h>
#include "out.h"
#include "lcd.h"
#include "main.h"
//*********************
// 1����50���ڣ����ƹ�����50���������
//*********************
uint hz=1;//1~50��ʾ����

//0��1�Ĵ��롣port��0~7
void out_port(void){
   if(hz==51){
     hz=1;
   }
   if(temps[0].flag==1){
	  if(temps[0].incrementtemp>=hz){
	    PORTC |=0x01;
	  }else {
	    PORTC &=0xFE;
	  }
   }else{
      PORTC &=0xFE;
   }
    if(temps[1].flag==1){
	  if(temps[0].incrementtemp>=hz){
	      PORTC |=0x02;
	    }else {
	      PORTC &=0xFD;
	    }
   }else{
      PORTC &=0xFD;
   }
    if(temps[2].flag==1){
	  if(temps[0].incrementtemp>=hz){
	      PORTC |=0x04;
	    }else {
	      PORTC &=0xFB;
	    }
   }else{
      PORTC &=0xFB;
   }
    if(temps[3].flag==1){
	  if(temps[0].incrementtemp>=hz){
	      PORTC |=0x08;
	    }else {
	      PORTC &=0xF7;
	    }
   }else{
     PORTC &=0xF7;
   }
    hz++;
}
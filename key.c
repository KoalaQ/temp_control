#include<iom128v.h>
#include "delay.h"
void KeyInit(void){
   

}
uchar KeyScan(void){
  //��ʼ���˿�
   DDRC=0xE0;
   DDRG|=0x10;
   
   //��һ��ɨ��
   PORTC=0xDF;
   PORTG|=0x10;
   delay_us(1);
   switch(PINC)
   {
   		case 0xDE:return  'e';//'esc';
		case 0xdd:return  'a';//'alm';
		case 0xdb:return  'd';//'down';  
		case 0xd7:return  'u';//'up';
		case 0xcf:return  'l';//'left';
		default:break;	   
   } 
    //�ڶ���ɨ��
   PORTC=0xBF;
   PORTG|=0x10;
   delay_us(1);
   switch(PINC)
   {
   		case 0xbE:return 's';//'set';
		case 0xbd:return 'r';//'right';
		case 0xbb:return 't';//'ent';  
		case 0xb7:return 'c';//'clr';
		case 0xaf:return '+';//'+/-';
		default:break;	   
   } 
    //������ɨ��
   PORTC=0x7F;
   PORTG|=0x10;
   delay_us(1);
   switch(PINC)
   {
   		case 0x7E:return '0';
		case 0x7d:return '3';
		case 0x7b:return '2';  
		case 0x77:return '1';
		case 0x6f:return '6';
		default:break;	   
   } 
      //���Ĵ�ɨ��
   PORTC=0xFF;
   PORTG&=0x0F;
   delay_us(1);
   switch(PINC)
   {
   		case 0xFE:return '7';
		case 0xFd:return '8';
		case 0xFb:return '9';  
		case 0xF7:return '4';
		case 0xEf:return '5';
		default:break;	   
   }
 return 'n';
   
}
//********************************
//		������ʱ�����Ķ�ȡ��һ�ζ�ȡһ��
//********************************
uchar KeyScan_once(void){
	  uchar keyValue,keyValue2;
	  keyValue=KeyScan();
	  delay_ms(2);
	  keyValue2=KeyScan();
	if(keyValue==keyValue2){
	 return keyValue;
	}
	return 'n';
}
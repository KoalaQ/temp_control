#include<iom128v.h>
#include "eeprom.h"
#include "delay.h"
void EEPROM_write(uint addr_h,uint addr_l,uint data){
   SREG&=0x7F;//关中断
    while(EECR & (1<<EEWE)){
	 			 
	 }
	 EEARL=addr_l;
	 EEARH=addr_h;
	 
	 EEDR=data;
	 EECR|=(1<<EEMWE);
	 EECR|=(1<<EEWE);
	  delay_us(1);
	 SREG|=0x80;//开中断
	 return;
}
uchar EEPROM_read(uint addr_h,uint addr_l){
   uchar data;
   SREG&=0x7F;//关中断
    while(EECR & (1<<EEWE)){ 			 
	 }
	 EEARL=addr_l;
	 EEARH=addr_h;
	 
	 EECR|=(1<<EERE);
	 delay_us(1);
	 data=EEDR;
	 SREG|=0x80;//开中断
	 return data;
}
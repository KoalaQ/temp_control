#include<iom128v.h>
#include "eeprom.h"
#include "delay.h"

//使用全非中断方式读写。温控数据在保存时候一次性写入。状态数据执行时写入，写入量小不会影响速度
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
uint EEPROM_read(uint addr_h,uint addr_l){
   uint data;
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
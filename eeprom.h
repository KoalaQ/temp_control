#ifndef __EEPROM_H__
#define __EEPROM_H__
#define uchar unsigned char
#define uint unsigned int
void EEPROM_write(uint addr_h,uint addr_l,uint data);
uchar EEPROM_read(uint addr_h,uint addr_l);


#endif
#include<iom128v.h>
#include "out.h"

void out_all(uchar out){
  DDRC=0xFF;
  PORTC=out;
}
//0、1的传入。port由0~7
void out_port(uint out,uint port){
  DDRC=0xFF;
  if(out==0){
   PORTC&=~(1<<port);
  }else if(out==1){
   PORTC|=(1<<port);
  }
}
uint read_port(uint port){
  return PINC&(1<<port);
}
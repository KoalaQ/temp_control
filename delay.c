#include<iom128v.h>
#include "delay.h"


void delay_us(uint n)//ÑÓÊ±us
{
  n=2*n;
  do{ n--;
  }while(n>1);
}
void delay_ms(uint j)//ÑÓÊ±ms
{
   do{j--;
     delay_us(1141);
   }while(j>1);
}
void delay_s(uint i)
{
   do{
   i--;
   delay_ms(1000);
   }while(i>1);
}
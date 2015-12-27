#include <iom128v.h>
#include "uart.h"
#include "main.h"
#define fosc  800000  //晶振8MHZ
#define baud 9600  //波特率


void uart0_init(void)
{
UCSR0B = 0x00; //关闭UART00
UCSR0A = 0x00; //不使用倍速发送（异步）
UCSR0C =(1<<UCSZ01)|(1<<UCSZ00); //数据位为8位
//UBRR0L=(fosc/16/(baud+1))%6; //异步正常情况下的计算公式
//UBRR0H=(fosc/16/(baud+1))/256;
UBRR0L=103; //异步正常情况下的计算公式.9600
UBRR0H=0x00;
UCSR0B |=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0); //接收使能和发送使能.接收终端打开

}

void putchar0(unsigned char c)
{
while (!(UCSR0A&(1<<UDRE0)));//表明发送器已经准备就绪
UDR0=c; //将要发送的数据装入UDR0寄存器
}


unsigned char getchar0(void)
{
  while(!(UCSR0A& (1<<RXC0)));//表明已经接收完毕
  return UDR0;
}
//读取中断
#pragma interrupt_handler int_ruart0:19
void int_ruart0(void){
   uchar data;
   data=UDR0;
   
}
//发送中断
#pragma interrupt_handler int_suart0:20
void int_suart0(void){
   UCSR0B &=~(1<<UDRIE0); //关中断
   PORTE=~PORTE;
   if(send_data_cur<send_data_length){//还有数据存在，继续发送
      UDR0=send_data_cache[send_data_cur];
	  send_data_cur++;
	  UCSR0B |=(1<<UDRIE0); //开中断
   }else{//没有数据啦，清空游标。关中断
    send_data_length=0;
    send_data_cur=0;
   } 
  
}

void puts0(char *s)
{
  while (*s)
  {
    putchar0(*s);
    s++;
  }
  putchar0(0x0a);//回车换行
//putchar0(0x0d);
}



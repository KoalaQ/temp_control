
#ifndef __TIME1307_H__
#define __TIME1307_H__
#define uchar unsigned char
#define uint unsigned int
//void Write1307( unsigned char addr,unsigned char dat );
//unsigned char Read1307( unsigned char addr );
void Initial_time(void) ;
//void showTimeLcd(void);
void showTime_page(uint y);//����page��һ����ʾ����
void setTime(uint year,uint month,uint day,uint hour,uint minute,uint second);
unsigned int Read1307(unsigned char add);
#endif

#ifndef __KEY_H__
#define __KEY_H__
#define uchar unsigned char
#define uint unsigned int
#define rs_l PORTA&=~(1<<PA5)
#define rs_h PORTA|=1<<PA5
#define rw_l PORTA&=~(1<<PA4)
#define rw_h PORTA|=1<<PA4
#define ep_l PORTA&=~(1<<PA3)
#define ep_h PORTA|=1<<PA3
uchar KeyScan_once(void);//加上延时抖动的读取。长按会读取一次然后不在读取
#endif
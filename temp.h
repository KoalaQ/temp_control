#ifndef __TEMP_H__
#define __TEMP_H__
#define uchar unsigned char
#define uint unsigned int
void tempdata_init(void);
void set_temp_data(uint t,uint* dataCach);
void reset_temp_data(uint t);
void set_all_start(void);
void set_all_stop(void);
void set_start(uint t);
void set_stop(uint t);
void data_recover(void);
void int_int2(void);
void tempcontrol(void);
void send_temp_data(uint t);//发送温度数据到串口
#endif
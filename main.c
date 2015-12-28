#include<iom128v.h>
#include "main.h"
#include "lcd.h"
#include "time1307.h"
#include "key.h"
#include "delay.h"
#include "timertask.h"
#include "eeprom.h"
#include "pages.h"
#include "temp.h"
#include "uart.h"
//串口接收数据需要
unsigned int read_data_cache[132]={0};
unsigned int read_data_cur=0;
unsigned char read_data_cmd='z';//字母表示。如果是z表示空指令
//串口发送数据需要
unsigned int send_data_cache[135]={0x30};
unsigned int send_data_length=0;//数据长度
unsigned int send_data_cur=0;//当前发送到游标
//定时器0复用参数。t0_fla0=0，开机等待；t0_fla0=1，温度计时
unsigned int t0_flag =0;
//const unsigned char nihao[1536]={};
//确认恢复的等待标记，初始为1000，如果为0代表到时.在使用其当作温度计数的时候需要值为32
unsigned int waitflag=1000;
//下面两个继续使用。暂时保存数据使用
 unsigned int temp_h=0;
 unsigned int temp_l=0;
 //界面需要参数
 unsigned int pageNum;//当前页面，如需跳转改变这个值就行
 unsigned int pageParam[5];//传递参数。界面间参数暂存
 unsigned int prePageNum; //上一界面。应该在跳转前设置这个参数。但是用到这个参数的就Page3、4、8.所以可以直接在该界面用到在设置。不用理会规则
 //**************
struct temp temps[4]={{0},{0},{0},{0}};


//*************************************************************************
//			主程序
//*************************************************************************
void main(void)
{ 
  send_data_cache[0]=0x30;
  send_data_cache[1]=0x31;
  send_data_cache[2]=0x32;
  send_data_cache[3]=0x33;
  send_data_cache[4]=0x34;
  send_data_cache[5]=0x35;
  send_data_cache[6]=0x36;
  send_data_cache[7]=0x37;
  send_data_cache[8]=0x38;
  send_data_cache[9]=0x39;
  DDRE=0xFF;
  PORTE=~0xaa;
  SREG|=0x80;//开中断
  lcd_init();
  lcd_clear();
   //画欢迎界面
  //Draw_Pic( 0, 0, nihao);
   //delay_ms(1000);
     pageNum=2;
     Set_White_off(1,0,12);
	 Set_White_off(1,1,12);
	 Set_White_off(1,2,12);
	 Set_White_off(1,3,12);
	 //测试使用
	   temp_l=0x50;
      temp_h=0x12;
	  tempdata_init();//数据初始化，清空
      Initial_time(); //初始化时间的
	  Timerinit_3(0xc0,0x00);//使用16位的定时器3。发送串口数据，刚开始为初始化的时候可能数据都为空
	  Timerinit_1(0xFe,0xb8);//使用16位的定时器1来输出
	  Timerinit_2(0x00);//1s计时模块
	  uart0_init( );//初始化串口
	 while(1){
     dispatchPages();
  }
  /*Initial_time();
   lcd_Desk(); 
   delay_us(10);
    data=read_data_xy(0,0);
  data=read_data_xy(0,0);
  lcd_write_char(2,2,data);
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
  lcd_write_char_con(2,date_cmd_1());
   //Timerinit_1(0x00,0x00);
   Timerinit_3(0x88,0x88);
   //Timerinit_0(0x88);
  // Timerinit_2(0x01);*/
 // EEPROM_write(0x00,0x00,0x02);
 // data=EEPROM_read(0x00,0x00);
  // lcd_write_char(8,0,0x30|data);
  // EEPROM_write(0x00,0x00,data+1);
  //PORTE=~data;
  // lcd_Desk(); 
 /*
  while(1){
   
   
   
   showTimeLcd();
    lcd_write_char(0,2,KeyScan_once());
	cur_set(0);
	delay_ms(3000);
	cur_set(1);
	delay_ms(3000);
	cur_set(2);
	delay_ms(3000);
	cur_set(3);
	delay_ms(3000);
	cur_set(4);
	delay_ms(3000);
	cur_set(5);
	delay_ms(3000);
	cur_set(6);
	delay_ms(3000);
	cur_set(7);
	delay_ms(3000);
  }*/
 

 /* SREG|=0x80;
  //ADCSRA=0x8E;  
  DDRE=0xFF;
  PORTE=0xFF;
  lcd_init();                         	//液晶参数初始化设置
  lcd_clear();                        	//清屏
  lcd_Desk();//adc初始化配置
  //adc_init();
   // adc_init_once() ;                    	
                          //开启全局中断
 //Timerinit_1(0xFF,0xF0);
 Initial_time();
 Timerinit_3( 0xCC, 0xC5);//16M,0.8s
 //Timerinit_3( 0xE6, 0x62);//8M,0.8s
 
 //初始化按键
 //KeyInit();*/
 

}

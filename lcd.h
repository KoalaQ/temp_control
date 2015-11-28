
#ifndef __LCD_H__
#define __LCD_H__
#define uchar unsigned char
#define uint unsigned int
void lcd_write_pos(unsigned char x,unsigned char y);
void lcd_write_str(unsigned char x,unsigned char y,unsigned char *s) ;
void lcd_write_char(unsigned char x,unsigned char y,unsigned char data) ;
void lcd_write_char_con(unsigned char y,unsigned char data);
void lcd_write_str_con(unsigned char y,unsigned char *s) ;
uchar read_data_1(unsigned char addr);
uchar read_data_2(unsigned char addr);
uchar read_data_xy(unsigned char x,unsigned char y);
uchar read_ac_1(void);
uchar read_ac_2(void);
uchar date_cmd_1(void);//读取ram的，自动改变.。写入AC(或者获取当前)，然后用此命名获取值
uchar date_cmd_2(void);
void lcd_clear(void) ;
void lcd_init(void);
void lcd_Desk(void);
//************
// 光标显示操作,默认初始化都是关闭。上半屏 0:关闭,1：开游标,2：游标反白,3：开游标、反白
// 下半屏  4:关闭,5：开游标,6：游标反白,7：开游标、反白
//************
void cur_set(uint type);
 void Set_Draw(void)  ;
 void Set_UNDraw(void) ; 
  void Set_White(uchar x,uchar y,uchar end_x)   ;
   void Set_White_off(uchar x,uchar y,uchar end_x)   ;
#endif
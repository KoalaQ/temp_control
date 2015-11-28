
#ifndef __LCD_H__
#define __LCD_H__
#define uchar unsigned char
#define uint unsigned int
void lcd_write_str(unsigned char x,unsigned char y,unsigned char *s) ;
void lcd_write_char(unsigned char x,unsigned char y,unsigned char data) ;
void lcd_write_char_con(unsigned char y,unsigned char data);
uchar read_data_1(unsigned char addr);
uchar read_data_2(unsigned char addr);
uchar read_data_xy(unsigned char x,unsigned char y);
uchar read_ac_1(void);
uchar read_ac_2(void);
uchar date_cmd_1(void);//读取ram的，自动改变
uchar date_cmd_2(void);
void lcd_clear(void) ;
void lcd_init(void);
void lcd_Desk(void);
void cur_set(uint type);
void lcd_write_pos(unsigned char x,unsigned char y);
 void Set_Draw(void)  ;
 void Set_UNDraw(void) ; 
  void Set_White(uchar x,uchar y,uchar end_x)   ;
   void Set_White_off(uchar x,uchar y,uchar end_x)   ;
#endif
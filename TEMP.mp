NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   097F =   2431. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       0A0B  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0A0C   6A58 =  27224. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0506  __text_start
       0506  __start
       0528  _exit
       0529  _delay_us
       0533  _delay_ms
       0543  _delay_s
       0553  _KeyScan
       0620  _KeyScan_once
       063F  _lcd_bz_1
       0665  _lcd_wcmd_1
       068B  _lcd_wdat_1
       06B1  _lcd_clear_1
       06B7  _lcd_bz_2
       06DD  _lcd_wcmd_2
       0703  _lcd_wdat_2
       0729  _lcd_clear_2
       072B  _lcd_write_char_con
       073F  _lcd_write_pos
       075D  _lcd_write_char
       0783  _lcd_write_str
       07CD  _lcd_write_str_con
       07F0  _read_ac_1
       0815  _read_ac_2
       083A  _lcd_clear
       083C  _date_cmd_1
       0860  _date_cmd_2
       0884  _read_data_xy
       08B9  _read_data_1
       08C0  _read_data_2
       08C7  _lcd_init
       08F4  _cur_set
       0930  _Set_Draw
       0934  _Set_UNDraw
       0938  _Set_White_off
       09A8  _Set_White
       0A18  _Draw_Pic
       0A69  _lcd_Desk
       0A9B  _main
       0AE7  _Timerinit_1
       0AF6  _Timerinit_3
       0B0C  _Timerinit_0
       0B15  _Timerinit_2
       0B1E  _int_timer0
       0B99  _int_timer1
       0BD2  _int_timer2
       0C1F  _int_timer3
       0D8F  _readTemp_1
       0E00  _readTemp_2
       0E79  _readTemp_3
       0F0A  _readTemp_4
       0FB1  _readTemp
       0FCE  _out_port
       1056  _uart0_init
       1064  _putchar0
       1068  _getchar0
       106C  _int_ruart0
       1101  _int_suart0
       1140  _puts0
       1152  _cmd_oper
       1179  _read_cmd
       11F8  _EEPROM_write
       120F  _EEPROM_read
       1225  _pageTime
       1238  _pageTime2
       1241  _page1
       1618  _page2
       1761  _page3
       1B40  _page4_data
       1CE4  _page4_ac
       1DBE  _page4
       2087  _page5
       21AC  _page6
       21ED  _page7
       228D  _page8
       2627  _page9
       2662  _dispatchPages
       26C2  _int_int2
       2FA9  _tempcontrol
       3102  _tempdata_init
       3252  _data_recover
       3386  _set_temp_data
       33EF  _send_temp_data
       3471  _reset_temp_data
       35A6  _set_all_start
       35F2  _set_all_stop
       3623  _set_start
       3685  _set_stop
       36AE  _PID_realize
       376E  _PI_realize
       3808  _I2C_start
       3815  _I2C_stop
       3822  _I2C_send_ack
       382A  _I2C_send_noack
       3832  _I2C_write_byte
       3864  _I2C_read_byte
       387C  _Write1307
       388B  _Read1307
       389F  _setTime
       38C3  _Initial_time
       38D4  _showTime_page
       395A  push_arg4
       395C  push_arg2
       395F  asr16
       3966  mod16s
       396A  div16s
       3984  mod16u
       3986  div16u
       3987  xdiv16u
       39A0  empy16s
       39B0  pop_xgset003C
       39B5  pop_xgset00FC
       39BC  pop_xgsetF0FC
       39C7  push_xgsetF0FC
       39C9  push_xgset30FC
       39CB  push_xgset00FC
       39CD  push_xgset003C
       39D2  push_xgset300C
       39D7  pop_xgset300C
       39DC  push_xgsetF000
       39E1  pop_xgsetF000
       39E6  push_xgsetF00C
       39ED  pop_xgsetF00C
       39F4  push_xgset303C
       39FB  pop_xgset303C
       3A02  push_xgsetF03C
       3A0B  pop_xgsetF03C
       3A14  lsl8
       3A1A  asgnblk
       3A32  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   097F =   2431. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  _key_value
       0100  __data_start
       0110  _read_data_cache
       0218  _read_data_cur
       021A  _read_data_cmd
       021B  _send_data_cache
       0331  _send_data_length
       0333  _send_data_cur
       0335  _t0_flag
       0337  _waitflag
       0339  _temp_h
       033B  _temp_l
       033D  _temps
       0805  _secondflag
       0807  _hz
       0A7F  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0A7F   0018 =     24. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0A7F  _prePageNum
       0A7F  __bss_start
       0A81  _pageParam
       0A8B  _pageNum
       0A8D  _i
       0A8E  _time_2
       0A8F  _time_0
       0A90  _time_l_3
       0A91  _time_h_3
       0A92  _time_l_1
       0A93  _time_h_1
       0A94  _second
       0A96  _BP
       0A97  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0078 =    120. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
delay.o	[ delay.c ]
key.o	[ key.c ]
lcd.o	[ lcd.c ]
main.o	[ main.c ]
timertask.o	[ timertask.c ]
max6675.o	[ max6675.c ]
out.o	[ out.c ]
uart.o	[ uart.c ]
eeprom.o	[ eeprom.c ]
pages.o	[ pages.c ]
temp.o	[ temp.c ]
time1307.o	[ time1307.c ]
<library>	[ asave.s, asr16.s, div16s.s, div16u.s, emul16s.s, gpop2.s, gpop3.s, gpop5.s, gpush.s, gpushx.s, gpushy.s ]
[ gpushz.s, gpusha.s, gpushb.s, lsl8.s, struct.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096


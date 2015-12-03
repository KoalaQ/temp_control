NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   0697 =   1687. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       0723  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0724   3D32 =  15666. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0392  __start
       0392  __text_start
       03B4  _exit
       03B5  _delay_us
       03BF  _delay_ms
       03CF  _delay_s
       03DF  _Write1302
       0406  _Read1302
       0438  _Initial_time
       044C  _showTimeLcd
       04E5  _getYear
       04E8  _getMonth
       04EB  _getDay
       04EE  _getWeek
       04F1  _getHour
       04F4  _getMinute
       04F7  _getSecond
       04FA  _setTime
       04FB  _showTime_page
       058D  _KeyInit
       058E  _KeyScan
       065B  _KeyScan_once
       067A  _lcd_bz_1
       06A0  _lcd_wcmd_1
       06C6  _lcd_wdat_1
       06EC  _lcd_clear_1
       06F2  _lcd_bz_2
       0718  _lcd_wcmd_2
       073E  _lcd_wdat_2
       0764  _lcd_clear_2
       0766  _lcd_write_char_con
       077A  _lcd_write_pos
       0798  _lcd_write_char
       07BE  _lcd_write_str
       0808  _lcd_write_str_con
       082B  _read_ac_1
       0850  _read_ac_2
       0875  _lcd_clear
       0877  _date_cmd_1
       089B  _date_cmd_2
       08BF  _read_data_xy
       08F4  _read_data_1
       08FB  _read_data_2
       0902  _lcd_init
       092F  _cur_set
       096B  _Set_Draw
       096F  _Set_UNDraw
       0973  _Set_White_off
       09E3  _Set_White
       0A53  _Draw_Pic
       0AA4  _lcd_Desk
       0AD6  _main
       0B04  _Timerinit_1
       0B13  _Timerinit_3
       0B29  _Timerinit_0
       0B32  _Timerinit_2
       0B3B  _int_timer0
       0B89  _int_timer1
       0BDA  _int_timer2
       0C2B  _int_timer3
       0C7E  _readTemp_1
       0CE0  _readTemp_2
       0D42  _readTemp_3
       0DBE  _readTemp_4
       0E3A  _readOC
       0E40  _out_all
       0E44  _out_port
       0E6B  _read_port
       0E7B  _init_USART1
       0E87  _put_c1
       0E8B  _USART_Receive1
       0EA0  _receiveStrfromCom
       0EE5  _outStrtoCom
       0EF9  _MAC_CalCrc16
       0F25  _MAC_CheckCrc16
       0F4A  _ComSendResponse
       0F83  _EEPROM_write
       0F9A  _EEPROM_read
       0FB0  _pageTime
       0FC3  _pageTime2
       0FCC  _page1
       1346  _page2
       13D1  _page3
       1593  _page4_data
       1737  _page4_ac
       1811  _page4
       1AD9  _page5
       1BBA  _page6
       1BFB  _page7
       1C9B  _page8
       1EBE  _page9
       1EF4  _dispatchPages
       1F53  _tempdata_init
       1F8A  _data_recover
       1FDC  _set_temp_data
       2039  _reset_temp_data
       2088  _set_all_start
       20C4  _set_all_stop
       2100  _set_start
       2134  _set_stop
       2168  push_arg4
       216A  push_arg2
       216D  mod16u
       216F  div16u
       2170  xdiv16u
       2189  empy16s
       2199  pop_xgset003C
       219E  pop_xgset00FC
       21A5  pop_xgset30FC
       21AE  pop_xgsetF0FC
       21B9  push_xgsetF0FC
       21BB  push_xgset30FC
       21BD  push_xgset00FC
       21BF  push_xgset003C
       21C4  push_xgset300C
       21C9  pop_xgset300C
       21CE  push_xgsetF000
       21D3  pop_xgsetF000
       21D8  push_xgsetF00C
       21DF  pop_xgsetF00C
       21E6  push_xgset303C
       21ED  pop_xgset303C
       21F4  push_xgsetF03C
       21FD  pop_xgsetF03C
       2206  lsl16
       220D  lsl8
       2213  asgnblk
       222B  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0697 =   1687. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       0103  _key_value
       0113  _temp_h
       0115  _temp_l
       0117  _temps
       0797  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0797   04CB =   1227. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0797  _receive_len
       0797  __bss_start
       0799  _send_len
       079B  _receive_buf
       09F3  _send_buf
       0C4B  _prePageNum
       0C4D  _pageParam
       0C57  _pageNum
       0C59  _i
       0C5A  _time_2
       0C5B  _time_0
       0C5C  _time_l_3
       0C5D  _time_h_3
       0C5E  _time_l_1
       0C5F  _time_h_1
       0C60  _uart_timeout_flag2
       0C61  _uart_timeout_flag1
       0C62  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0078 =    120. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
delay.o	[ delay.c ]
time.o	[ time.c ]
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
<library>	[ asave.s, div16u.s, emul16s.s, gpop2.s, gpop3.s, gpop4.s, gpop5.s, gpush.s, gpushx.s, gpushy.s, gpushz.s ]
[ gpusha.s, gpushb.s, lsl16.s, lsl8.s, struct.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096


NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   07B4 =   1972. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       0840  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0840   34AE =  13486. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0420  __start
       0420  __text_start
       0442  _exit
       0443  _delay_us
       044D  _delay_ms
       045D  _delay_s
       046D  _Write1302
       0494  _Read1302
       04C6  _Initial_time
       04DA  _showTimeLcd
       0573  _getYear
       0576  _getMonth
       0579  _getDay
       057C  _getWeek
       057F  _getHour
       0582  _getMinute
       0585  _getSecond
       0588  _setTime
       0589  _showTime_page
       061B  _KeyInit
       061C  _KeyScan
       06E9  _KeyScan_once
       0708  _lcd_bz_1
       072E  _lcd_wcmd_1
       0754  _lcd_wdat_1
       077A  _lcd_clear_1
       0780  _lcd_bz_2
       07A6  _lcd_wcmd_2
       07CC  _lcd_wdat_2
       07F2  _lcd_clear_2
       07F4  _lcd_write_char_con
       0808  _lcd_write_pos
       0826  _lcd_write_char
       084C  _lcd_write_str
       0896  _lcd_write_str_con
       08B9  _read_ac_1
       08DE  _read_ac_2
       0903  _lcd_clear
       0905  _date_cmd_1
       0929  _date_cmd_2
       094D  _read_data_xy
       0982  _read_data_1
       0989  _read_data_2
       0990  _lcd_init
       09BD  _cur_set
       09F9  _Set_Draw
       09FD  _Set_UNDraw
       0A01  _Set_White_off
       0A71  _Set_White
       0AE1  _Draw_Pic
       0B32  _lcd_Desk
       0B64  _main
       0BB2  _Timerinit_1
       0BC1  _Timerinit_3
       0BD7  _Timerinit_0
       0BE0  _Timerinit_2
       0BE9  _int_timer0
       0C37  _int_timer1
       0C88  _int_timer2
       0CD9  _int_timer3
       0D2C  _readTemp_1
       0D8E  _readTemp_2
       0DF0  _readTemp_3
       0E6C  _readTemp_4
       0EE8  _readOC
       0EEE  _out_all
       0EF2  _out_port
       0F19  _read_port
       0F29  _init_USART1
       0F35  _put_c1
       0F39  _USART_Receive1
       0F4E  _receiveStrfromCom
       0F93  _outStrtoCom
       0FA7  _MAC_CalCrc16
       0FD3  _MAC_CheckCrc16
       0FF8  _ComSendResponse
       1031  _EEPROM_write
       1048  _EEPROM_read
       105E  _pageTime
       1071  _pageTime2
       107A  _page1
       13EB  _page2
       1462  _page3
       15BC  _page4_data
       1676  _page4_ac
       1750  _page4
       1954  _page5
       1A2A  _page6
       1A6B  _page7
       1B07  _page8
       1D2A  _page9
       1D5A  _dispatchPages
       1DB9  push_arg4
       1DBB  push_arg2
       1DBE  mod16u
       1DC0  div16u
       1DC1  xdiv16u
       1DDA  empy16s
       1DEA  pop_xgset00FC
       1DF1  pop_xgset30FC
       1DFA  pop_xgsetF0FC
       1E05  push_xgsetF0FC
       1E07  push_xgset30FC
       1E09  push_xgset00FC
       1E0B  push_xgset003C
       1E10  push_xgset300C
       1E15  pop_xgset300C
       1E1A  push_xgsetF000
       1E1F  pop_xgsetF000
       1E24  push_xgsetF00C
       1E2B  pop_xgsetF00C
       1E32  push_xgset303C
       1E39  pop_xgset303C
       1E40  push_xgsetF03C
       1E49  pop_xgsetF03C
       1E52  lsl16
       1E59  lsl8
       1E5F  asgnblk
       1E77  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   07B4 =   1972. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       0103  _key_value
       0113  _nihao
       0713  _temp_h
       0715  _temp_l
       0717  _temps
       08B4  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   08B4   04CB =   1227. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       08B4  _receive_len
       08B4  __bss_start
       08B6  _send_len
       08B8  _receive_buf
       0B10  _send_buf
       0D68  _prePageNum
       0D6A  _pageParam
       0D74  _pageNum
       0D76  _i
       0D77  _time_2
       0D78  _time_0
       0D79  _time_l_3
       0D7A  _time_h_3
       0D7B  _time_l_1
       0D7C  _time_h_1
       0D7D  _uart_timeout_flag2
       0D7E  _uart_timeout_flag1
       0D7F  __bss_end

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
<library>	[ asave.s, div16u.s, emul16s.s, gpop3.s, gpop4.s, gpop5.s, gpush.s, gpushx.s, gpushy.s, gpushz.s, gpusha.s ]
[ gpushb.s, lsl16.s, lsl8.s, struct.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096


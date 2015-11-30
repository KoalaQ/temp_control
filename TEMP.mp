NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   0127 =    295. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       01B3  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   01B4   2AB6 =  10934. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00DA  __text_start
       00DA  __start
       00FC  _exit
       00FD  _delay_us
       0107  _delay_ms
       0117  _delay_s
       0127  _Write1302
       014E  _Read1302
       0180  _Initial_time
       0188  _showTimeLcd
       0221  _getYear
       0224  _getMonth
       0227  _getDay
       022A  _getWeek
       022D  _getHour
       0230  _getMinute
       0233  _getSecond
       0236  _setTime
       0237  _showTime_page
       02C9  _KeyInit
       02CA  _KeyScan
       0397  _KeyScan_once
       03B6  _lcd_bz_1
       03DC  _lcd_wcmd_1
       040A  _lcd_wdat_1
       0434  _lcd_clear_1
       043A  _lcd_bz_2
       0460  _lcd_wcmd_2
       048E  _lcd_wdat_2
       04B8  _lcd_clear_2
       04BE  _lcd_write_char_con
       04D2  _lcd_write_pos
       04F0  _lcd_write_char
       0516  _lcd_write_str
       0560  _lcd_write_str_con
       0583  _read_ac_1
       05A8  _read_ac_2
       05CD  _lcd_clear
       05CF  _date_cmd_1
       05F3  _date_cmd_2
       0617  _read_data_xy
       064C  _read_data_1
       0653  _read_data_2
       065A  _lcd_init
       06AB  _cur_set
       06E7  _Set_Draw
       06F3  _Set_UNDraw
       06FF  _Set_White_off
       077B  _Set_White
       07F3  _Draw_Pic
       0844  _lcd_Desk
       0876  _main
       08B8  _Timerinit_1
       08C7  _Timerinit_3
       08DD  _Timerinit_0
       08E6  _Timerinit_2
       08EF  _int_timer0
       093D  _int_timer1
       098E  _int_timer2
       09DF  _int_timer3
       0A32  _readTemp_1
       0A94  _readTemp_2
       0AF6  _readTemp_3
       0B72  _readTemp_4
       0BEE  _readOC
       0BF4  _out_all
       0BF8  _out_port
       0C1F  _read_port
       0C2F  _init_USART1
       0C3B  _put_c1
       0C3F  _USART_Receive1
       0C54  _receiveStrfromCom
       0C99  _outStrtoCom
       0CAD  _MAC_CalCrc16
       0CD9  _MAC_CheckCrc16
       0CFE  _ComSendResponse
       0D37  _EEPROM_write
       0D4E  _EEPROM_read
       0D64  _pageTime
       0D77  _page1
       10E2  _page2
       1159  _page3
       1177  _page4
       1195  _page5
       126B  _page6
       1282  _page7
       131E  _page8
       153B  _page9
       1547  _dispatchPages
       15A3  push_arg4
       15A5  push_arg2
       15A8  pop_xgset00FC
       15AF  pop_xgset30FC
       15B8  pop_xgsetF0FC
       15C3  push_xgsetF0FC
       15C5  push_xgset30FC
       15C7  push_xgset00FC
       15C9  push_xgset003C
       15CE  push_xgset300C
       15D3  pop_xgset300C
       15D8  push_xgsetF000
       15DD  pop_xgsetF000
       15E2  push_xgsetF00C
       15E9  pop_xgsetF00C
       15F0  push_xgset303C
       15F7  pop_xgset303C
       15FE  push_xgsetF03C
       1607  pop_xgsetF03C
       1610  lsl16
       1617  lsl8
       161D  asgnblk
       1635  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0127 =    295. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       0103  _key_value
       0113  _temp_h
       0115  _temp_l
       0117  _temps
       0227  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0227   04CB =   1227. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0227  _receive_len
       0227  __bss_start
       0229  _send_len
       022B  _receive_buf
       0483  _send_buf
       06DB  _prePageNum
       06DD  _pageParam
       06E7  _pageNum
       06E9  _i
       06EA  _time_2
       06EB  _time_0
       06EC  _time_l_3
       06ED  _time_h_3
       06EE  _time_l_1
       06EF  _time_h_1
       06F0  _uart_timeout_flag2
       06F1  _uart_timeout_flag1
       06F2  __bss_end

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
<library>	[ asave.s, gpop3.s, gpop4.s, gpop5.s, gpush.s, gpushx.s, gpushy.s, gpushz.s, gpusha.s, gpushb.s, lsl16.s ]
[ lsl8.s, struct.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096


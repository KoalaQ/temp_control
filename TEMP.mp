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
                            text   0724   3D62 =  15714. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0392  __start
       0392  __text_start
       03B4  _exit
       03B5  _delay_us
       03BF  _delay_ms
       03CF  _delay_s
       03DF  _KeyInit
       03E0  _KeyScan
       04AD  _KeyScan_once
       04CC  _lcd_bz_1
       04F2  _lcd_wcmd_1
       0518  _lcd_wdat_1
       053E  _lcd_clear_1
       0544  _lcd_bz_2
       056A  _lcd_wcmd_2
       0590  _lcd_wdat_2
       05B6  _lcd_clear_2
       05B8  _lcd_write_char_con
       05CC  _lcd_write_pos
       05EA  _lcd_write_char
       0610  _lcd_write_str
       065A  _lcd_write_str_con
       067D  _read_ac_1
       06A2  _read_ac_2
       06C7  _lcd_clear
       06C9  _date_cmd_1
       06ED  _date_cmd_2
       0711  _read_data_xy
       0746  _read_data_1
       074D  _read_data_2
       0754  _lcd_init
       0781  _cur_set
       07BD  _Set_Draw
       07C1  _Set_UNDraw
       07C5  _Set_White_off
       0835  _Set_White
       08A5  _Draw_Pic
       08F6  _lcd_Desk
       0928  _main
       095A  _Timerinit_1
       0969  _Timerinit_3
       097F  _Timerinit_0
       0988  _Timerinit_2
       0991  _int_timer0
       09DF  _int_timer1
       0A30  _int_timer2
       0A7E  _int_timer3
       0AD1  _readTemp_1
       0B33  _readTemp_2
       0B95  _readTemp_3
       0C11  _readTemp_4
       0C8D  _readOC
       0C93  _out_all
       0C97  _out_port
       0CBE  _read_port
       0CCE  _init_USART1
       0CDA  _put_c1
       0CDE  _USART_Receive1
       0CF3  _receiveStrfromCom
       0D38  _outStrtoCom
       0D4C  _MAC_CalCrc16
       0D78  _MAC_CheckCrc16
       0D9D  _ComSendResponse
       0DD6  _EEPROM_write
       0DED  _EEPROM_read
       0E03  _pageTime
       0E16  _pageTime2
       0E1F  _page1
       1199  _page2
       126D  _page3
       142F  _page4_data
       15D3  _page4_ac
       16AD  _page4
       1975  _page5
       1A9A  _page6
       1ADB  _page7
       1B7B  _page8
       1D9E  _page9
       1DD4  _dispatchPages
       1E33  _tempdata_init
       1E6A  _data_recover
       1EBC  _set_temp_data
       1F24  _reset_temp_data
       1F73  _set_all_start
       1FAF  _set_all_stop
       1FEB  _set_start
       201F  _set_stop
       2053  _I2C_start
       2060  _I2C_stop
       206D  _I2C_send_ack
       2075  _I2C_send_noack
       207D  _I2C_write_byte
       20AF  _I2C_read_byte
       20C7  _Write1307
       20D6  _Read1307
       20E7  _getYear
       20EA  _getMonth
       20ED  _getDay
       20F0  _getWeek
       20F3  _getHour
       20F6  _getMinute
       20F9  _getSecond
       20FC  _setTime
       20FD  _Initial_time
       2103  _showTime_page
       2189  push_arg4
       218B  push_arg2
       218E  mod16u
       2190  div16u
       2191  xdiv16u
       21AA  empy16s
       21BA  pop_xgset003C
       21BF  pop_xgset00FC
       21C6  pop_xgsetF0FC
       21D1  push_xgsetF0FC
       21D3  push_xgset30FC
       21D5  push_xgset00FC
       21D7  push_xgset003C
       21DC  push_xgset300C
       21E1  pop_xgset300C
       21E6  push_xgsetF000
       21EB  pop_xgsetF000
       21F0  push_xgsetF00C
       21F7  pop_xgsetF00C
       21FE  push_xgset303C
       2205  pop_xgset303C
       220C  push_xgsetF03C
       2215  pop_xgsetF03C
       221E  lsl16
       2225  lsl8
       222B  asgnblk
       2243  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0697 =   1687. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  _key_value
       0100  __data_start
       0110  _temp_h
       0112  _temp_l
       0114  _temps
       0797  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0797   04CC =   1228. bytes (rel,con,ram)

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
       0C62  _BP
       0C63  __bss_end

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
<library>	[ asave.s, div16u.s, emul16s.s, gpop2.s, gpop3.s, gpop5.s, gpush.s, gpushx.s, gpushy.s, gpushz.s, gpusha.s ]
[ gpushb.s, lsl16.s, lsl8.s, struct.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096


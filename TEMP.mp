NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   00AB =    171. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       0137  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0138   21D0 =   8656. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       009C  __text_start
       009C  __start
       00BE  _exit
       00BF  _delay_us
       00C9  _delay_ms
       00D9  _delay_s
       00E9  _Write1302
       0110  _Read1302
       0142  _Initial_time
       014A  _showTimeLcd
       01E3  _showTime_page
       0275  _KeyInit
       0276  _KeyScan
       0343  _KeyScan_once
       0362  _lcd_bz_1
       0388  _lcd_wcmd_1
       03B6  _lcd_wdat_1
       03E0  _lcd_clear_1
       03E6  _lcd_bz_2
       040C  _lcd_wcmd_2
       043A  _lcd_wdat_2
       0464  _lcd_clear_2
       046A  _lcd_write_char_con
       047E  _lcd_write_pos
       049C  _lcd_write_char
       04C2  _lcd_write_str
       050C  _lcd_write_str_con
       052F  _read_ac_1
       0554  _read_ac_2
       0579  _lcd_clear
       057B  _date_cmd_1
       059F  _date_cmd_2
       05C3  _read_data_xy
       05F8  _read_data_1
       05FF  _read_data_2
       0606  _lcd_init
       0657  _cur_set
       0693  _Set_Draw
       069F  _Set_UNDraw
       06AB  _Set_White_off
       0727  _Set_White
       079F  _lcd_Desk
       07D1  _main
       0813  _Timerinit_1
       0822  _Timerinit_3
       0838  _Timerinit_0
       0841  _Timerinit_2
       084A  _int_timer0
       0898  _int_timer1
       08E9  _int_timer2
       093A  _int_timer3
       098D  _readTemp_1
       09EF  _readTemp_2
       0A51  _readTemp_3
       0ACD  _readTemp_4
       0B49  _readOC
       0B4F  _out_all
       0B53  _out_port
       0B7A  _read_port
       0B8A  _init_USART1
       0B96  _put_c1
       0B9A  _USART_Receive1
       0BAF  _receiveStrfromCom
       0BF4  _outStrtoCom
       0C08  _MAC_CalCrc16
       0C34  _MAC_CheckCrc16
       0C59  _ComSendResponse
       0C92  _EEPROM_write
       0CA9  _EEPROM_read
       0CBF  _pageUtil
       0CCC  _page1
       0FDC  _page3
       0FE7  _page5
       10B0  _page8
       10BC  _dispatchPages
       110A  push_arg4
       110C  push_arg2
       110F  pop_xgset00FC
       1116  pop_xgset30FC
       111F  pop_xgsetF0FC
       112A  push_xgsetF0FC
       112C  push_xgset30FC
       112E  push_xgset00FC
       1130  push_xgset003C
       1135  push_xgset300C
       113A  pop_xgset300C
       113F  push_xgsetF000
       1144  pop_xgsetF000
       1149  push_xgsetF00C
       1150  pop_xgsetF00C
       1157  push_xgset303C
       115E  pop_xgset303C
       1165  push_xgsetF03C
       116E  pop_xgsetF03C
       1177  lsl16
       117E  lsl8
       1184  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   00AB =    171. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       0103  _key_value
       0113  _temp_h
       0115  _temp_l
       0117  _temps
       01AB  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   01AB   04CB =   1227. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       01AB  _receive_len
       01AB  __bss_start
       01AD  _send_len
       01AF  _receive_buf
       0407  _send_buf
       065F  _prePageNum
       0661  _pageParam
       066B  _pageNum
       066D  _i
       066E  _time_2
       066F  _time_0
       0670  _time_l_3
       0671  _time_h_3
       0672  _time_l_1
       0673  _time_h_1
       0674  _uart_timeout_flag2
       0675  _uart_timeout_flag1
       0676  __bss_end

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
[ lsl8.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096


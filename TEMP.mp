NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   0013 =     19. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       009F  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   00A0   174E =   5966. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0050  __start
       0050  __text_start
       0072  _exit
       0073  _delay_us
       007D  _delay_ms
       008D  _delay_s
       009D  _Write1302
       00C4  _Read1302
       00F6  _Initial_time
       00FE  _showTimeLcd
       0197  _KeyInit
       0198  _KeyScan
       0265  _KeyScan_once
       0296  _lcd_bz_1
       02BC  _lcd_wcmd_1
       02EA  _lcd_wdat_1
       0314  _lcd_clear_1
       031A  _lcd_bz_2
       0340  _lcd_wcmd_2
       036E  _lcd_wdat_2
       0398  _lcd_clear_2
       039E  _lcd_write_char_con
       03B8  _lcd_write_pos
       03D6  _lcd_write_char
       03FC  _lcd_write_str
       0446  _read_ac_1
       046B  _read_ac_2
       0490  _lcd_clear
       0492  _date_cmd_1
       04B6  _date_cmd_2
       04DA  _read_data_xy
       050F  _read_data_1
       0516  _read_data_2
       051D  _lcd_init
       056E  _cur_set
       05AA  _Set_Draw
       05B4  _Set_UNDraw
       05BE  _Set_White_off
       061C  _Set_White
       0676  _lcd_Desk
       06A8  _main
       06DB  _Timerinit_1
       06EA  _Timerinit_3
       0700  _Timerinit_0
       0709  _Timerinit_2
       0712  _int_timer0
       0760  _int_timer1
       07B1  _int_timer2
       0802  _int_timer3
       0855  _readTemp_1
       08B7  _readTemp_2
       0919  _readTemp_3
       0995  _readTemp_4
       0A11  _readOC
       0A17  _out_all
       0A1B  _out_port
       0A42  _read_port
       0A52  _init_USART1
       0A5E  _put_c1
       0A62  _USART_Receive1
       0A77  _receiveStrfromCom
       0ABC  _outStrtoCom
       0AD0  _MAC_CalCrc16
       0AFC  _MAC_CheckCrc16
       0B21  _ComSendResponse
       0B5A  _EEPROM_write
       0B71  _EEPROM_read
       0B87  push_arg4
       0B89  push_arg2
       0B8C  pop_xgset00FC
       0B93  pop_xgset30FC
       0B9C  pop_xgsetF0FC
       0BA7  push_xgsetF0FC
       0BA9  push_xgset30FC
       0BAB  push_xgset00FC
       0BAD  push_xgset003C
       0BB2  push_xgset300C
       0BB7  pop_xgset300C
       0BBC  push_xgsetF00C
       0BC3  pop_xgsetF00C
       0BCA  push_xgset303C
       0BD1  pop_xgset303C
       0BD8  push_xgsetF03C
       0BE1  pop_xgsetF03C
       0BEA  lsl16
       0BF1  lsl8
       0BF7  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0013 =     19. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       010F  _temp_h
       0111  _temp_l
       0113  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0113   04BD =   1213. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0113  __bss_start
       0113  _receive_len
       0115  _send_len
       0117  _receive_buf
       036F  _send_buf
       05C7  _i
       05C8  _time_2
       05C9  _time_0
       05CA  _time_l_3
       05CB  _time_h_3
       05CC  _time_l_1
       05CD  _time_h_1
       05CE  _uart_timeout_flag2
       05CF  _uart_timeout_flag1
       05D0  __bss_end

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
<library>	[ asave.s, gpop3.s, gpop4.s, gpop5.s, gpush.s, gpushx.s, gpushz.s, gpusha.s, gpushb.s, lsl16.s, lsl8.s ]


User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096


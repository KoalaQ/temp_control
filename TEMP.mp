NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   0011 =     17. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       009D  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   009E   1508 =   5384. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       004F  __start
       004F  __text_start
       0071  _exit
       0072  _delay_us
       007C  _delay_ms
       008C  _delay_s
       009C  _Write1302
       00C3  _Read1302
       00F5  _Initial_time
       00FD  _showTimeLcd
       0196  _KeyInit
       0197  _KeyScan
       0264  _KeyScan_once
       0276  _lcd_bz_1
       029C  _lcd_wcmd_1
       02CA  _lcd_wdat_1
       02F4  _lcd_clear_1
       02FA  _lcd_bz_2
       0320  _lcd_wcmd_2
       034E  _lcd_wdat_2
       0378  _lcd_clear_2
       037E  _lcd_write_char_con
       0398  _lcd_write_pos
       03B6  _lcd_write_char
       03DC  _lcd_write_str
       0426  _read_ac_1
       044B  _read_ac_2
       0470  _date_cmd_1
       0494  _date_cmd_2
       04B8  _read_data_xy
       04ED  _read_data_1
       04F4  _read_data_2
       04FB  _lcd_init
       054C  _cur_set
       0588  _lcd_Desk
       0598  _main
       05C7  _Timerinit_1
       05D6  _Timerinit_3
       05EC  _Timerinit_0
       05F5  _Timerinit_2
       05FE  _int_timer0
       064C  _int_timer1
       069D  _int_timer2
       06EE  _int_timer3
       0741  _readTemp_1
       07A3  _readTemp_2
       0805  _readTemp_3
       0881  _readTemp_4
       08FD  _readOC
       0903  _out_all
       0907  _out_port
       092E  _read_port
       093E  _init_USART1
       094A  _put_c1
       094E  _USART_Receive1
       0963  _receiveStrfromCom
       09A8  _outStrtoCom
       09BC  _MAC_CalCrc16
       09E8  _MAC_CheckCrc16
       0A0D  _ComSendResponse
       0A46  _EEPROM_write
       0A5D  _EEPROM_read
       0A73  pop_xgset00FC
       0A7A  pop_xgset30FC
       0A83  push_xgsetF0FC
       0A85  push_xgset30FC
       0A87  push_xgset00FC
       0A89  push_xgset003C
       0A8E  push_xgset300C
       0A93  pop_xgset300C
       0A98  push_xgsetF00C
       0A9F  pop_xgsetF00C
       0AA6  push_xgset303C
       0AAD  pop_xgset303C
       0AB4  push_xgsetF03C
       0ABD  pop_xgsetF03C
       0AC6  lsl16
       0ACD  lsl8
       0AD3  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0011 =     17. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       010D  _temp_h
       010F  _temp_l
       0111  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0111   04BD =   1213. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0111  __bss_start
       0111  _receive_len
       0113  _send_len
       0115  _receive_buf
       036D  _send_buf
       05C5  _i
       05C6  _time_2
       05C7  _time_0
       05C8  _time_l_3
       05C9  _time_h_3
       05CA  _time_l_1
       05CB  _time_h_1
       05CC  _uart_timeout_flag2
       05CD  _uart_timeout_flag1
       05CE  __bss_end

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
<library>	[ gpop3.s, gpop4.s, gpush.s, gpushx.s, gpushz.s, gpusha.s, gpushb.s, lsl16.s, lsl8.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096


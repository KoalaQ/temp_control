NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   008C   0010 =     16. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __lit_start
       009C  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   009C   07A0 =   1952. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       009C  __idata_start
       083C  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   083C   6D52 =  27986. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       041E  __text_start
       041E  __start
       0440  _exit
       0441  _delay_us
       044B  _delay_ms
       045B  _delay_s
       046B  _KeyInit
       046C  _KeyScan
       0539  _KeyScan_once
       0558  _lcd_bz_1
       057E  _lcd_wcmd_1
       05A4  _lcd_wdat_1
       05CA  _lcd_clear_1
       05D0  _lcd_bz_2
       05F6  _lcd_wcmd_2
       061C  _lcd_wdat_2
       0642  _lcd_clear_2
       0644  _lcd_write_char_con
       0658  _lcd_write_pos
       0676  _lcd_write_char
       069C  _lcd_write_str
       06E6  _lcd_write_str_con
       0709  _read_ac_1
       072E  _read_ac_2
       0753  _lcd_clear
       0755  _date_cmd_1
       0779  _date_cmd_2
       079D  _read_data_xy
       07D2  _read_data_1
       07D9  _read_data_2
       07E0  _lcd_init
       080D  _cur_set
       0849  _Set_Draw
       084D  _Set_UNDraw
       0851  _Set_White_off
       08C1  _Set_White
       0931  _Draw_Pic
       0982  _lcd_Desk
       09B4  _main
       09FC  _Timerinit_1
       0A0B  _Timerinit_3
       0A21  _Timerinit_0
       0A2A  _Timerinit_2
       0A33  _int_timer0
       0A8C  _int_timer1
       0AC5  _int_timer2
       0B12  _int_timer3
       0B4F  _readTemp_1
       0BC0  _readTemp_2
       0C39  _readTemp_3
       0CCA  _readTemp_4
       0D71  _readTemp
       0D9B  _out_port
       0E57  _init_USART1
       0E63  _put_c1
       0E67  _USART_Receive1
       0E7C  _receiveStrfromCom
       0EC1  _outStrtoCom
       0ED5  _MAC_CalCrc16
       0F01  _MAC_CheckCrc16
       0F26  _ComSendResponse
       0F5F  _EEPROM_write
       0F76  _EEPROM_read
       0F8C  _pageTime
       0F9F  _pageTime2
       0FA8  _page1
       138B  _page2
       14AF  _page3
       1848  _page4_data
       19EC  _page4_ac
       1AC6  _page4
       1D8F  _page5
       1EB4  _page6
       1EF5  _page7
       1F95  _page8
       232F  _page9
       236A  _dispatchPages
       23CA  _int_int2
       2D35  _tempcontrol
       2EA9  _tempdata_init
       301D  _data_recover
       3155  _set_temp_data
       31BD  _reset_temp_data
       32FC  _set_all_start
       3348  _set_all_stop
       3379  _set_start
       33DB  _set_stop
       3404  _PID_realize
       34FA  _PI_realize
       35C0  _I2C_start
       35CD  _I2C_stop
       35DA  _I2C_send_ack
       35E2  _I2C_send_noack
       35EA  _I2C_write_byte
       361C  _I2C_read_byte
       3634  _Write1307
       3643  _Read1307
       3657  _setTime
       367B  _Initial_time
       368C  _showTime_page
       3712  push_arg4
       3714  push_arg2
       3717  asr16
       371E  mod16s
       3722  div16s
       373C  mod16u
       373E  div16u
       373F  xdiv16u
       3758  elpm32
       376C  empy16s
       377C  pop_xgset003C
       3781  pop_xgset00FC
       3788  pop_xgsetF0FC
       3793  push_xgsetF0FC
       3795  push_xgset30FC
       3797  push_xgset00FC
       3799  push_xgset003C
       379E  push_xgset300C
       37A3  pop_xgset300C
       37A8  push_xgsetF000
       37AD  pop_xgsetF000
       37B2  push_xgsetF00C
       37B9  pop_xgsetF00C
       37C0  push_xgset303C
       37C7  pop_xgset303C
       37CE  push_xgsetF03C
       37D7  pop_xgsetF03C
       37E0  neg32
       37E9  lsl8
       37EF  asgnblk
       3807  fpsub
       3809  fpadd
       380A  fpadd_alt
       3871  fpadd1x
       387E  fpadd2
       3889  fpsub1
       3893  fpsub2
       389E  fpsub1x
       38AB  fpsub2x
       38B9  fpint
       38EB  uint2fp
       38ED  int2fp
       38F6  ulong2fp
       38F8  long2fp
       390F  fpdiv1
       3918  fpdiv2
       3922  fpdiv1x
       392E  fpdiv2x
       39A9  unpacks
       39B1  tstR16_R19
       39B9  unpacku
       39D2  normalize_and_pack
       3A07  pack
       3A17  saveFPRegs
       3A26  restoreFPRegs
       3A35  fpmule
       3A88  fpmule2
       3A93  fpmule1x
       3AA0  fpmule2x
       3AAE  fpcmp
       3ABB  fpcmp2
       3AC7  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   07A0 =   1952. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  _key_value
       0100  __data_start
       0110  _waitflag
       0112  _temp_h
       0114  _temp_l
       0116  _temps
       0626  _secondflag
       0628  _hz
       08A0  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   08A0   04CE =   1230. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       08A0  __bss_start
       08A0  _receive_len
       08A2  _send_len
       08A4  _receive_buf
       0AFC  _send_buf
       0D54  _prePageNum
       0D56  _pageParam
       0D60  _pageNum
       0D62  _i
       0D63  _time_2
       0D64  _time_0
       0D65  _time_l_3
       0D66  _time_h_3
       0D67  _time_l_1
       0D68  _time_h_1
       0D69  _uart_timeout_flag2
       0D6A  _uart_timeout_flag1
       0D6B  _second
       0D6D  _BP
       0D6E  __bss_end

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
<library>	[ asave.s, asr16.s, div16s.s, div16u.s, elpm32.s, emul16s.s, gpop2.s, gpop3.s, gpop5.s, gpush.s, gpushx.s ]
[ gpushy.s, gpushz.s, gpusha.s, gpushb.s, lneg.s, lsl8.s, struct.s, fpadd.s, fpadd1x.s, fpadd2.s, fpsub1.s ]
[ fpsub2.s, fpsub1x.s, fpsub2x.s, fpint.s, int2fp.s, fpdiv_new.s, fputil.s, fpmule.s, fpmule2.s, fpmule1x.s ]
[ fpmule2x.s, fpcmp.s, fpcmp2.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096


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
                            text   083C   6D50 =  27984. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       041E  __text_start
       041E  __start
       0440  _exit
       0441  _delay_us
       044B  _delay_ms
       045B  _delay_s
       046B  _KeyScan
       0538  _KeyScan_once
       0557  _lcd_bz_1
       057D  _lcd_wcmd_1
       05A3  _lcd_wdat_1
       05C9  _lcd_clear_1
       05CF  _lcd_bz_2
       05F5  _lcd_wcmd_2
       061B  _lcd_wdat_2
       0641  _lcd_clear_2
       0643  _lcd_write_char_con
       0657  _lcd_write_pos
       0675  _lcd_write_char
       069B  _lcd_write_str
       06E5  _lcd_write_str_con
       0708  _read_ac_1
       072D  _read_ac_2
       0752  _lcd_clear
       0754  _date_cmd_1
       0778  _date_cmd_2
       079C  _read_data_xy
       07D1  _read_data_1
       07D8  _read_data_2
       07DF  _lcd_init
       080C  _cur_set
       0848  _Set_Draw
       084C  _Set_UNDraw
       0850  _Set_White_off
       08C0  _Set_White
       0930  _Draw_Pic
       0981  _lcd_Desk
       09B3  _main
       09FB  _Timerinit_1
       0A0A  _Timerinit_3
       0A20  _Timerinit_0
       0A29  _Timerinit_2
       0A32  _int_timer0
       0A8B  _int_timer1
       0AC4  _int_timer2
       0B11  _int_timer3
       0B4E  _readTemp_1
       0BBF  _readTemp_2
       0C38  _readTemp_3
       0CC9  _readTemp_4
       0D70  _readTemp
       0D9A  _out_port
       0E56  _init_USART1
       0E62  _put_c1
       0E66  _USART_Receive1
       0E7B  _receiveStrfromCom
       0EC0  _outStrtoCom
       0ED4  _MAC_CalCrc16
       0F00  _MAC_CheckCrc16
       0F25  _ComSendResponse
       0F5E  _EEPROM_write
       0F75  _EEPROM_read
       0F8B  _pageTime
       0F9E  _pageTime2
       0FA7  _page1
       138A  _page2
       14AE  _page3
       1847  _page4_data
       19EB  _page4_ac
       1AC5  _page4
       1D8E  _page5
       1EB3  _page6
       1EF4  _page7
       1F94  _page8
       232E  _page9
       2369  _dispatchPages
       23C9  _int_int2
       2D34  _tempcontrol
       2EA8  _tempdata_init
       301C  _data_recover
       3154  _set_temp_data
       31BC  _reset_temp_data
       32FB  _set_all_start
       3347  _set_all_stop
       3378  _set_start
       33DA  _set_stop
       3403  _PID_realize
       34F9  _PI_realize
       35BF  _I2C_start
       35CC  _I2C_stop
       35D9  _I2C_send_ack
       35E1  _I2C_send_noack
       35E9  _I2C_write_byte
       361B  _I2C_read_byte
       3633  _Write1307
       3642  _Read1307
       3656  _setTime
       367A  _Initial_time
       368B  _showTime_page
       3711  push_arg4
       3713  push_arg2
       3716  asr16
       371D  mod16s
       3721  div16s
       373B  mod16u
       373D  div16u
       373E  xdiv16u
       3757  elpm32
       376B  empy16s
       377B  pop_xgset003C
       3780  pop_xgset00FC
       3787  pop_xgsetF0FC
       3792  push_xgsetF0FC
       3794  push_xgset30FC
       3796  push_xgset00FC
       3798  push_xgset003C
       379D  push_xgset300C
       37A2  pop_xgset300C
       37A7  push_xgsetF000
       37AC  pop_xgsetF000
       37B1  push_xgsetF00C
       37B8  pop_xgsetF00C
       37BF  push_xgset303C
       37C6  pop_xgset303C
       37CD  push_xgsetF03C
       37D6  pop_xgsetF03C
       37DF  neg32
       37E8  lsl8
       37EE  asgnblk
       3806  fpsub
       3808  fpadd
       3809  fpadd_alt
       3870  fpadd1x
       387D  fpadd2
       3888  fpsub1
       3892  fpsub2
       389D  fpsub1x
       38AA  fpsub2x
       38B8  fpint
       38EA  uint2fp
       38EC  int2fp
       38F5  ulong2fp
       38F7  long2fp
       390E  fpdiv1
       3917  fpdiv2
       3921  fpdiv1x
       392D  fpdiv2x
       39A8  unpacks
       39B0  tstR16_R19
       39B8  unpacku
       39D1  normalize_and_pack
       3A06  pack
       3A16  saveFPRegs
       3A25  restoreFPRegs
       3A34  fpmule
       3A87  fpmule2
       3A92  fpmule1x
       3A9F  fpmule2x
       3AAD  fpcmp
       3ABA  fpcmp2
       3AC6  __text_end

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


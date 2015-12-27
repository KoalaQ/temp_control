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
                           idata   009C   08D2 =   2258. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       009C  __idata_start
       096E  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   096E   7116 =  28950. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       04B7  __start
       04B7  __text_start
       04D9  _exit
       04DA  _delay_us
       04E4  _delay_ms
       04F4  _delay_s
       0504  _KeyScan
       05D1  _KeyScan_once
       05F0  _lcd_bz_1
       0616  _lcd_wcmd_1
       063C  _lcd_wdat_1
       0662  _lcd_clear_1
       0668  _lcd_bz_2
       068E  _lcd_wcmd_2
       06B4  _lcd_wdat_2
       06DA  _lcd_clear_2
       06DC  _lcd_write_char_con
       06F0  _lcd_write_pos
       070E  _lcd_write_char
       0734  _lcd_write_str
       077E  _lcd_write_str_con
       07A1  _read_ac_1
       07C6  _read_ac_2
       07EB  _lcd_clear
       07ED  _date_cmd_1
       0811  _date_cmd_2
       0835  _read_data_xy
       086A  _read_data_1
       0871  _read_data_2
       0878  _lcd_init
       08A5  _cur_set
       08E1  _Set_Draw
       08E5  _Set_UNDraw
       08E9  _Set_White_off
       0959  _Set_White
       09C9  _Draw_Pic
       0A1A  _lcd_Desk
       0A4C  _main
       0AC9  _Timerinit_1
       0AD8  _Timerinit_3
       0AEE  _Timerinit_0
       0AF7  _Timerinit_2
       0B00  _int_timer0
       0B7B  _int_timer1
       0BB4  _int_timer2
       0C01  _int_timer3
       0D7F  _readTemp_1
       0DF0  _readTemp_2
       0E69  _readTemp_3
       0EFA  _readTemp_4
       0FA1  _readTemp
       0FCB  _out_port
       1087  _uart0_init
       1095  _putchar0
       1099  _getchar0
       109D  _int_ruart0
       10A5  _int_suart0
       10E7  _puts0
       10F9  _EEPROM_write
       1110  _EEPROM_read
       1126  _pageTime
       1139  _pageTime2
       1142  _page1
       1525  _page2
       166E  _page3
       1A07  _page4_data
       1BAB  _page4_ac
       1C85  _page4
       1F4E  _page5
       2073  _page6
       20B4  _page7
       2154  _page8
       24EE  _page9
       2529  _dispatchPages
       2589  _int_int2
       2EF4  _tempcontrol
       3068  _tempdata_init
       31DC  _data_recover
       3314  _set_temp_data
       33D2  _send_temp_data
       3438  _reset_temp_data
       3577  _set_all_start
       35C3  _set_all_stop
       35F4  _set_start
       3656  _set_stop
       367F  _PID_realize
       3775  _PI_realize
       383B  _I2C_start
       3848  _I2C_stop
       3855  _I2C_send_ack
       385D  _I2C_send_noack
       3865  _I2C_write_byte
       3897  _I2C_read_byte
       38AF  _Write1307
       38BE  _Read1307
       38D2  _setTime
       38F6  _Initial_time
       3907  _showTime_page
       398D  push_arg4
       398F  push_arg2
       3992  asr16
       3999  mod16s
       399D  div16s
       39B7  mod16u
       39B9  div16u
       39BA  xdiv16u
       39D3  elpm32
       39E7  empy16s
       39F7  pop_xgset003C
       39FC  pop_xgset00FC
       3A03  pop_xgsetF0FC
       3A0E  push_xgsetF0FC
       3A10  push_xgset30FC
       3A12  push_xgset00FC
       3A14  push_xgset003C
       3A19  push_xgset300C
       3A1E  pop_xgset300C
       3A23  push_xgsetF000
       3A28  pop_xgsetF000
       3A2D  push_xgsetF00C
       3A34  pop_xgsetF00C
       3A3B  push_xgset303C
       3A42  pop_xgset303C
       3A49  push_xgsetF03C
       3A52  pop_xgsetF03C
       3A5B  neg32
       3A64  lsl8
       3A6A  asgnblk
       3A82  fpsub
       3A84  fpadd
       3A85  fpadd_alt
       3AEC  fpadd1x
       3AF9  fpadd2
       3B04  fpsub1
       3B0E  fpsub2
       3B19  fpsub1x
       3B26  fpsub2x
       3B34  fpint
       3B66  uint2fp
       3B68  int2fp
       3B71  ulong2fp
       3B73  long2fp
       3B8A  fpdiv1
       3B93  fpdiv2
       3B9D  fpdiv1x
       3BA9  fpdiv2x
       3C24  unpacks
       3C2C  tstR16_R19
       3C34  unpacku
       3C4D  normalize_and_pack
       3C82  pack
       3C92  saveFPRegs
       3CA1  restoreFPRegs
       3CB0  fpmule
       3D03  fpmule2
       3D0E  fpmule1x
       3D1B  fpmule2x
       3D29  fpcmp
       3D36  fpcmp2
       3D42  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   08D2 =   2258. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  _key_value
       0100  __data_start
       0110  _send_data_cache
       023C  _send_data_length
       023E  _send_data_cur
       0240  _t0_flag
       0242  _waitflag
       0244  _temp_h
       0246  _temp_l
       0248  _temps
       0758  _secondflag
       075A  _hz
       09D2  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   09D2   04CC =   1228. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       09D2  __bss_start
       09D2  _receive_len
       09D4  _send_len
       09D6  _receive_buf
       0C2E  _send_6buf
       0E86  _prePageNum
       0E88  _pageParam
       0E92  _pageNum
       0E94  _i
       0E95  _time_2
       0E96  _time_0
       0E97  _time_l_3
       0E98  _time_h_3
       0E99  _time_l_1
       0E9A  _time_h_1
       0E9B  _second
       0E9D  _BP
       0E9E  __bss_end

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


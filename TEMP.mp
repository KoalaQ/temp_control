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
                           idata   009C   09BF =   2495. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       009C  __idata_start
       0A5B  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0A5C   74CC =  29900. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       052E  __start
       052E  __text_start
       0550  _exit
       0551  _delay_us
       055B  _delay_ms
       056B  _delay_s
       057B  _KeyScan
       0648  _KeyScan_once
       0667  _lcd_bz_1
       068D  _lcd_wcmd_1
       06B3  _lcd_wdat_1
       06D9  _lcd_clear_1
       06DF  _lcd_bz_2
       0705  _lcd_wcmd_2
       072B  _lcd_wdat_2
       0751  _lcd_clear_2
       0753  _lcd_write_char_con
       0767  _lcd_write_pos
       0785  _lcd_write_char
       07AB  _lcd_write_str
       07F5  _lcd_write_str_con
       0818  _read_ac_1
       083D  _read_ac_2
       0862  _lcd_clear
       0864  _date_cmd_1
       0888  _date_cmd_2
       08AC  _read_data_xy
       08E1  _read_data_1
       08E8  _read_data_2
       08EF  _lcd_init
       091C  _cur_set
       0958  _Set_Draw
       095C  _Set_UNDraw
       0960  _Set_White_off
       09D0  _Set_White
       0A40  _Draw_Pic
       0A91  _lcd_Desk
       0AC3  _main
       0B40  _Timerinit_1
       0B4F  _Timerinit_3
       0B65  _Timerinit_0
       0B6E  _Timerinit_2
       0B77  _int_timer0
       0BF2  _int_timer1
       0C2B  _int_timer2
       0C78  _int_timer3
       0E46  _readTemp_1
       0EB7  _readTemp_2
       0F30  _readTemp_3
       0FC1  _readTemp_4
       1068  _readTemp
       1092  _out_port
       114E  _uart0_init
       115C  _putchar0
       1160  _getchar0
       1164  _int_ruart0
       11FA  _int_suart0
       1239  _puts0
       124B  _cmd_oper
       1272  _read_cmd
       12F4  _EEPROM_write
       130B  _EEPROM_read
       1321  _pageTime
       1334  _pageTime2
       133D  _page1
       1720  _page2
       1869  _page3
       1C59  _page4_data
       1DFD  _page4_ac
       1ED7  _page4
       21A0  _page5
       22C5  _page6
       2306  _page7
       23A6  _page8
       2740  _page9
       277B  _dispatchPages
       27DB  _int_int2
       3146  _tempcontrol
       32BA  _tempdata_init
       342E  _data_recover
       3566  _set_temp_data
       3624  _send_temp_data
       368A  _reset_temp_data
       37C9  _set_all_start
       3815  _set_all_stop
       3846  _set_start
       38A8  _set_stop
       38D1  _PID_realize
       39C7  _PI_realize
       3A8D  _I2C_start
       3A9A  _I2C_stop
       3AA7  _I2C_send_ack
       3AAF  _I2C_send_noack
       3AB7  _I2C_write_byte
       3AE9  _I2C_read_byte
       3B01  _Write1307
       3B10  _Read1307
       3B24  _setTime
       3B48  _Initial_time
       3B59  _showTime_page
       3BDF  push_arg4
       3BE1  push_arg2
       3BE4  asr16
       3BEB  mod16s
       3BEF  div16s
       3C09  mod16u
       3C0B  div16u
       3C0C  xdiv16u
       3C25  elpm32
       3C39  empy16s
       3C49  pop_xgset003C
       3C4E  pop_xgset00FC
       3C55  pop_xgsetF0FC
       3C60  push_xgsetF0FC
       3C62  push_xgset30FC
       3C64  push_xgset00FC
       3C66  push_xgset003C
       3C6B  push_xgset300C
       3C70  pop_xgset300C
       3C75  push_xgsetF000
       3C7A  pop_xgsetF000
       3C7F  push_xgsetF00C
       3C86  pop_xgsetF00C
       3C8D  push_xgset303C
       3C94  pop_xgset303C
       3C9B  push_xgsetF03C
       3CA4  pop_xgsetF03C
       3CAD  neg32
       3CB6  lsl8
       3CBC  asgnblk
       3CD4  fpsub
       3CD6  fpadd
       3CD7  fpadd_alt
       3D3E  fpadd1x
       3D4B  fpadd2
       3D56  fpsub1
       3D60  fpsub2
       3D6B  fpsub1x
       3D78  fpsub2x
       3D86  fpint
       3DB8  uint2fp
       3DBA  int2fp
       3DC3  ulong2fp
       3DC5  long2fp
       3DDC  fpdiv1
       3DE5  fpdiv2
       3DEF  fpdiv1x
       3DFB  fpdiv2x
       3E76  unpacks
       3E7E  tstR16_R19
       3E86  unpacku
       3E9F  normalize_and_pack
       3ED4  pack
       3EE4  saveFPRegs
       3EF3  restoreFPRegs
       3F02  fpmule
       3F55  fpmule2
       3F60  fpmule1x
       3F6D  fpmule2x
       3F7B  fpcmp
       3F88  fpcmp2
       3F94  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   09BF =   2495. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  _key_value
       0100  __data_start
       0110  _read_data_cache
       0218  _read_data_cur
       021A  _read_data_cmd
       021B  _send_data_cache
       0329  _send_data_length
       032B  _send_data_cur
       032D  _t0_flag
       032F  _waitflag
       0331  _temp_h
       0333  _temp_l
       0335  _temps
       0845  _secondflag
       0847  _hz
       0ABF  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0ABF   0018 =     24. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0ABF  _prePageNum
       0ABF  __bss_start
       0AC1  _pageParam
       0ACB  _pageNum
       0ACD  _i
       0ACE  _time_2
       0ACF  _time_0
       0AD0  _time_l_3
       0AD1  _time_h_3
       0AD2  _time_l_1
       0AD3  _time_h_1
       0AD4  _second
       0AD6  _BP
       0AD7  __bss_end

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


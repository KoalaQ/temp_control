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
                           idata   009C   0799 =   1945. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       009C  __idata_start
       0835  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0836   5826 =  22566. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       041B  __text_start
       041B  __start
       043D  _exit
       043E  _delay_us
       0448  _delay_ms
       0458  _delay_s
       0468  _KeyInit
       0469  _KeyScan
       0536  _KeyScan_once
       0555  _lcd_bz_1
       057B  _lcd_wcmd_1
       05A1  _lcd_wdat_1
       05C7  _lcd_clear_1
       05CD  _lcd_bz_2
       05F3  _lcd_wcmd_2
       0619  _lcd_wdat_2
       063F  _lcd_clear_2
       0641  _lcd_write_char_con
       0655  _lcd_write_pos
       0673  _lcd_write_char
       0699  _lcd_write_str
       06E3  _lcd_write_str_con
       0706  _read_ac_1
       072B  _read_ac_2
       0750  _lcd_clear
       0752  _date_cmd_1
       0776  _date_cmd_2
       079A  _read_data_xy
       07CF  _read_data_1
       07D6  _read_data_2
       07DD  _lcd_init
       080A  _cur_set
       0846  _Set_Draw
       084A  _Set_UNDraw
       084E  _Set_White_off
       08BE  _Set_White
       092E  _Draw_Pic
       097F  _lcd_Desk
       09B1  _main
       09F9  _Timerinit_1
       0A08  _Timerinit_3
       0A1E  _Timerinit_0
       0A27  _Timerinit_2
       0A30  _int_timer0
       0A89  _int_timer1
       0AC2  _int_timer2
       0B0F  _int_timer3
       0B4C  _readTemp_1
       0BBD  _readTemp_2
       0C36  _readTemp_3
       0CC7  _readTemp_4
       0D6E  _readTemp
       0D98  _out_port
       0E40  _init_USART1
       0E4C  _put_c1
       0E50  _USART_Receive1
       0E65  _receiveStrfromCom
       0EAA  _outStrtoCom
       0EBE  _MAC_CalCrc16
       0EEA  _MAC_CheckCrc16
       0F0F  _ComSendResponse
       0F48  _EEPROM_write
       0F5F  _EEPROM_read
       0F75  _pageTime
       0F88  _pageTime2
       0F91  _page1
       1369  _page2
       148D  _page3
       1813  _page4_data
       19B7  _page4_ac
       1A91  _page4
       1D59  _page5
       1E7E  _page6
       1EBF  _page7
       1F5F  _page8
       22F9  _page9
       2334  _dispatchPages
       2394  _int_int2
       24C4  _tempcontrol
       262B  _tempdata_init
       279F  _data_recover
       27F1  _set_temp_data
       283D  _reset_temp_data
       2882  _set_all_start
       28CE  _set_all_stop
       28FF  _set_start
       2942  _set_stop
       296B  _PID_realize
       2A61  _PI_realize
       2B27  _I2C_start
       2B34  _I2C_stop
       2B41  _I2C_send_ack
       2B49  _I2C_send_noack
       2B51  _I2C_write_byte
       2B83  _I2C_read_byte
       2B9B  _Write1307
       2BAA  _Read1307
       2BBE  _setTime
       2BE2  _Initial_time
       2BF3  _showTime_page
       2C79  push_arg4
       2C7B  push_arg2
       2C7E  asr16
       2C85  mod16s
       2C89  div16s
       2CA3  mod16u
       2CA5  div16u
       2CA6  xdiv16u
       2CBF  elpm32
       2CD3  empy16s
       2CE3  pop_xgset003C
       2CE8  pop_xgset00FC
       2CEF  pop_xgsetF0FC
       2CFA  push_xgsetF0FC
       2CFC  push_xgset30FC
       2CFE  push_xgset00FC
       2D00  push_xgset003C
       2D05  push_xgset300C
       2D0A  pop_xgset300C
       2D0F  push_xgsetF000
       2D14  pop_xgsetF000
       2D19  push_xgsetF00C
       2D20  pop_xgsetF00C
       2D27  push_xgset303C
       2D2E  pop_xgset303C
       2D35  push_xgsetF03C
       2D3E  pop_xgsetF03C
       2D47  neg32
       2D50  lsl8
       2D56  asgnblk
       2D6E  fpsub
       2D70  fpadd
       2D71  fpadd_alt
       2DD8  fpadd1x
       2DE5  fpadd2
       2DF0  fpsub1
       2DFA  fpsub2
       2E05  fpsub1x
       2E12  fpsub2x
       2E20  fpint
       2E52  uint2fp
       2E54  int2fp
       2E5D  ulong2fp
       2E5F  long2fp
       2E76  fpdiv1
       2E7F  fpdiv2
       2E89  fpdiv1x
       2E95  fpdiv2x
       2F10  unpacks
       2F18  tstR16_R19
       2F20  unpacku
       2F39  normalize_and_pack
       2F6E  pack
       2F7E  saveFPRegs
       2F8D  restoreFPRegs
       2F9C  fpmule
       2FEF  fpmule2
       2FFA  fpmule1x
       3007  fpmule2x
       3015  fpcmp
       3022  fpcmp2
       302E  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0799 =   1945. bytes (rel,con,ram)

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
       0899  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0899   04CC =   1228. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0899  _receive_len
       0899  __bss_start
       089B  _send_len
       089D  _receive_buf
       0AF5  _send_buf
       0D4D  _prePageNum
       0D4F  _pageParam
       0D59  _pageNum
       0D5B  _i
       0D5C  _time_2
       0D5D  _time_0
       0D5E  _time_l_3
       0D5F  _time_h_3
       0D60  _time_l_1
       0D61  _time_h_1
       0D62  _uart_timeout_flag2
       0D63  _uart_timeout_flag1
       0D64  _BP
       0D65  __bss_end

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


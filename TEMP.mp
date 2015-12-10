NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   008C   0018 =     24. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __lit_start
       00A4  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   00A4   075E =   1886. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00A4  __idata_start
       0802  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0802   5080 =  20608. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0401  __text_start
       0401  __start
       0423  _exit
       0424  _delay_us
       042E  _delay_ms
       043E  _delay_s
       044E  _KeyInit
       044F  _KeyScan
       051C  _KeyScan_once
       053B  _lcd_bz_1
       0561  _lcd_wcmd_1
       0587  _lcd_wdat_1
       05AD  _lcd_clear_1
       05B3  _lcd_bz_2
       05D9  _lcd_wcmd_2
       05FF  _lcd_wdat_2
       0625  _lcd_clear_2
       0627  _lcd_write_char_con
       063B  _lcd_write_pos
       0659  _lcd_write_char
       067F  _lcd_write_str
       06C9  _lcd_write_str_con
       06EC  _read_ac_1
       0711  _read_ac_2
       0736  _lcd_clear
       0738  _date_cmd_1
       075C  _date_cmd_2
       0780  _read_data_xy
       07B5  _read_data_1
       07BC  _read_data_2
       07C3  _lcd_init
       07F0  _cur_set
       082C  _Set_Draw
       0830  _Set_UNDraw
       0834  _Set_White_off
       08A4  _Set_White
       0914  _Draw_Pic
       0965  _lcd_Desk
       0997  _main
       09DC  _Timerinit_1
       09EB  _Timerinit_3
       0A01  _Timerinit_0
       0A0A  _Timerinit_2
       0A13  _int_timer0
       0A6C  _int_timer1
       0AA5  _int_timer2
       0AF3  _int_timer3
       0B30  _readTemp_1
       0BA1  _readTemp_2
       0C1A  _readTemp_3
       0CAB  _readTemp_4
       0D52  _readTemp
       0D7C  _out_port
       0E28  _init_USART1
       0E34  _put_c1
       0E38  _USART_Receive1
       0E4D  _receiveStrfromCom
       0E92  _outStrtoCom
       0EA6  _MAC_CalCrc16
       0ED2  _MAC_CheckCrc16
       0EF7  _ComSendResponse
       0F30  _EEPROM_write
       0F47  _EEPROM_read
       0F5D  _pageTime
       0F70  _pageTime2
       0F79  _page1
       1351  _page2
       1475  _page3
       16CA  _page4_data
       186E  _page4_ac
       1948  _page4
       1C10  _page5
       1D35  _page6
       1D76  _page7
       1E16  _page8
       21B0  _page9
       21EB  _dispatchPages
       224B  _tempcontrol
       2390  _tempdata_init
       24A2  _data_recover
       24F4  _set_temp_data
       2540  _reset_temp_data
       2585  _set_all_start
       25B6  _set_all_stop
       25E7  _set_start
       2610  _set_stop
       2639  _PID_realize
       272F  _I2C_start
       273C  _I2C_stop
       2749  _I2C_send_ack
       2751  _I2C_send_noack
       2759  _I2C_write_byte
       278B  _I2C_read_byte
       27A3  _Write1307
       27B2  _Read1307
       27C6  _setTime
       27EA  _Initial_time
       27FB  _showTime_page
       2881  _int_int2
       2893  push_arg4
       2895  push_arg2
       2898  asr16
       289F  mod16s
       28A3  div16s
       28BD  mod16u
       28BF  div16u
       28C0  xdiv16u
       28D9  elpm32
       28ED  empy16s
       28FD  pop_xgset003C
       2902  pop_xgset00FC
       2909  pop_xgsetF0FC
       2914  push_xgsetF0FC
       2916  push_xgset30FC
       2918  push_xgset00FC
       291A  push_xgset003C
       291F  push_xgset300C
       2924  pop_xgset300C
       2929  push_xgsetF000
       292E  pop_xgsetF000
       2933  push_xgsetF00C
       293A  pop_xgsetF00C
       2941  push_xgset303C
       2948  pop_xgset303C
       294F  push_xgsetF03C
       2958  pop_xgsetF03C
       2961  neg32
       296A  lsl16
       2971  lsl8
       2977  asgnblk
       298F  fpsub
       2991  fpadd
       2992  fpadd_alt
       29F9  fpadd1x
       2A06  fpadd2
       2A11  fpsub1
       2A1B  fpsub2
       2A26  fpsub1x
       2A33  fpint
       2A65  uint2fp
       2A67  int2fp
       2A70  ulong2fp
       2A72  long2fp
       2A89  fpdiv1
       2A92  fpdiv2
       2A9C  fpdiv1x
       2AA8  fpdiv2x
       2B23  unpacks
       2B2B  tstR16_R19
       2B33  unpacku
       2B4C  normalize_and_pack
       2B81  pack
       2B91  saveFPRegs
       2BA0  restoreFPRegs
       2BAF  fpmule
       2C02  fpmule2
       2C0D  fpmule1x
       2C1A  fpmule2x
       2C28  fpcmp
       2C35  fpcmp2
       2C41  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   075E =   1886. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  _key_value
       0100  __data_start
       0110  _waitflag
       0112  _temp_h
       0114  _temp_l
       0116  _temps
       05FE  _hz
       085E  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   085E   04CC =   1228. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       085E  _receive_len
       085E  __bss_start
       0860  _send_len
       0862  _receive_buf
       0ABA  _send_buf
       0D12  _prePageNum
       0D14  _pageParam
       0D1E  _pageNum
       0D20  _i
       0D21  _time_2
       0D22  _time_0
       0D23  _time_l_3
       0D24  _time_h_3
       0D25  _time_l_1
       0D26  _time_h_1
       0D27  _uart_timeout_flag2
       0D28  _uart_timeout_flag1
       0D29  _BP
       0D2A  __bss_end

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
[ gpushy.s, gpushz.s, gpusha.s, gpushb.s, lneg.s, lsl16.s, lsl8.s, struct.s, fpadd.s, fpadd1x.s, fpadd2.s ]
[ fpsub1.s, fpsub2.s, fpsub1x.s, fpint.s, int2fp.s, fpdiv_new.s, fputil.s, fpmule.s, fpmule2.s, fpmule1x.s ]
[ fpmule2x.s, fpcmp.s, fpcmp2.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096


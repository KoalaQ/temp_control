CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega128  -l -g -MLongJump -MHasMul -MEnhanced -Wf-use_elpm 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x20000 -ucrtatmega.o -bfunc_lit:0x8c.0x20000 -dram_end:0x10ff -bdata:0x100.0x10ff -dhwstk_size:30 -beeprom:0.4096 -fihx_coff -S2
FILES = delay.o time.o key.o lcd.o main.o timertask.o max6675.o out.o uart.o eeprom.o pages.o temp.o 

TEMP:	$(FILES)
	$(CC) -o TEMP $(LFLAGS) @TEMP.lk   -llpatm128 -lcatm128
delay.o: D:\iccv7avr\include\iom128v.h .\delay.h
delay.o:	delay.c
	$(CC) -c $(CFLAGS) delay.c
time.o: D:\iccv7avr\include\iom128v.h .\time.h .\delay.h .\lcd.h
time.o:	time.c
	$(CC) -c $(CFLAGS) time.c
key.o: D:\iccv7avr\include\iom128v.h .\delay.h .\lcd.h
key.o:	key.c
	$(CC) -c $(CFLAGS) key.c
lcd.o: D:\iccv7avr\include\iom128v.h .\lcd.h .\delay.h
lcd.o:	lcd.c
	$(CC) -c $(CFLAGS) lcd.c
main.o: D:\iccv7avr\include\iom128v.h .\main.h .\lcd.h .\time.h .\key.h .\delay.h .\timertask.h .\eeprom.h .\pages.h .\temp.h
main.o:	main.c
	$(CC) -c $(CFLAGS) main.c
timertask.o: D:\iccv7avr\include\iom128v.h .\timertask.h .\time.h .\lcd.h .\delay.h
timertask.o:	timertask.c
	$(CC) -c $(CFLAGS) timertask.c
max6675.o: D:\iccv7avr\include\iom128v.h .\max6675.h .\main.h .\delay.h
max6675.o:	max6675.c
	$(CC) -c $(CFLAGS) max6675.c
out.o: D:\iccv7avr\include\iom128v.h .\out.h
out.o:	out.c
	$(CC) -c $(CFLAGS) out.c
uart.o: D:\iccv7avr\include\iom128v.h .\uart.h
uart.o:	uart.c
	$(CC) -c $(CFLAGS) uart.c
eeprom.o: D:\iccv7avr\include\iom128v.h .\eeprom.h .\delay.h
eeprom.o:	eeprom.c
	$(CC) -c $(CFLAGS) eeprom.c
pages.o: D:\iccv7avr\include\iom128v.h .\main.h .\lcd.h .\time.h .\timertask.h .\key.h .\delay.h .\temp.h
pages.o:	pages.c
	$(CC) -c $(CFLAGS) pages.c
temp.o: D:\iccv7avr\include\iom128v.h .\temp.h .\main.h .\eeprom.h
temp.o:	temp.c
	$(CC) -c $(CFLAGS) temp.c

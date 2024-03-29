# commands/Makefile

#ENTRYPOINT	= 0x1000
HD		= ../80m.img

ASM		= nasm
DASM		= objdump
CC		= gcc
LD		= ld
ASMFLAGS	= -I ../include/ -f elf
CFLAGS		= -m32 -I ../include/ -I ../include/sys -c -fno-builtin -fno-stack-protector -Wall
LDFLAGS		= -m elf_i386 -Ttext 0x1000
DASMFLAGS	= -D
LIB		= ../lib/orangescrt.a
BIN		= echo cd rmdir mkdir touch rm ls cat write

# All Phony Targets
.PHONY : everything final clean realclean disasm all install

# Default starting position
everything : $(BIN)

install : all clean
	tar vcf inst.tar  text $(BIN)
	dd if=inst.tar of=$(HD) seek=`echo "obase=10;ibase=16;(\`egrep -e '^ROOT_BASE' ../boot/include/load.inc | sed -e 's/.*0x//g'\`+\`egrep -e '#define[[:space:]]*INSTALL_START_SECT' ../include/sys/config.h | sed -e 's/.*0x//g'\`)*200" | bc` bs=1 count=`ls -l inst.tar | awk -F " " '{print $$5}'` conv=notrunc

all : realclean everything

final : all clean

clean :
	rm -f *.o

realclean :
	rm -f $(BIN) *.o


start.o : start.asm
	$(ASM) $(ASMFLAGS) -o $@ $<

echo.o: echo.c ../include/type.h ../include/sys/fs.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

echo : echo.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

pwd.o: pwd.c ../include/type.h ../include/sys/fs.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

pwd : pwd.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

cd.o: cd.c ../include/type.h  ../include/sys/fs.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

cd : cd.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

rmdir.o: rmdir.c ../include/type.h  ../include/sys/fs.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

rmdir : rmdir.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?	

mkdir.o: mkdir.c ../include/type.h  ../include/sys/fs.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

mkdir : mkdir.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?	

touch.o: touch.c ../include/type.h  ../include/sys/fs.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

touch : touch.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?	

rm.o: rm.c ../include/type.h  ../include/sys/fs.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

rm : rm.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?	

ls.o: ls.c ../include/type.h  ../include/sys/fs.h ../include/stdio.h ../include/sys/const.h
	$(CC) $(CFLAGS) -o $@ $<

ls : ls.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?	

cat.o: cat.c ../include/type.h  ../include/sys/fs.h ../include/stdio.h ../include/sys/const.h
	$(CC) $(CFLAGS) -o $@ $<

cat : cat.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?	

write.o: write.c ../include/type.h  ../include/sys/fs.h ../include/stdio.h ../include/sys/const.h
	$(CC) $(CFLAGS) -o $@ $<

write : write.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?	

# makfile configuration
COMMON_OBJECTS		= memoryGame.o draw_shapes.o wdtInterruptHandlerLCD.o switchesLCD.o p2_interrupt_handlerLCD.o buzzer.o game.o
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: memoryGame_c.elf memoryGame_s.elf

#additional rules for files
memoryGame_c.elf: ${COMMON_OBJECTS} is_level_done_c.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd
memoryGame_s.elf: ${COMMON_OBJECTS} is_level_done_s.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

load_c: memoryGame_c.elf
	msp430loader.sh $^
load_s:memoryGame_s.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf *~

# makfile configuration
COMMON_OBJECTS		= draw_shapes.o wdtInterruptHandlerLCD.o switchesLCD.o p2_interrupt_handlerLCD.o buzzer.o
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: memoryGame.elf

#additional rules for files
memoryGame.elf: ${COMMON_OBJECTS} memoryGame.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load: memoryGame.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf *~

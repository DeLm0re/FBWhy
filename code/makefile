WARNING_FLAGS = -Wall -Wextra -pedantic -Wformat\
				-Wshadow -Wpointer-arith\
				-Wmissing-prototypes -Wcast-align -pedantic-errors

CFLAGS = -std=c99 -m64 -O2 $(WARNING_FLAGS)
CC = gcc
CLIBS = -lm -lglut -lGL -lX11

main: main.o GfxLib.o BmpLib.o OutilsLib.o core.o display.o image.o learning.o
	@echo "Links edition :"
	gcc $(CFLAGS) $^ -o $@ $(CLIBS)
	rm -f *~ *.o
	@echo ""

main.o: main.c GfxLib.h ESLib.h core.h display.h
	@echo "Compilation main :"
	gcc $(CFLAGS) -c $<
	@echo ""

core.o: core.c core.h
	@echo "Compilation core :"
	gcc $(CFLAGS) -c $<
	@echo ""

display.o: display.c display.h
	@echo "Compilation display :"
	gcc $(CFLAGS) -c $<
	@echo ""

image.o: image.c image.h
	@echo "Compilation image :"
	gcc $(CFLAGS) -c $<
	@echo ""

learning.o: learning.c learning.h
	@echo "Compilation learning :"
	gcc $(CFLAGS) -c $<
	@echo ""

ESLib.o: ESLib.c ESLib.h ErreurLib.h
	@echo "Compilation ESLib :"
	gcc $(CFLAGS) -c $<
	@echo ""

ErreurLib.o: ErreurLib.c ErreurLib.h
	@echo "Compilation ErreurLib :"
	gcc $(CFLAGS) -c $<
	@echo ""

GfxLib.o: GfxLib.c GfxLib.h ESLib.h
	@echo "Compilation GfxLib :"
	gcc -Wall -c $< -I/usr/include/GL 
	@echo ""

BmpLib.o: BmpLib.c BmpLib.h OutilsLib.h
	@echo "Compilation BmpLib :"
	gcc -Wall -c $<
	@echo ""

OutilsLib.o: OutilsLib.c OutilsLib.h
	@echo "Compilation OutilsLib :"
	gcc -Wall -c $<
	@echo ""

clean:
	rm -f *.o
	rm -f main
	rm -f *~


WARNING_FLAGS = -Wall -Wextra -pedantic -Wformat\
				-Wshadow -Wpointer-arith\
				-Wmissing-prototypes -Wcast-align -pedantic-errors

CFLAGS = -std=c99 -m64 -O2 $(WARNING_FLAGS)
CC = gcc
CLIBS = -lm -lglut -lGL -lX11

main: main.o GfxLib.o
	@echo "Links edition :"
	gcc $(CFLAGS) $^ -o $@ $(CLIBS)
	rm -f *~ *.o
	@echo ""

main.o: main.c GfxLib.h ESLib.h
	@echo "Compilation main :"
	gcc $(CFLAGS) -c $<
	@echo ""

ESLib.o: ESLib.c ESLib.h ErreurLib.h
	@echo "Compilation ESLib :"
	gcc $(CFLAGS) -c ESLib.c
	@echo ""

ErreurLib.o: ErreurLib.c ErreurLib.h
	@echo "Compilation ErreurLib :"
	gcc $(CFLAGS) ErreurLib.c
	@echo ""

GfxLib.o: GfxLib.c GfxLib.h ESLib.h
	@echo "Compilation GfxLib :"
	gcc -Wall -c GfxLib.c -I/usr/include/GL 
	@echo ""

clean:
	rm -f *.o
	rm -f main
	rm -f *~


CC = gcc -c
LINK = gcc
RM = rm
CFLAG = -W -Wall -O2

.PHONY : all clean

all: Mandelbrot.exe

clean:
	-$(RM) *.o Mandelbrot.exe

Mandelbrot.exe: Mandelbrot.o displayplot.o libpng.a libz.a
	$(LINK) -s -o Mandelbrot.exe Mandelbrot.o displayplot.o libpng.a libz.a -lm

Mandelbrot.o: Mandelbrot.c displayplot.h
	$(CC) $(CFLAG) Mandelbrot.c

displayplot.o: displayplot.c displayplot.h png.h
	$(CC) $(CFLAG) displayplot.c


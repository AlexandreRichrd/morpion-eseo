CC=gcc
CFLAGS=-I. -DSYMBOL1 -DSYMBOL2
DEPS = header1.h header2.h
SRCS = src1.c src2.c src3.c
OBJS = src1.o src2.o src3.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cible: $(OBJS)
	$(CC) -o $@ $< $(CFLAGS)
	
clean:
	rm -f cible $(OBJS)
	

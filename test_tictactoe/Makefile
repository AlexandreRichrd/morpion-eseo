CC=gcc
DEPS = test_CheckEndOfGame.h
SRCS = main.c test_CheckEndOfGame.c
OBJS = main.o test_CheckEndOfGame.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJS)
	$(CC) -o $@ $< $(CFLAGS)

test2:
	echo 'aaaaaaaaa'

	
clean:
	rm -f cible $(OBJS)
	

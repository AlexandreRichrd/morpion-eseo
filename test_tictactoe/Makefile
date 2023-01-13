CC=gcc
DEPS = test_checkEndOfGame.h ../etape1/board.c
SRCS = main.c test_checkEndOfGame.c
OBJS = main.o test_checkEndOfGame.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

test2:
	echo 'aaaaaaaaa'

	
clean:
	rm -f cible $(OBJS)
	

CC=gcc
CFLAGS=-DCONFIG_TEXTUI -DCONFIG_PLAYER_MANAGER_SCANF
DEPS = game.h  board.h board_view.h player_manager.h
SRCS = main.c game.c  board.c board_view_text.c player_manager_scanf.c
OBJS = main.o game.o  board.o board_view_text.o player_manager_scanf.o


etape2: $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)


clean:
	rm -f *.o etape2	
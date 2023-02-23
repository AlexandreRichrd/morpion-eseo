CC=gcc
CFLAGS=-DCONFIG_TEXTUI -DCONFIG_PLAYER_MANAGER_MOCK
DEPS = game.h  board.h board_view.h player_manager.h
SRCS = main.c game.c  board.c board_view_text.c player_manager_mock.c
OBJS = main.o game.o  board.o board_view_text.o player_manager_mock.o


etape1: $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)


clean:
	rm -f *.o etape1	
CC=gcc
DEPS = game.h  board.h board_view.h player_manager.h
SRCS = main.c game.c  board.c board_view_text.c
OBJS = main.o game.o  board.o board_view_text.o


etape1: $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) -D CONFIG_TEXTUI CONFIG_PLAYER_MANAGER_MOCK
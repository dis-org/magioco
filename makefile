CC= gcc
CFLAGS= -std=c99 -Wall -g
mainexec: main.c battle.c save.c input.c management.c output.c text.c
	$(CC) $(CFLAGS) -o test main.c battle.c save.c input.c management.c output.c text.c

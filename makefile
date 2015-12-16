CC= gcc
CFLAGS= -std=c99 -Wall
mainexec: main.c battle.c event.c input.c management.c output.c text.c
	$(CC) $(CFLAGS) -o test main.c battle.c event.c input.c management.c output.c text.c

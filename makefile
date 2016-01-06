CC= gcc
CFLAGS= -std=c99 -Wall -g
mainexec: main.c battle.c save.c input.c management.c output.c text.c control.c error.c
	$(CC) $(CFLAGS) -o Magioco main.c battle.c save.c input.c management.c output.c text.c control.c error.c

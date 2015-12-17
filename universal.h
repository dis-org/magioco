#include "struct.h"
#include <stdio.h>

//battle
void battle(void);

//event
void select(short chosen, Choice_List* List); //ritorna il testo scelto
void deleteChoices(Choice_List* List); //svuota una Choice_List
void addChoice(char* text, Choice_List* List); //aggiunge una scelta ad una Choice_List

//input
void press_a(void); //ferma il programma fino a che non si preme 'a'
_Bool choice(short* chosen, short choices); // rende 1 se viene premuto 'a' se effettua un cambiamento al valore chosed o allo stato rende 0

//management
void addAction(Enemy_t* Enemy, char* text, char type, short value);
void addEnemy(char* name, short health, short defence);
void addItem(Item_List* List, char* name, char type, int usev, unsigned short trwv, unsigned short defv, int uses);
Item_t* searchItem(char* id, Item_List* List);

//output
void next_page(); //divide graficamente le varie schermate
void print_intro(); //stampa l'intro del gioco
void print_menu(); //stampa il menù
void print_ahah(); //stampa derisione
void print_quit(); //stampa menù quit
void print_gameover(); //stampa messaggio Game Over
void print_Enemies(); //stampa lista nemici con vita e difesa
void print_Items(); //stampa la lista degli oggetti con durata/quantità
void print_Events(); //choice_t e choice_list
void print_Stats(); //Nome vita e difesa giocatore

//text
void readevent(); //aggiungere evento di uscita
void printtext(FILE*);
void move(char,FILE*);
char* sstring(FILE*,char);
void controle(FILE*,char,char);
void readchoices(FILE*);
void isearch();
void save(); // salva Date_t Local su file save.bin
void load(); // carica i salvataggi (se esistono) e stampa relativo messaggio

#include "struct.h"
#include <stdio.h>

//battle
void battle();
void enemy_Use();
void Trow();
Enemy_t* enemy_sel();  //trova l'enemy_chosen
Item_t* item_sel(); 	//trova l'item_chosen

//input
void switch_state();
void press_a(); //ferma il programma fino a che non si preme 'a'
_Bool choice(short* chosen, short choices); // rende 1 se viene premuto 'a' se effettua un cambiamento al valore chosed o allo stato rende 0
_Bool new_name(); //salva il nome del giocatore controllando che non sia già presente

//management **** rimettere a posto gli argomenti delle funzioni
void addChoice(Choice_List_t* List, char* text); //aggiunge una scelta ad una Choice_List
void select(Choice_List_t* List, char* text, short chosen); //ritorna il testo scelto
void deleteChoices(Choice_List_t* List); //svuota una Choice_List
void addItem(Item_List_t* List, char* name, char type, int usev, unsigned short trwv, unsigned short defv, int uses);
Item_t* searchItem(Item_List_t* List, char* name);
void deleteItem(Item_List_t* List, char* name);
void deleteItems(Item_List_t* List);
void addEnemy(Enemy_List_t* List, char* name, short health);
void addAction(Enemy_t* Enemy, char* text, char type, short value);
Enemy_t* searchEnemy(Enemy_List_t* List, char* name);
void deleteEnemy(Enemy_List_t* List, Enemy_t* Enemy);
void deleteEnemies(Enemy_List_t* List);

//output
void next_page(); //divide graficamente le varie schermate
void print_intro(); //stampa l'intro del gioco *********
void print_menu(); //stampa il menù
void print_ahah(); //stampa derisione **********
void print_quit(); //stampa menù quit
void print_gameover(); //stampa messaggio Game Over
void print_Enemies(); //stampa lista nemici con vita e difesa
void print_Items(); //stampa la lista degli oggetti con durata/quantità
void print_Choices(Choice_List_t* List, short chosen);
void print_Stats(); //Nome vita e difesa giocatore
void print_Uses(); //Possibili utilizzi degli oggetti

//save
void save(); // salva Date_t Local su file save.bin
void load(); // carica i salvataggi (se esistono) e stampa relativo messaggio
void readsaves(); //genera una Choice_List per i file di salvataggio

//text *********** aggiungere descrizione funzioni
void readevent();
void printtext(FILE*);
void move(char,FILE*);
char* sstring(FILE*,char);
void controle(FILE*,char,char);
void readchoices(FILE*);
void isearch(short uses);
void esearch();

#include "struct.h"
#include <stdio.h>

//battle
void battle();
Enemy_t* enemy_sel();    //trova l'enemy_chosen
Item_t* item_sel();      //trova l'item_chosen
void enemy_damage(Enemy_t* Enemy, int damage);
void self_damage(int damage);
void Action();

//input
void switch_state();
_Bool press_a();         //ferma il programma fino a che non si preme 'a'
_Bool choice(short* chosen, short choices);
//rende 1 se viene premuto'a', se effettua un cambiamento al valore chosed o allo stato rende 0
void select(Choice_List_t* List, char* text, short chosen); //ritorna il testo scelto
_Bool new_name();        //salva il nome del giocatore controllando che non sia già presente

//management
Choice_t* addChoice(Choice_List_t* List);  //aggiunge una scelta ad una Choice_List
void deleteChoices(Choice_List_t* List);   //svuota una Choice_List
Item_t* addItem(Item_List_t* List);
Item_t* searchItem(Item_List_t* List, char* name);
void deleteItem(Item_List_t* List, Item_t* Item);
void deleteItems(Item_List_t* List);
Enemy_t* addEnemy(Enemy_List_t* List);
Action_t* addAction(Enemy_t* Enemy);
Enemy_t* searchEnemy(Enemy_List_t* List, char* name);
void deleteEnemy(Enemy_List_t* List, Enemy_t* Enemy);
void deleteEnemies(Enemy_List_t* List);
void deleteActions(Enemy_t* Enemy);

//output
void next_page();       //divide graficamente le varie schermate
void print_intro();     //stampa l'intro del gioco ********* da fare
void print_menu();      //stampa il menù
void print_center();    //stampa un testo centrato
void print_imp();       //stampa impostazioni ********** aggiungere crediti
void print_quit(short* chosen); //stampa menù quit
void print_gameover();  //stampa messaggio Game Over
void print_Choices(Choice_List_t* List, short chosen);//stampa le scelte
void print_name(char* name); //stampa il nome centrato
void print_Enemies();   //stampa lista nemici con vita e difesa
void print_stats();     //Nome vita e difesa giocatore
void print_Items();     //stampa la lista degli oggetti con durata/quantità
void print_Uses(Item_t* Item);  //Possibili utilizzi degli oggetti
void print_sel(Item_t* Item);   //Utilizzo scelto
void print_Action(Enemy_t* Enemy);

//save
void save();            //salva Date_t Local su file save.bin
void load();            //carica i salvataggi (se esistono) e stampa relativo messaggio
void loadChoice(Choice_List_t* List, FILE* pf); //carica una scelta
void readsaves();       //genera una Choice_List per i file di salvataggio
void deletesaves();     //cancella tutti i salvataggi

//text *********** aggiungere descrizione funzioni
void readevent();
void printtext(FILE*);
void move(char,FILE*);
char* sstring(FILE*,char);
void controle(FILE*,char,char,char*);
void readchoices();
void isearch(short,char*);
void esearch(char*);

//Memo:
//aggiungere eventi che fanno perdere o guadagnare vita al giocatore
//ridurre memoria azioni
//aggiungere eventi di scelta che utilizzano oggetti dall'inventario
//testo con riepilogo della partita
//impostazioni per tasti
//risistemare tutti i type :C

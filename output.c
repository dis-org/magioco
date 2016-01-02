#include "universal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CENTER(TEXT) for(int x= (strlen(TEXT)+1)/2; x< width/2-2; x++) printf(" "); printf("%s\n",TEXT);
#define CHOSE(TEXT, SELECTED, WIDTH) for(int x= strlen(TEXT)/2; x< WIDTH/2-4; x++) printf(" "); printf("%c%s%c\n",SELECTED?'[':' ',TEXT,SELECTED?']':' ');

extern Data_t Local;
extern _Bool buffered;
extern short width;

void next_page()
{
  if(buffered)
    {
    }
  else
    system("clear");
}

void print_intro()
{
  CENTER("Magioco");
  puts("");
  CENTER("Premere 'a' per continuare");
  CENTER("Premere 'q' per uscire");
}

void print_menu()
{
  CENTER(" Menù ");
  puts("");
  CENTER("Usare le frecce direzionali");
  CENTER("per muoversi");
  puts("");
  CHOSE("Continua",Local.chosen==1,width);
  CHOSE("Nuova partita",Local.chosen==2,width);
  CHOSE("Imp. grafiche",Local.chosen==3,width);
  CHOSE("Elimina salv.",Local.chosen==4,width);
}

void print_center(char* text)
{
  CENTER(text);
}

void print_imp()
{
  CENTER("Impostazioni");
  puts("");
  CENTER("Usare le frecce direzionali");
  CENTER("per cambiare la larghezza");
  puts("");
  CENTER("Premere 'a' per salvare");
  CENTER("Premere 'q' per default");
  puts("");
  for(int x=0; x<width; x++)
    printf("*");
  puts("");
}

void print_quit(short* chosen)
{
  CENTER("Quit Menù");
  puts("");
  CENTER("Premere 'q' per annullare");
  puts("");
  CHOSE("Salva",*chosen==1,width);
  CHOSE("Menù",*chosen==2,width);
  CHOSE("Esci",*chosen==3,width);
}

void print_gameover()
{
  CENTER("Game Over");
  puts("");
  CENTER("Premere 'q' per uscire");
  CENTER("Premere 'a' per continuare");
}

void print_Choices(Choice_List_t* List, short chosen)
{
  CENTER(List->text);
  puts("");
  Choice_t* Temp= List->First; 
  for(int x= 1; x <= List->choices; x++)
    {
      CHOSE(Temp->text,x==chosen,width);
      Temp= Temp->Next;
    }
}

void print_name(char* name)
{
  CENTER("Nome");
  puts("");
  CENTER(name);
  puts("");
  CENTER("Premere '.' per confermare");
  CENTER("Premere '-' per cancellare");  
}

void print_Enemies()
{ 
  Enemy_t* Enemy= Local.Battle.First;
  for (int x=1; x<=Local.Battle.enemies; x++)
    {
      CHOSE(Enemy->Info.name, Local.enemy_chosen==x, 0);
      printf("HP ");
      for (int y=0; y<Enemy->Info.health; y++)
        printf("*");
      for (int z=0; z<Enemy->Info.defence; z++)
        printf(")");
      puts("\n");
      Enemy= Enemy->Next;
    }
}

void print_stats()
{
  for(int x= strlen(Local.name)+2; x < width; x++)
    printf(" ");
  CHOSE(Local.name, Local.enemy_chosen==Local.Battle.enemies+1, 0);
  for(int x= 3+Local.health+Local.defence; x< width; x++)
    printf(" ");
  for(int y=0; y<Local.defence; y++)
    printf("(");
  for (int x=0; x<Local.health; x++)
    printf("*");
  printf(" HP");
  puts("\n");
}

void print_Items()      //solo nome 
{ 
  Item_t* Tmp= Local.Bag.First;
  puts("Scegli:");
  for(int x= 1; x <= Local.Bag.items; x++)
    {
      for(int x= strlen(Tmp->Info.name)/2; x< width/2-7; x++) 
	printf(" "); 
      printf("%c%s%c  %s: %d\n"
	     , Local.item_chosen==x?'[':' '
	     , Tmp->Info.name
	     , Local.item_chosen==x?']':' '
	     , Tmp->Info.type=='u' ? "res" : "qnt"
	     , Tmp->Info.uses
	     );
      Tmp= Tmp->Next;
    }
}

void print_Uses(Item_t* Item)
{
  printf("Scelto:");
  CHOSE(Item->Info.name,0,(width-12));
  puts("");
  CHOSE(">> Usa <<",Local.use_chosen==1,width);
  CHOSE("<< Lancia",Local.use_chosen==2,width);
  CHOSE("(( Blocca",Local.use_chosen==3,width);
}

void print_sel(Item_t* Item)
{
  printf("%s", Local.use_chosen==1? ">> Usa <<": "<< Lancia");
  CHOSE(Item->Info.name,0,(width-16));
}

void print_Action(Enemy_t* Enemy)
{
  Action_t* A= Enemy->First;
  printf("%s: %s\n", Enemy->Info.name, A->Info.text);
  if(A->Info.type=='m' && Local.ranged)
      printf("%s è fuori portata\n", Local.name);
  if(A->Info.type!='d' && Local.defending)
    printf("%s blocca con %s\n", Local.name, Local.Defending.name);

}

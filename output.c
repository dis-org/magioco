#include "universal.h"
#include <stdio.h>
#include <stdlib.h>

extern Data_t Local;
extern _Bool buffered;

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
  printf(
         "                           Magioco\n\n"
         "                  Premere 'a' per continuare.\n"
         );
}

void print_menu()
{
  printf(
         "                            Menù\n\n"
         "                  Usare le frecce direzionali\n"
         "                        per muoversi.\n\n"
         "                         %cContinua%c\n"
         "                       %cNuova partita%c\n"
         "                       %cImp. grafiche%c\n",
         Local.chosen==1?'[':' ',Local.chosen==1?']':' ',
         Local.chosen==2?'[':' ',Local.chosen==2?']':' ',
         Local.chosen==3?'[':' ',Local.chosen==3?']':' '
         );
}

void print_ahah()
{
  puts(  "                 AHAHAHAHAHAHAHHAHAHAHAHAHAH");
}

void print_quit()
{
  printf(
         "                            Quit\n\n"
         "                  Premere 'q' per continuare.\n\n"
         "                           %cSalva%c\n"
         "                           %cMenù%c\n"
         "                           %cEsci%c\n",
         Local.chosen==1?'[':' ',Local.chosen==1?']':' ',
         Local.chosen==2?'[':' ',Local.chosen==2?']':' ',
         Local.chosen==3?'[':' ',Local.chosen==3?']':' '
         );
}

void print_gameover()
{
  printf(
         "                          Game Over\n\n"
         "                    Premere 'q' per uscire.\n"
         "                 Premere 'a' per tornare al menù.\n"
         );
}

void print_Enemies()
{ 
  for (int x=0; x<Local.Battle.enemies; x++)
    {
      printf("%c %s\nHp: ",x==Local.enemy_chosen? '[':' ', Local.Battle.First->name);
      for (int y=0; y<Local.Battle.First->health; y++)
        printf("*");
      for (int z=0; z<Local.Battle.First->defence; z++)
        printf(")");
      printf("%c\n", x==Local.enemy_chosen? ']':' ');
    }
}
 

void print_Items()      //solo nome 
{ 
  Item_t* Tmp= Local.Bag.First; 
  for(int x= 1; x <= Local.Bag.items; x++)
    {
      printf("%c %s (%s: %d)\n", 
        x==Local.item_chosen? '>' : ' ',  
        Tmp->name, 
        Local.Bag.First->type=='u' ? "res" : "qnt", 
        Loca.Bag.First->uses);
      Tmp= Tmp->Next;
    }
}

void print_Choices(short chosen, Choice_List* List)
{
  printf("%s\n", List->text);
  Choice_t* Temp= List->First; 
  for(int x= 1; x <= List->choices; x++)
    {
      printf("%c %s\n", x==chosen? '>' : ' ', Temp->text);
      Temp= Temp->Next;
    }
}

void print_Stats()
{
  printf("%s:\tHp: ", Local.name);
  for (int x=0; x<Local.health; x++)
    printf("*");
  for(int y=0; y<Local.defence; y++)
    printf(")");
  puts("");
}

void print_Uses()
{
  printf(
         "%s (%s: %d)\n\n"
         "%cUsa su %s%c\n"
         "%cUsa sul nemico%c\n"
         "%cScaglia contro il nemico%c\n"
         "%cDifenditi%c\n"
         "%cTorna all'inventario%c\n",
         Local.Bag.First->name, Local.Bag.First->type=='u' ? "res" : "qnt", Loca.Bag.First->uses,
         Local.use_chosen==1?'[':' ', Local.name ,Local.use_chosen==1?']':' ',
         Local.use_chosen==2?'[':' ', Local.use_chosen==2?']':' ',
         Local.use_chosen==3?'[':' ', Local.use_chosen==3?']':' ',
         Local.use_chosen==4?'[':' ', Local.use_chosen==4?']':' ',
         Local.use_chosen==5?'[':' ', Local.use_chosen==5?']':' ');
}

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
      printf("%c %s\n", x==Local.item_chosen? '>' : ' ',  Tmp->name);
      Tmp= Tmp->Next;
    }
}

void print_Events()
{
  printf("%s\n", Local.Events.text);
  Choice_t* Temp= Local.Events.First; 
  for(int x= 1; x <= Local.Events.choices; x++)
    {
      printf("%c %s\n", x==Local.chosen? '>' : ' ', Temp->text);
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

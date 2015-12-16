#include "union.h"
#include <stdio.h>

extern Data_t Local;

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
      printf("%c %s\n", x==Local.event_chosen? '>' : ' ', Temp->text);
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

#include "union.h"
#include <stdio.h>

extern Data_t Local;

void print_Enemies()
{ 
  for (int x=0; x<Battle.enemies; x++)
    {
      printf("%c %s\nHp: ",x==enemy_chosen? '[':' ', Battle.First->name);
      for (int y=0; y<Battle.First->health; y++)
      	  printf("*");
      for (int z=0; z<Battle.First->defence; z++)
          printf(")");
      printf("%c\n", x==enemy_chosen? ']':' ');
    }
}
 

void print_Items()      //solo nome 
{ 
  Item_t* Tmp= Bag.First; 
  for(int x= 1; x <= Bag.items; x++)
    {
      printf("%c %s\n", x==item_chosen? '>' : ' ',  Tmp->name);
      Tmp= Tmp->Next;
    }
}

void print_Events()
{
  printf("%s\n", Events.text);
  Choice_t* Temp= Events.First; 
  for(int x= 1; x <= Events.choices; x++)
    {
      printf("%c %s\n", x==event_chosen? '>' : ' ', Temp->text);
      Temp= Temp->Next;
    }
}

void print_Stat ()
{
	printf("Player: %s\tHp: ", name);
	for (int x=0; x<health; x++)
    	printf("*");
	for(int y=0; y<defence; y++)
    	printf(")");
	puts("");
}

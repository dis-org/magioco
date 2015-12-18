#include "universal.h"
#include <stdio.h>

extern Data_t Local;

void battle(void)
{
  print_Enemies();
  print_Stats();
  switch(Local.phase)
    {
    case'i':
      print_Items();
      if(choice(&Local.item_chosen, Local.Bag.items))
	Local.phase='u';
    case 'u':
      print_Uses();
      if (choice(&Local.use_chosen, 5)) //percepisco che è sbagliata, 
	switch(Local.use_chosen)
	  {
	  case 1: //usa su di te
            Local.health += Local.Bag.First->usevalue;
            break;
          case 2: //usa su nemico
            enemy_Use();
            
            break;
          case 3: //lancia
            Trow();
            
            break;
          case 4: //difenditi
            Defend();
            
            break;
          case 5: //inventario
            break;  
	  }
      Local.phase= Local.use_chosen==5 ? 'i':'a';
    case 'a':
      break;
    }
}


void enemy_Use()
{
	
}

void Trow()
{
}

void Defend()
{
}

#include "universal.h"
#include <stdio.h>

extern Data_t Local;

char battle(void)
{
  print_Enemies();
  print_Stats();
  switch(Local.phase)
    {
    case'i':
      print_Items();
      if(choice(&Local.item_chosen, Local.Bag.items))
	  return Local.phase='u';
	case 'u':
	  print_Uses();
	  if (choice(&Local.use_chosen, 5)) //percepisco che è sbagliata, 
		switch(Local.use_chosen)
        {
          case 1: //usa su di te
            me_Use ()
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
      Local.use_chosen==5 ? return Local.phase='i', return Local.phase='a';
    case 'a':



    }
}


Enemy_List enemy_Use()
{
	
}

Enemy_List Trow()
{
}

unsigned short Defend()
{
}
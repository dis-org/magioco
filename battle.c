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
        Local.phase= 'u';
    }
}

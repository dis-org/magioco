#include "union.h"
#include <string.h>
#include <stdlib.h>

Data_t Local;
_Bool buffered;

int main()
{
  //Inizializzazione
  
  _Bool on= 1;
  strcpy(Local.id,"Intro");
  Local.state='t';
  Local.event_chosen= 1;
  Local.enemy_chosen= 0;
  Local.item_chosen= 1;
  Local.phase='i';

  while(on)
    {
      //Controllo
      //vita
      system("clear"); //da spostare su una funzione di output

      if(Local.Battle.enemies)
        Local.state= 'b';

      switch(Local.state)
        {
        case't':
          readevent();
          press_a();
          continue;
        case'c':
          print_Events();
          if(choice(&Local.event_chosen, Local.Events.choices))
            {
              select(Local.event_chosen, &Local.Events);
              Local.event_chosen= 1;
            }
          continue;
        case'b':
          print_Enemies();
          print_Stat();
          switch(Local.phase)
            {
            case'i':
              print_Items();
              if(choice(&Local.item_chosen, Local.Bag.items))
                Local.phase= 'u';
              continue;
            }
        case'q':
          on=0;
        }
    }
  return 0;
}

#include "universal.h"
#include <string.h>
#include <stdlib.h>

Data_t Local;
_Bool buffered;

int main()
{
  _Bool on= 1;

  Local.state='i';
  Local.chosen= 1;

  next_page();
  print_intro();
  press_a();

  while(on)
    {
      //Controllo
      //vita
      next_page();

      if(Local.Battle.enemies)
        Local.state='b';

      switch(Local.state)
        {
        case'i':
          print_menu();
          if(choice(&Local.chosen, 3))
            switch(Local.chosen)
              {
              case 1:
                next_page();
                load();
                press_a();
                continue;
              case 2:
                // inizzializzazione nuova partita
                strcpy(Local.id,"Start");
                Local.enemy_chosen= 0;
                Local.item_chosen= 1;
                Local.phase='i';
                Local.state='t';
                continue;
              case 3:
                next_page();
                print_ahah();
                press_a();
                continue;
              }
          else
            continue;
        case't':
          readevent();
          press_a();
          continue;
        case'c':
          print_Events();
          if(choice(&Local.chosen, Local.Events.choices))
            {
              select(Local.chosen, &Local.Events);
              Local.chosen= 1;
            }
          continue;
        case'b':
	  battle();
	  continue;            
        case'q': //aggiungere menù salvataggio e schermata game over
          on=0;
        }
    }
  return 0;
}

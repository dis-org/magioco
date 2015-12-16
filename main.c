#include "universal.h"
#include <string.h>
#include <stdlib.h>

Data_t Local;
_Bool buffered;

int main()
{
  _Bool on= 1;

  Local.state='m';
  Local.previus='q';
  Local.chosen= 1;
  Local.health= 3;

  next_page();
  print_intro();
  press_a();

  while(on)
    {
      next_page();

      //Controllo
      if(!Local.health)
	Local.state='g';

      if(Local.Battle.enemies)
        Local.state='b';

      switch(Local.state)
        {
        case'm':
          print_menu();
          if(choice(&Local.chosen, 3))
            switch(Local.chosen)
              {
              case 1:
                next_page();
                load();
		Local.chosen= 1;
                press_a();
                continue;
              case 2:
                // inizzializzazione nuova partita
                strcpy(Local.id,"Start");
                Local.enemy_chosen= 0;
                Local.item_chosen= 1;
		Local.chosen= 1;
                Local.phase='i';
                Local.state='t';
                continue;
              case 3:
                next_page();
                print_ahah();
		Local.chosen= 1;
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
              select(Local.id, Local.chosen, &Local.Events);
              Local.state='t';
              Local.chosen= 1;
            }
          continue;
        case'b':
	  battle();
	  continue;
	case'g':
	  print_gameover();
	  press_a();
	  if(Local.state=='q')
	    on=0;
	  else
	    Local.state='m';
	  continue;
        case'q': //aggiungere menù salvataggio e schermata game over
	  print_quit();
	  if(choice(&Local.chosen, 3))
	    switch(Local.chosen)
	      {
	      case 1:
		save();//da decidere
		Local.chosen= 1; //rivedili tutti
                press_a();
		continue;
	      case 2:;
		Local.state='m';
		Local.previus='q';
		continue;
	      case 3:
		on= 0;
		continue;
	      }
        }
    }
  next_page();
  return 0;
}

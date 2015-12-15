#include <string.h>
#include <stdlib.h>
#include "input.h"
#include "text.h"
#include "event.h"
#include "output.h"

int main()
{
  //Inizilizzazione
  
  state='t';
  _Bool on= 1;
  event_chosen= 1;
  strcpy(id,"Intro");
  enemy_chosen= 0;
  item_chosen= 1;
  phase='i';

  while(on)
    {
      //Controllo
      //vita
      system("clear"); //da spostare su una funzione di output

      if(Battle.enemies)
        state= 'b';

      switch(state)
        {
        case't':
          readevent();
          press_a();
          continue;
        case'c':
          print_Events();
          if(choice(&event_chosen, Events.choices))
	    {
	      select(event_chosen, &Events);
	      event_chosen= 1;
	    }
	  continue;
        case'b':
          print_Enemies();
         // print_Stat();
          switch(phase)
            {
            case'i':
              print_Items();
              if(choice(&item_chosen, Bag.items))
                phase= 'u';
              continue;
            }
          return 0;
        }
    }
}

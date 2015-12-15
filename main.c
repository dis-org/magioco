#include <string.h>
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

  while(on)
    {
      //Controllo
      //vita

      if(Battle.enemies)
      	state= 'b';

      switch(state)
        {
        case't':
          readevent();
	  puts("lol");
          press_a();
          continue;
        case'c':
	  print_Events();
          if(choice(&event_chosen, Events.choices))
	    select(event_chosen, &Events);
	  else
	    continue;
	/* case'b': */
	/*   print_Enemies(); */
	/*   switch(phase); */

	}
    }
  return 0;
}

#include <string.h>
#include "input.h"
#include "text.h"
#include "event.h"

#include <stdio.h> //temp

int main(int argc, char* argv[])
{
  //Inizilizzazione
  
  state='t';
  _Bool on= 1;
  event_chosen= 1;
  strcpy(id,"Devi sceglere tra queste cose");

  printf("%s\n", id);// temp

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
          press_a();
          continue;
        case'c':
	  print_Choices();
          if(choice(&event_chosen, Events.choices))
              select(event_chosen, &Events);
	  else
	    continue;
	case'b':
	  print_Enemies();
	  switch(phase)
	    {
	    

	  if()
	    print_Items;
	  else
	    
	case
        }
    }
}

#include <string.h>
#include "input.h"
#include "text.h"
#include "event.h"

#include <stdio.h> //temp

int main(int argc, char* argv[])
{
  //inizilizzazione
  
  state='t';
  _Bool on= 1;
  event_chosen= 1;
  strcpy(id,"Devi sceglere tra queste cose");

  printf("%s\n", id);// temp

  while(on)
    {
      switch(state)
        {
        case't':
          readevent(id); //da rivedere---> programma unico??
          /* if(state=='c') */
          /*   read_choice(id); */
          press_a();
          continue;
        case'c':
          if(choice(&event_chosen, Events.choices))
            {
              select(event_chosen, &Events);
            }
          continue;
        }
    }
}

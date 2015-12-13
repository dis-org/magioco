#include "var.h"
#include "input.h"

int main(int argc, char* argv[])
{
  //inizilizzazione
  
  state='t';
  _Bool on= 1;
  event_chosed= 1;
  while(on)
    {
      switch(state)
        {
        case't':
          read_event(id); //da migliorare---> programma unico??
          if(state=='c')
            read_choice(id);
          press_a();
          continue;
        case'c':
          if(choice(&event_chosed, Events.choices))
            {
              select(event_chosed, Events);
            }
          continue;
        }
    }
}

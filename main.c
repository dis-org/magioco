#include "var.h"
#include "input.h"

int main(int argc, char* argv[])
{
  //inizilizzazione
  
  state='t';
  _Bool on= 1;
  chosed= 1;
  while(on)
    {
      switch(state)
        {
        case't':
          read_event(id);
          if(state=='c')
            read_choice(id);
          press_a();
          continue;
        case'c':
          if(choice(chosed,events))
            {
              select(Choice_list);
            }
          continue;
        case'q':
        case'b':
        }
    }
}

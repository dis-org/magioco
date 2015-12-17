#include "universal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern Data_t Local;
extern char buffered;

void press_a(void) 
{
  if(buffered)
    {
    }
  else
    {
      char in;
      system("/bin/stty raw");
      while(1) //loop infinito
        {
          in= getchar();
          printf("\r        \r");
          if(in=='a')
            break; //esce dal loop se digito 'a'
          if(in=='q')
            {
	      char temp= Local.state;
              Local.state= Local.previous;
	      Local.previous= temp;
              break;
            }
        }
      system("/bin/stty cooked");
    }
}
//dovrebbe essere l'ultima funzione chiamata prima di rivalutare il loop

_Bool choice(short* chosen, short choices)
{
  if(buffered)
    {
      return 0;
    }
  else
    {
      _Bool ret;
      char in;
      system("/bin/stty raw");
      while(1)
        {
          in= getchar();
          printf("\r        \r");
          if(in=='q')
            {
	      char temp= Local.state;
              Local.state= Local.previous;
	      Local.previous= temp;
              *chosen= 1;
              break;
            }
          if(in=='a')
            break;
          if(in=='A' && *chosen>1)
            {
              *chosen-= 1;
              break;
            }
          if(in=='B' && *chosen<choices)
            {
              *chosen+= 1;
              break;
            }
        }
      system("/bin/stty cooked");
      ret= in=='a'? 1: 0;
      return ret;
    }
}

_Bool new_name()
{
  if(
}

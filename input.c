#include <stdio.h>
#include <stdlib.h>
#include "var.h"

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
              state='q'; //anche se digito q ma prima cambia lo stato
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
              state='q';
              *chosen= 1;
              break;
            }
          if(in=='a')
            break;
          if(in=='A' && *chosen>1)
            {
              *chosen--;
              break;
            }
          if(in=='B' && *chosen<choices)
            {
              *chosen++;
              break;
            }
        }
      system("/bin/stty cooked");
      ret= in=='a'? 1: 0;
      return ret;
    }
}

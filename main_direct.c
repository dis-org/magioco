#include <stdio.h>
#include <stdlib.h>
#include "library.h"

//---elementi di prova---
Event_t Prova={ 10, "Questa è una prova", 3, {"fai questo", "oppure questo", "no, questo no"} };

Event_t Quit={ 0, "Uscire dal gioco?", 2, {"Yep", "Nope"} };
//---

int main()
{
  _Bool on= 1;
  char in= 'a';
  unsigned int chosed= 1;
  Event_t Current= Prova;
  //inventory enabler
  Event_t Previus;

  while(on)
    {
      system ("clear");
      printf("%s\n", Current.text);
      for(int x= 1; x <= Current.choices; x++)
	printf("%c%u%c %s\n", x==chosed?'[':' ', x, x==chosed?']':' ',
	       Current.choice_text[x-1] );

      system ("/bin/stty raw");
      while(1)
	{
	  in= getchar();
	  printf("\r          \r");

	  if(in=='q')
	    {
	      //quit
	      break;
	    }
	  if(in=='a')
	    {
	      //execute
	      break;
	    }
	  if(in=='A' && chosed>1)
	    {
	      chosed--;
	      break;
	    }
	  if(in=='B' && chosed<Current.choices)
	    {
	      chosed++;
	      break;
	    }
	}
      system ("/bin/stty cooked");
    }

}

#include <stdio.h>
#include <stdlib.h>
#include "library.h"

//---elementi di prova---
Event_t Fine={ 111, 'e', "", "fine prova"};

Event_t Prova3={ 13, 't', "no, questo no", "ecco l'hai rotto", 1, &Fine};
Event_t Prova2={ 12, 't',"oppure questo", "bravissimo", 2, &Prova3};
Event_t Prova1={ 11, 't',"fai questo", "bravo", 3, &Prova2};
Event_t Prova={ 10, 'c',"se leggi questo c'è un errore", "Questa è una prova", 3, &Prova1};

//---

int main()
{
  _Bool on= 1;
  char in;
  unsigned int chosen= 1;
  Event_t Current= Prova;
  Event_t Previous;
  Event_t* Temp;
  
  Event_t QuitY={ 2, 'e', "Yep","Bye", 1, &Previous};
  Event_t QuitN={ 1, 'b', "Nope","riprendi", 2, &QuitY};
  Event_t Quit={ 0, 'c', "errore", "Uscire dal gioco?", 2, &QuitN};
  //inventory enabler

  while(1)
    {
      system ("clear");
      printf("%s\n", Current.text);
      if(Current.type=='e')
	break;
      if(Current.type=='c')
	{
	  if(Current.id)
	    Previous= Current;
	  for(int x= 1; x <= Current.range; x++)
	    {
	      Temp= Current.Next;
	      for(int z= 1; z < x; z++)
		Temp= Temp->Next;
	      printf("%c%u%c %s\n", x==chosen?'[':' ', x, x==chosen?']':' ',Temp->choice_text );
	    }
	}
      else
	chosen= Current.range;

      system ("/bin/stty raw");
      while(1)
	{
	  in= getchar();
	  printf("\r          \r");

	  if(in=='q')
	    {
	      Current= Quit;
	      chosen= 1;
	      break;
	    }
	  if(in=='a')
	    {
	      Temp= Current.Next;
	      for(int x= 1; x < chosen; x++)
		Temp= Temp->Next;
	      Current= *Temp;
	      chosen= 1;
	      break;
	    }
	  if(in=='A' && chosen>1 && Current.type=='c')
	    {
	      chosen--;
	      break;
	    }
	  if(in=='B' && chosen<Current.range && Current.type=='c')
	    {
	      chosen++;
	      break;
	    }
	}
      system ("/bin/stty cooked");
    }
}

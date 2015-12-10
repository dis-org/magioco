#include "library.h"

char unbuffered(void)
{
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

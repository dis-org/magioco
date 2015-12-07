#include <stdio.h>
#include "library.h"

int main(int argc, char* argv[])
{
  _Bool direct= 1;
  _Bool on= 1;
  unsigned int state= 1;
  char n;

  if(argc-1)
    if(argv[1][0]=='E')
      direct= 0;

  if(direct)
    system ("clear");
  else
    puts("-----------------------------------------------------------------");
  puts("\t\t\t[q]: esci [m]: inventario");

  while(on)
    {
      if(direct)
	system ("/bin/stty raw");
      while(n= getchar())
	{
	  if(direct)
	    printf("\r                          \r");
	  if(n=='q')
	    {
	      state= 0;
	      break;
	    }
	  if(n>='1' && n<='3')
	    {
	      state= 1;
	      break;
	    }
	  if(n=='m')
	    {
	      state= 2;
	      break;
	    }
	}
      if(direct)
	system ("/bin/stty cooked");

      if(direct)
	system ("clear");
      else
	puts("-----------------------------------------------------------------");

      switch(state)
	{
	case 0:
	  printf("Uscire dal gioco? (y/n): ");
	  if(scanf(" %c", &n) && n=='y')
	    {
	      on= 0;
	      continue;
	    }
	  break;
	case 1:
	  //event_reader
	  puts("nope");
	  break;
	case 2:
	  //inventory
	  puts("nada");
	  break;
	}
    }
}

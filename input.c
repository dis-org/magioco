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

  _Bool existent= 0;
  char* txt;
  FILE* pf;
  printf(
	 "                             Nome\n\n"
	 "                           "
	 );
  if(buffered)
    {
    }
  else
    {
      system("/bin/stty raw");
      scanf("%s", Local.name);
      system("/bin/stty cooked");
    }
  next_page();
  pf= fopen("saves/saves.txt","a+");
  if(!pf)
    {
      fprintf(stderr,"Errore: impossibile aprire saves.txt (new_name)\n");
      exit(EXIT_FAILURE);
    }
  while(getc(pf)!=EOF)
    {
      txt= sstring(pf,'\n');
      if(!strcmp(txt, Local.name))
	{
	  existent= 1;
	  break;
	}
      free(txt);
    }
  if(existent || Local.name[0]==' ')
    {
      printf("\n                        già utilizzato.\n");
      return 0;
    }
  fprintf(pf, "#%s\n", Local.name);
  fclose(pf);
  return 1;
}

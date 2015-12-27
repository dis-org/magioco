#include "universal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern Data_t Local;
extern char buffered;
extern short quit_chosen;

void switch_state()
{
  char temp= Local.state;
  Local.state= Local.previous;
  Local.previous= temp;
}

_Bool press_a() 
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
      while(1) //loop infinito
        {
          in= getchar();
          printf("\r        \r");
          if(in=='a')
            break; //esce dal loop se digito 'a'
          if(in=='q')
            {
	      quit_chosen= 1;
              switch_state();
              break;
            }
        }
      system("/bin/stty cooked");
      ret= in=='a'? 1: 0;
      return ret;
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
	      quit_chosen= 1;
              switch_state();
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
  char* name= calloc(32,sizeof(char));
  int n= 0;
  char c;
  while(!buffered)
    {
      system("clear");
      printf("                             Nome\n\n               ");
      for(int x= 16-(n)/2; x>0; --x)
        printf(" ");
      printf("%s\n\n"
             "                  Premere '.' per confermare.\n"
             "                  Premere '-' per cancellare.\n"
             , name);
      system("/bin/stty raw");
      while((c=getchar()))
        {
          if(((c <='z' && c>='a')||(c<='Z' && c>='A'))&& n<31)
            name[n++]= c;
          if(c=='-' && n)
            n--;
          break;
        }
      name[n]='\0';
      system("/bin/stty cooked");
      if(c=='.')
        break;
      continue;
    }
  printf("\r        \r");
  if(!n && !buffered)
    {
      puts("Annullato.");
      return 0;
    }
  strcpy(Local.name,name);
  free(name);
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
      puts("Nome già utilizzato.");
      return 0;
    }
  fprintf(pf, "#%s\n", Local.name);
  fclose(pf);
  return 1;
}

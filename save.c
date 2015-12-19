#include "universal.h"
#include <stdlib.h>
#include <string.h>

void save()
{
  FILE *pf;
  char a[64]="saves/";
  strcat(a,Local.name);
  strcat(a,".bin");
  pf=fopen(a,"wb");
  if(!pf)
    {
      fprintf(stderr,"Errore: salvataggio fallito (save)");
      exit(EXIT_FAILURE);
    }
  fwrite(&Local,sizeof(Data_t),1,pf);
  puts("Partita salvata.");
  fclose(pf);
}

void load()
{
  FILE *pf;
  char a[64]="saves/";
  strcat(a,Local.name);
  strcat(a,".bin");
  pf=fopen(a,"rb");
  if (!pf){ 
    fprintf(stderr,"Errore: caricamento fallito (load).\n");
    exit(EXIT_FAILURE);
  }
  fread(&Local,sizeof(Data_t),1,pf);
  fclose(pf);
}

void readsaves()
{
  FILE* pf;
  char* name;
  pf=fopen("saves/saves.txt","a+");
  if(!pf)
    {
      fprintf(stderr,"Errore: caricamento fallito (readsaves).\n");
      exit(EXIT_FAILURE);
    }
  rewind(pf);
  deleteChoices(&Local.Events);
  while(getc(pf)=='#')
    {
      name= sstring(pf,'\n');
      addChoice(name, &Local.Events);
      free(name);
    }
  if(Local.Events.choices)
    strcpy(Local.Events.text,"Selezionare salvataggio:");
  else
    strcpy(Local.Events.text,"Nessun salvataggio presente.");
  fclose(pf);
}

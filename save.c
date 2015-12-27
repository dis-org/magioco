#include "universal.h"
#include <stdlib.h>
#include <string.h>

extern Data_t Local;

void save()
{
  FILE *pf;
  char a[64]="saves/";
  strcat(a,Local.name);
  strcat(a,".bin");
  pf=fopen(a,"wb");
  if(!pf)
    {
      fprintf(stderr,"Errore: impossibile aprire %s\n",a);
      exit(EXIT_FAILURE);
    }
  fwrite(&Local,sizeof(Data_t),1,pf);
  if(Local.Bag.items)
    fwrite(&Local.Bag.First->Info,sizeof(Item_Data_t),1,pf);
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
  if (!pf)
    { 
      fprintf(stderr,"Errore: impossibile aprire %s\n",a);
      exit(EXIT_FAILURE);
    }
  fread(&Local,sizeof(Data_t),1,pf);
  if(Local.Bag.items)
    fread(&Local.Bag.First->Info,sizeof(Item_Data_t),1,pf);
  fclose(pf);
}

void readsaves()
{
  FILE* pf;
  char* name;
  pf=fopen("saves/saves.txt","a+");
  if(!pf)
    {
      fprintf(stderr,"Errore: impossibile aprire la cartella \"saves\"\n");
      exit(EXIT_FAILURE);
    }
  rewind(pf);
  while(getc(pf)=='#')
    {
      name= sstring(pf,'\n');
      addChoice(&Local.Events, name);
      free(name);
    }
  if(Local.Events.choices)
    strcpy(Local.Events.text,"Selezionare salvataggio:");
  else
    strcpy(Local.Events.text,"Nessun salvataggio presente.");
  fclose(pf);
}

void deletesaves()
{
  FILE* pf;
  char* name;
  char a[64];
  pf=fopen("saves/saves.txt","a+");
  if(!pf)
    {
      fprintf(stderr,"Errore: impossibile aprire la cartella \"saves\"\n");
      exit(EXIT_FAILURE);
    }
  rewind(pf);
  while(getc(pf)=='#')
    {
      name= sstring(pf,'\n');
      strcpy(a,"saves/");
      strcat(a, name);
      free(name);
      strcat(a,".bin");
      remove(a);
    }
  fclose(pf);
  remove("saves/saves.txt");
  puts("Salvataggi rimossi.");
}

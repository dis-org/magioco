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
  Choice_t* C= Local.Events.First;
  for(int x= 0; x<Local.Events.choices; x++)
    {
      fwrite(C->text,sizeof(char),128,pf);
      C= C->Next;
    }
  Item_t* I= Local.Bag.First;
  for(int x= 0; x<Local.Bag.items; x++)
    {
      fwrite(&I->Info,sizeof(Item_Data_t),1,pf);
      I= I->Next;
    }
  Enemy_t* E= Local.Battle.First;
  for(int x= 0; x<Local.Battle.enemies; x++)
    {
      fwrite(&E->Info,sizeof(Enemy_Data_t),1,pf);
      E= E->Next;
    }
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
  Local.Events.First= Local.Events.Last= NULL;
  Local.Bag.First= Local.Bag.Last= NULL;
  Local.Battle.First= Local.Battle.Last= NULL;
  for(int x= 0; x<Local.Events.choices; x++)
    {
      addChoice(&Local.Events,"");
      fread(&Local.Events.Last->text,sizeof(char),128,pf);
      Local.Events.choices-= 1;
    }
  for(int x= 0; x<Local.Bag.items; x++)
    {
      addItem(&Local.Bag,"",'\0',0,0,0,0);
      fread(&Local.Bag.Last->Info,sizeof(Item_Data_t),1,pf);
      Local.Bag.items-= 1;
    }
  for(int x= 0; x<Local.Battle.enemies; x++)
    {
      addEnemy(&Local.Battle,"",0,0);
      fread(&Local.Battle.Last->Info,sizeof(Enemy_Data_t),1,pf);
      Local.Battle.enemies-= 1;
    }
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

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
  for(int x= 0; x<Local.Events.choices; x++)
    {
      Choice_t* Temp= Local.Events.First;
      fwrite(&Temp->text,sizeof(char),128,pf);
      Temp= Temp->Next;
    }
  for(int x= 0; x<Local.Bag.items; x++)
    {
      Item_t* Temp= Local.Bag.First;
      fwrite(&Temp->Info,sizeof(Item_Data_t),1,pf);
      Temp= Temp->Next;
    }
  for(int x= 0; x<Local.Battle.enemies; x++)
    {
      Enemy_t* Temp= Local.Battle.First;
      fwrite(&Temp->Info,sizeof(Enemy_Data_t),1,pf);
      Temp= Temp->Next;
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
  for(int x= 0; x<Local.Events.choices; x++)
    {
      addChoice(&Local.Events,"");
      fread(&Local.Events.Last->text,sizeof(char),128,pf);
    }
  for(int x= 0; x<Local.Bag.items; x++)
    {
      addItem(&Local.Bag,"",'\0',0,0,0,0);
      fread(&Local.Bag.Last->Info,sizeof(Item_Data_t),1,pf);
    }
  for(int x= 0; x<Local.Battle.enemies; x++)
    {
      addEnemy(&Local.Battle,"",0);
      fread(&Local.Bag.Last->Info,sizeof(Enemy_Data_t),1,pf);
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
  deleteChoices(&Local.Events);
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

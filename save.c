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
      fwrite(Temp,sizeof(Choice_t),1,pf);
      Temp= Temp->Next;
    }
  for(int x= 0; x<Local.Bag.items; x++)
    {
      Item_t* Temp= Local.Bag.First;
      fwrite(Temp,sizeof(Item_t),1,pf);
      Temp= Temp->Next;
    }
  /* for(int x= 0; x<Local.Events.choices) */
  /*   { */
  /*     Enemy_t* Temp= Events.First; */
  /*     fwrite(Temp,sizeof(Choice_t),1,pf); */
  /*     Temp= Temp->Next; */
  /*   } */
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
  Local.Events.First=NULL;
  Local.Events.Last=NULL;
  for(int x= 0; x<Local.Events.choices; x++)
    {
      addChoice("",&Local.Events);
      Choice_t* Temp= Local.Events.First;
      fwrite(Temp,sizeof(Choice_t),1,pf);
      Temp= Temp->Next;
    }
  for(int x= 0; x<Local.Bag.items; x++)
    {
      addItem(&Local.Bag,'\0','\0',0,0,0,0);
      Item_t* Temp= Local.Bag.First;
      fwrite(Temp,sizeof(Item_t),1,pf);
      Temp= Temp->Next;
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
      addChoice(name, &Local.Events);
      free(name);
    }
  if(Local.Events.choices)
    strcpy(Local.Events.text,"Selezionare salvataggio:");
  else
    strcpy(Local.Events.text,"Nessun salvataggio presente.");
  fclose(pf);
}

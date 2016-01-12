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
    fopen_error(__func__);
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
  I= Local.Ground.First;
  for(int x= 0; x<Local.Ground.items; x++)
    {
      fwrite(&I->Info,sizeof(Item_Data_t),1,pf);
      I= I->Next;
    }
  Enemy_t* E= Local.Battle.First;
  for(int x= 0; x<Local.Battle.enemies; x++)
    {
      fwrite(&E->Info,sizeof(Enemy_Data_t),1,pf);
      Action_t* A= E->First;
      for(int y= 0; y<E->Info.actions; y++)
        {
          fwrite(&A->Info,sizeof(Action_Data_t),1,pf);
          A= A->Next;
        }
      E= E->Next;
    }
  puts("");
  print_center("Partita salvata"); //OUTPUT
  fclose(pf);
}

void load()
{
  FILE *pf;
  char a[64]="saves/";
  Choice_t* C;
  Item_t* I;
  Enemy_t* E;
  Action_t* A;

  strcat(a,Local.name);
  strcat(a,".bin");
  pf=fopen(a,"rb");
  if (!pf)
    fopen_error(__func__);
  fread(&Local,sizeof(Data_t),1,pf);
  Local.Events.First= Local.Events.Last= NULL;
  Local.Bag.First= Local.Bag.Last= NULL;
  Local.Battle.First= Local.Battle.Last= NULL;
  for(int x= 0; x<Local.Events.choices; x++)
    {
      C= addChoice(&Local.Events);
      fread(&C->text,sizeof(char),128,pf);
      Local.Events.choices-= 1;
    }
  for(int x= 0; x<Local.Bag.items; x++)
    {
      I= addItem(&Local.Bag);
      fread(&I->Info,sizeof(Item_Data_t),1,pf);
      Local.Bag.items-= 1;
    }
  for(int x= 0; x<Local.Ground.items; x++)
    {
      I= addItem(&Local.Ground);
      fread(&I->Info,sizeof(Item_Data_t),1,pf);
      Local.Ground.items-= 1;
    }
  for(int x= 0; x<Local.Battle.enemies; x++)
    {
      E= addEnemy(&Local.Battle);
      fread(&E->Info,sizeof(Enemy_Data_t),1,pf);
      for(int y= 0; y<Local.Battle.Last->Info.actions; y++)
        {
          A= addAction(Local.Battle.Last);
          fread(&A->Info,sizeof(Action_Data_t),1,pf);
          Local.Battle.Last->Info.actions-= 1;
        }
      Local.Battle.enemies-= 1;
    }
  fclose(pf);
}

void readsaves()
{
  FILE* pf;
  char* name;
  Choice_t* C;
  
  pf=fopen("saves/saves.txt","a+");
  if(!pf)
    fopen_error(__func__);
  rewind(pf);
  while(getc(pf)=='#')
    {
      name= sstring(pf,'\n');
      C= addChoice(&Local.Events);
      strcpy(C->text, name);
      free(name);
    }
  if(Local.Events.choices)
    strcpy(Local.Events.text,"Seleziona un salvataggio"); //TIPO OUTPUT
  else
    strcpy(Local.Events.text,"Nessun salvataggio presente");
  fclose(pf);
}

void deletesaves()
{
  FILE* pf;
  char* name;
  char a[64];
  pf=fopen("saves/saves.txt","a+");
  if(!pf)
    fopen_error(__func__);
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
  print_center("Salvataggi rimossi");  //OUTPUT
}

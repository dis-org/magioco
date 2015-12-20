#include "universal.h"
#include <stdlib.h>
#include <string.h>

void addChoice(Choice_List_t* List, char* text)
{
  Choice_t* C= calloc(1,sizeof(Choice_t)); //controllo allocazione
  if(!C)
    {
      fprintf(stderr,"Errore: allocazione non riuscita (addChoice)\n");
      exit(EXIT_FAILURE);
    }
  strcpy(C->text, text);
  if(!List->Last)
    List->Last= List->First= C;
  else
    {
      List->Last->Next= C;
      List->Last= C;
    }
  List->choices++;
}

void select(Choice_List_t* List, char* text, short chosen)
{
  Choice_t* p= List->First;
  for(int x= 1; x < chosen; x++)
    p= p->Next;
  strcpy(text, p->text);
}

void deleteChoices(Choice_List_t* List)
{
  Choice_t* temp;
  while(List->First)
    {
      temp= List->First;
      List->First= List->First->Next;
      free(temp);
    }
  List->Last=NULL;
  List->choices= 0;
}

void addItem(Item_List_t* List, char* name, char type, int usev, unsigned short trwv, unsigned short defv, int uses)
{
 Item_t *Item = calloc(1, sizeof(Item_t));

 if (!Item)
 {
  fprintf(stderr,"Errore: allocazione non riuscita (addItem)\n");
  exit(EXIT_FAILURE);
 }

 strcpy(Item->Info.name, name);
 Item->Info.type= type;
 Item->Info.usevalue= usev;
 Item->Info.trowvalue= trwv;
 Item->Info.defvalue= defv;
 Item->Info.uses= uses;
 
 if(!List->First)
   List->First = List->Last = Item;
 else
 {
  List->Last->Next = Item;
  List->Last = Item;
 }
 List->items++;
}

Item_t* searchItem(Item_List_t* List, char* name)
{
  Item_t* Ret= List->First;
  while(Ret)
    {
      if(!strcmp(Ret->Info.name, name))
        break;
      Ret= Ret->Next;
    }
  return Ret;
}

void addEnemy(Enemy_List_t* List, char* name, short health)
{
 Enemy_t* Enemy = calloc(1, sizeof(Enemy_t));

 if(!Enemy)
 {
  fprintf(stderr,"Errore: allocazione non riuscita (addEnemy)\n");
  exit(EXIT_FAILURE); 
 }

 strcpy(Enemy->Info.name, name);
 Enemy->Info.health = health;

 if(!List->First)
   List->First = List->Last = Enemy;
 else
 {
   List->Last->Next = Enemy;
   List->Last = Enemy;
 }
 List->enemies++;
}

void addAction(Enemy_t* Enemy, char* text, char type, short value)
{
 Action_t* Action = calloc(1, sizeof(Action_t));

 if(!Action)
 {
  fprintf(stderr,"Errore: allocazione non riuscita (addAction)\n");
  exit(EXIT_FAILURE);
 }

 strcpy(Action->Info.text, text);
 Action->Info.type = type;
 Action->Info.value = value;

 if(!Enemy->First)
   Enemy->First = Enemy->Last = Action;
 else
 {
  Enemy->Last->Next = Action;
  Enemy->Last = Action;
 }
 Enemy->Info.actions++;
}

Enemy_t* searchEnemy(Enemy_List_t* List, char* name)
{
  Enemy_t* Ret = List->First;
  while(Ret)
  {
    if(!strcmp(Ret->Info.name, name))
      break;
    Ret = Ret->Next;
  }
  return Ret;
}

void deleteEnemy(Enemy_List_t* List,Enemy_t* Enemy)
{
  while(List->First)
  {
    Enemy = List->First;
    List->First = List->First->Next;
    free(Enemy);
  }
  List->Last = NULL;
  List->enemies = 0;
}

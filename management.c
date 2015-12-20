#include "universal.h"
#include <stdlib.h>
#include <string.h>

//extern Data_t Local;

void addChoice(char* text, Choice_List* List)
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

void select(char* text, short chosen, Choice_List* List)
{
  Choice_t* p= List->First;
  for(int x= 1; x < chosen; x++)
    p= p->Next;
  strcpy(text, p->text);
}

void deleteChoices(Choice_List* List)
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

void addItem(Item_List* List, char* name, char type, int usev, unsigned short trwv, unsigned short defv, int uses)
{
 Item_t *Item = calloc(1, sizeof(Item_t));

 if (!Item)
 {
  fprintf(stderr,"Errore: allocazione non riuscita (addItem)\n");
  exit(EXIT_FAILURE);
 }

 strcpy(Item->name, name);
 Item->type= type;
 Item->usevalue= usev;
 Item->trowvalue= trwv;
 Item->defvalue= defv;
 Item->uses= uses;
 
 if(!List->First)
   List->First = List->Last = Item;
 else
 {
  List->Last->Next = Item;
  List->Last = Item;
 }
 List->items++;
}

Item_t* searchItem(char* id, Item_List* List)
{
  Item_t* Ret= List->First;
  while(Ret)
    {
      if(!strcmp(Ret->name, id))
        break;
      Ret= Ret->Next;
    }
  return Ret;
}

void addEnemy(Enemy_List* List,char* name, short health)
{
 Enemy_t* Enemy = calloc(1, sizeof(Enemy_t));

 if(!Enemy)
 {
  fprintf(stderr,"Errore: allocazione non riuscita (addEnemy)\n");
  exit(EXIT_FAILURE); 
 }

 strcpy(Enemy->name, name);
 Enemy->health = health;

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

 strcpy(Action->text, text);
 Action->type = type;
 Action->value = value;

 if(!Enemy->First)
   Enemy->First = Enemy->Last = Action;
 else
 {
  Enemy->Last->Next = Action;
  Enemy->Last = Action;
 }
 Enemy->actions++;
}

Enemy_t* searchEnemy(char* id, Enemy_List* List)
{
  Enemy_t* Ret = List->First;
  while(Ret)
  {
    if(!strcmp(Ret->name, id))
      break;
    Ret = Ret->Next;
  }
  return Ret;
}

void deleteEnemy(Enemy_List* List,Enemy_t* Enemy)
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

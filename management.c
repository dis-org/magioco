#include "universal.h"
#include <stdlib.h>
#include <string.h>

void addChoice(Choice_List_t* List, char* text)
{
  Choice_t* C= calloc(1,sizeof(Choice_t));
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

void deleteChoices(Choice_List_t* List)
{
  Choice_t* Temp;
  while(List->First)
    {
      Temp= List->First;
      List->First= List->First->Next;
      free(Temp);
    }
  List->Last=NULL;
  List->choices=0;
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

void deleteItem(Item_List_t* List, Item_t* Item) //da usare solo con searchItem (unire?)
{
  Item_t* Ret= List->First;
  if(Ret==Item)
    {
      List->First= Ret->Next;
      free(Item);
    }
  else
    while(Ret)
      {
	if(!Ret->Next)
	  {
	    fprintf(stderr,"Errore: oggetto non in lista (deleteItem)\n");
	    exit(EXIT_FAILURE); // non dovrebbe accadere se Item è reso da searchItem
	  }
	else
	  if(Ret->Next== Item)
	    {
	      Ret->Next= Ret->Next->Next;
	      if(!Ret->Next)
		List->Last= Ret;
	      free(Item);
	      break;
	    }
      }
  List->items--;
}

void deleteItems(Item_List_t* List)
{
  Item_t* Item;
  while(List->First)
    {
      Item = List->First;
      List->First = List->First->Next;
      free(Item);
    }
  List->Last= NULL;
  List->items = 0;
}

void addEnemy(Enemy_List_t* List, char* name, unsigned short health, unsigned short defence)
{
  Enemy_t* Enemy = calloc(1, sizeof(Enemy_t));

  if(!Enemy)
    {
      fprintf(stderr,"Errore: allocazione non riuscita (addEnemy)\n");
      exit(EXIT_FAILURE); 
    }

  strcpy(Enemy->Info.name, name);
  Enemy->Info.health = health;
  Enemy->Info.defence = defence;

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
  Enemy->actions++;
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

void deleteEnemy(Enemy_List_t* List, char* name)
{
  Enemy_t* Ret= List->First;
  if(!strcmp(Ret->Info.name, name))
    {
      List->First= Ret->Next;
      deleteActions(Ret);
      free(Ret);
      return;
    }
  while(Ret)
    {
      if(!strcmp(Ret->Next->Info.name, name))
        {
          Ret->Next= Ret->Next->Next;
          deleteActions(Ret->Next);
          free(Ret->Next);
          return;
        }
      if(Ret->Next)
        Ret= Ret->Next;
      else
        break;
    }
  Ret= List->Last;
  if(!strcmp(Ret->Info.name, name))
    {
      List->First= Ret->Next;
      deleteActions(Ret);
      free(Ret);
    }
}

void deleteEnemies(Enemy_List_t* List)
{
  Enemy_t* Enemy;
  while(List->First)
    {
      Enemy = List->First;
      List->First = List->First->Next;
      deleteActions(Enemy);
      free(Enemy);
    }
  List->Last=NULL;
  List->enemies = 0;
}

void deleteActions(Enemy_t* Enemy)
{
  Action_t* Action;
  for(int x= 0; x < Enemy->actions; x++)
    {
      Action = Enemy->First;
      Enemy->First = Enemy->First->Next;
      free(Action);
    }
  Enemy->First=NULL;
  Enemy->Last=NULL;
  Enemy->actions= 0;
}

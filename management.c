#include "universal.h"
#include <stdlib.h>
#include <string.h>

Choice_t* addChoice(Choice_List_t* List)
{
  Choice_t* C= calloc(1,sizeof(Choice_t));
  if(!C)
    {
      fprintf(stderr,"Errore: allocazione non riuscita (addChoice)\n");
      exit(EXIT_FAILURE);
    }
  if(!List->Last)
    List->Last= List->First= C;
  else
    {
      List->Last->Next= C;
      List->Last= C;
    }
  List->choices++;
  return C;
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

Item_t* addItem(Item_List_t* List)
{
  Item_t *Item = calloc(1, sizeof(Item_t));

  if (!Item)
    {
      fprintf(stderr,"Errore: allocazione non riuscita (addItem)\n");
      exit(EXIT_FAILURE);
    }
  if(!List->First)
    List->First = List->Last = Item;
  else
    {
      List->Last->Next = Item;
      List->Last = Item;
    }
  List->items++;
  return Item;
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

Enemy_t* addEnemy(Enemy_List_t* List)
{
  Enemy_t* Enemy = calloc(1, sizeof(Enemy_t));

  if(!Enemy)
    {
      fprintf(stderr,"Errore: allocazione non riuscita (addEnemy)\n");
      exit(EXIT_FAILURE); 
    }
  if(!List->First)
    List->First = List->Last = Enemy;
  else
    {
      List->Last->Next = Enemy;
      List->Last = Enemy;
    }
  List->enemies++;
  return Enemy;
}

Action_t* addAction(Enemy_t* Enemy)
{
  Action_t* Action = calloc(1, sizeof(Action_t));

  if(!Action)
    {
      fprintf(stderr,"Errore: allocazione non riuscita (addAction)\n");
      exit(EXIT_FAILURE);
    }
  if(!Enemy->First)
    Enemy->First = Enemy->Last = Action;
  else
    {
      Enemy->Last->Next = Action;
      Enemy->Last = Action;
    }
  Enemy->Info.actions++;
  return Action;
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

void deleteEnemy(Enemy_List_t* List, Enemy_t* Enemy)
{
  Enemy_t* Ret= List->First;
  if(Ret==Enemy)
    {
      List->First= Ret->Next;
      free(Enemy);
    }
  else
    while(Ret)
      {
	if(!Ret->Next)
	  {
	    fprintf(stderr,"Errore: nemico non in lista (deleteEnemy)\n");
	    exit(EXIT_FAILURE); // non dovrebbe accadere se Item è reso da searchItem
	  }
	else
	  if(Ret->Next== Enemy)
	    {
	      Ret->Next= Ret->Next->Next;
	      if(!Ret->Next)
		List->Last= Ret;
	      free(Enemy);
	      break;
	    }
      }
  List->enemies--;
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
  while(Enemy->First)
    {
      Action = Enemy->First;
      Enemy->First = Enemy->First->Next;
      free(Action);
    }
  Enemy->Last=NULL;
  Enemy->Info.actions= 0;
}

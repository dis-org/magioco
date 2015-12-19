#include "universal.h"
#include <stdlib.h>
#include <string.h>

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

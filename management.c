#include "universal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void addItem(Item_List* List, char* name, char type, int usev, unsigned short trwv, unsigned short defv)
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
 
 if(!List->First)
   List->First = List->Last = Item;
 else
 {
  List->Last->Next = Item;
  List->Last = Item;
 }
 List->items++;
}

#include "union.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Item_t* searchItem(char* id, Item_List* List)
{
  Item_t* Ret= List->First;
  while(Ret!=NULL)
    {
      if(!strcmp(Ret->name, id))
        break;
      Ret= Ret->Next;
    }
  return Ret;
}

void addItem(Item_List* List, char* name, char type, int usev, unsigned short trwv, unsigned short defv, int uses)
{
}

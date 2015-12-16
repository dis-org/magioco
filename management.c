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

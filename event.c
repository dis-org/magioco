#include <string.h>
#include "event.h"

void select(short chosen, Choice_List* List)
{
  Choice_t* p= List->First;
  for(int x= 1; x < chosen; x++)
    p= p->Next;
  strcpy(id, p->text);
}

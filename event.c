#include <string.h>
#include "event.h"

void select(short chosen, Choice_List* List)
{
  Choice_t* p= List->First;
  for(int x= 1; x < chosen; x++)
    p= p->Next;
  strcpy(id, p->text);
}

void deleteEvents(void)
{
  Choice_t* temp;
  while(Events.First!=NULL)
    {
      temp= Event.First;
      Event.First= Event.First->Next;
      free(temp);
    }
}

void addEvent(void)
{
  Choice_t Event= calloc(1,sizeof(Choice_t));
  strcpy(Event.text, id);
  Events.Last->Next= &Event;
  Event.Last= &Event;
  Events.choices++;
}

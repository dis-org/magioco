#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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
      temp= Events.First;
      Events.First= Events.First->Next;
      free(temp);
    }
  Events.Last= NULL;
}

void addEvent(void)
{
  Choice_t* Event= calloc(1,sizeof(Choice_t)); //controllo allocazione
  if(Event==NULL)
    {
      fprintf(stderr,"Errore: allocazione non riuscita (addEvent)\n");
      exit(EXIT_FAILURE);
    }
  strcpy(Event->text, id);
  if(Events.Last==NULL)
    Events.Last= Events.First= Event;
  else
  {
    Events.Last->Next= Event;
    Events.Last= Event;
   }
 Events.choices++;
}

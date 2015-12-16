#include "union.h"
#include <stdlib.h>
#include <string.h>

extern Data_t Local;

void select(short chosen, Choice_List* List)
{
  Choice_t* p= List->First;
  for(int x= 1; x < chosen; x++)
    p= p->Next;
  strcpy(Local.id, p->text);
  Local.state='t';
}

void deleteEvents(void)
{
  Choice_t* temp;
  while(Local.Events.First!=NULL)
    {
      temp= Local.Events.First;
      Local.Events.First= Local.Events.First->Next;
      free(temp);
    }
  Local.Events.Last= NULL;
  Local.Events.choices= 0;
}

void addEvent(void)
{
  Choice_t* Event= calloc(1,sizeof(Choice_t)); //controllo allocazione
  if(Event==NULL)
    {
      fprintf(stderr,"Errore: allocazione non riuscita (addEvent)\n");
      exit(EXIT_FAILURE);
    }
  strcpy(Event->text, Local.id);
  if(Local.Events.Last==NULL)
    Local.Events.Last= Local.Events.First= Event;
  else
  {
    Local.Events.Last->Next= Event;
    Local.Events.Last= Event;
   }
 Local.Events.choices++;
}

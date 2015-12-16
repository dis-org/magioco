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

void deleteChoices(Choice_List* List)
{
  Choice_t* temp;
  while(List->First!=NULL)
    {
      temp= List->First;
      List->First= List->First->Next;
      free(temp);
    }
  List->Last=NULL;
  List->choices= 0;
}

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

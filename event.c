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


#include "universal.h"
#include <stdlib.h>

void arg_error(int n)
{
  switch(n)
    {
    case 2:
      fprintf(stderr,
	      "\nImmesse troppe specifiche di esecuzione\n"
	      "Inserire massimo una specifica\n"
	      );
      break;
    case 1:
      fprintf(stderr,"\nSpecifica non riconosciuta\n");
      break;
    }
  fprintf(stderr,
	  "\nPossibili specifiche di esecuzione:\n"
	  " (h) help : Mostra questo messaggio\n"
	  " (t) test : Esegue controllo completo dei file di testo\n"
	  //" (m) man : Mostra il manuale del programma\n"
	  "\n"
	  );
  exit(EXIT_FAILURE);
}

void folders_error()
{
  fprintf(stderr,
	  "\nFile o cartelle mancanti\n"
	  "Per funzionare il programma richiede:\n"
	  "una cartella \"saves\" vuota\n"
	  "una cartella \"custom\" contenente i seguenti file:\n"
	  " events.txt  enemy.txt  item.txt\n\n"
	  );
  exit(EXIT_FAILURE);
}

void alloc_error(char* func)
{
  fprintf(stderr,"Errore: allocazione non riuscita in %s\n", func); //OUTPUT
  exit(EXIT_FAILURE);
}

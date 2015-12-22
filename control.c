#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"universal.h"

test_story(){
int x;
FILE *pf;
pf = fopen("custom/events.txt","r");
if (!pf){ 
  fprintf(stderr,"Errore: impossibile aprire events.txt\n");
  exit(EXIT_FAILURE);
}
do{
   do{
   x=getc();
   if (x=='/'){
            test_event(pf);
            break;
            }
   if (x=='+'){
             test_choice(pf);
             break;
            }
   else
   }while(x!='\n');

}while(x!=EOF);
}


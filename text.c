#include "text.h"
#include "event.h"
#include <stdio.h>	
#include <stdlib.h>
#include <string.h>

void readevent(){
char x,*f;
FILE *pf;
pf = fopen("events.txt","r");
if (pf==NULL){ 
              fprintf(stderr,"Errore: impossibile aprire events.txt\n");
              exit(EXIT_FAILURE);
              }
controle(pf,'/','\n');
printtext(pf);
do{
   move('-',pf);
   
   x=getc(pf);
   if (x=='*') break;
   if ( x== '>') break;
   if (x=='i'){
               getc(pf);
               f=sstring(pf,'\n');
               strcpy(id,f);
               free(f);
               //iserch();
              }
   if (x=='e'){
               getc(pf);
               f=sstring(pf,'\n');
               strcpy(id,f);
               free(f);
              // eserch();
              }
  }while(x!=EOF);
  if (x=='*'){
              state='c';
              f=sstring(pf,'\n');
              strcpy(id,f);
              free(f);
              fseek(pf,0L,SEEK_SET);
              readchoices(pf);
             }
  if (x=='>'){
              state='t';
              f=sstring(pf,'\n');
              strcpy(id,f);
              free(f);
             }
  
  fclose(pf);
}            

void move(char a,FILE* pf){//muove il puntatore fino al simbolo...finito.
char c;
do{
   c=getc(pf);
   if (c==EOF) break;
  }while(c != a);
}

void printtext(FILE*pf){// stampa il testo fino al simbolo...finito.
char a;
do{
   a=getc(pf);
   if (a=='*'){ 
               putc('\n',stdout);
               return;
              }
   putc(a,stdout);
               
  }while(a != EOF);
}

char* sstring(FILE *pf,char m){// rimanda una stringa..finito.
char a;
int i= 0;
char *x=calloc(128,sizeof(char));
if (x==NULL){
              fprintf(stderr,"Errore: allocazione non riuscita (sstring)\n");
              exit(EXIT_FAILURE);
              }
do{
  a=getc(pf);
   if(a==m){
            return x;
           }
   *(x+i)=a;
   i++;
  }while(a!=EOF);
}

void controle(FILE* pf,char f,char x){ // controlla 2 stringhe.. finito.
char *temp;
do{
   move(f,pf);
   temp = sstring(pf,x);
  }while (strcmp(temp,id));
free(temp);
}

void readchoices(FILE* pf){
char c;
char *x;
deleteEvents();
controle(pf,'+','\n');
strcpy(Events.text,id);
do{
   move('/',pf);
   x=sstring(pf,'\n');
   strcpy(id,x);
   free(x);
   if (!strcmp(id,"#"))
       return;
   addEvent();
  }while(1);
}

void iserch(){
FILE* pf;
pf=fopen("items.txt","r");
if (pf==NULL){ 
              fprintf(stderr,"Errore: impossibile aprire items.txt\n");
              exit(EXIT_FAILURE);
              }
controle(pf,'/','.');
//select(sstring(pf,'.'),atoi(sstring(pf,'.')),atoi(sstring(pf,'.')),atoi(sstring(pf,'.')),atoi(sstring(pf,'.')));
}



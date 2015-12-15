#include"text.h"
#include"event.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void readevent(){
char x;
FILE *pf;
pf = fopen("events.txt","r");
if (pf==NULL){ 
              fprintf(stderr,"errore\n");
              exit(EXIT_FAILURE);
              }
controle(pf,'/');
printtext(pf);
do{
   move('-',pf);
   
   x=getc(pf);
   if (x=='*') break;
   if ( x== '>') break;
   if (x=='i'){
               getc(pf);
               //iserch();
              }
   if (x=='e'){
               getc(pf);
              // eserch();
              }
  }while(x!=EOF);
  if (x=='*'){
              state='c';
              strcpy(id,sstring(pf,'\n'));
              fseek(pf,0L,SEEK_SET);
              readchoices(pf);
             }
  if (x=='>'){
              state='t';
              strcpy(id,sstring(pf,'\n'));
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
              fprintf(stderr,"errore\n");
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

void controle(FILE* pf,char f){ // controlla 2 stringhe.. finito.
char *temp;
do{
   move(f,pf);
   temp = sstring(pf,'\n');
  }while (strcmp(temp,id));
free(temp);
}

void readchoices(FILE* pf){
char c;
deleteEvents();
controle(pf,'+');
strcpy(Events.text,id);
do{
   move('/',pf);
   strcpy(id,sstring(pf,'\n'));
   if (strcmp(id,"#"))return;
   addEvent();
  }while(1);
}

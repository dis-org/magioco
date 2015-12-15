#include"text.h"
#include"var.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void readevent(){
int x;
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
   if (x=='i'){
               getc(pf);
               //iserch();
              }
   if (x=='e'){
               getc(pf);
              // eserch();
              }
  }while(x!='*' || x!='>');
  if (x=='*'){
              state='c';
              id=sstring(pf,'\n');
              fseek(pf,0L,SEEK_SET);
              readchoices(pf);
             }
  if (x=='>'){
              state='t';
              id=sstring(pf,'\n');
             }
  
  fclose(pf);
}            

void move(int a,FILE* pf){//muove il puntatore fino al simbolo...finito.
int c;
while(c != a){
               c=getc(pf);
              if (c==EOF) break;
              }
}

void printtext(FILE*pf){// stampa il testo fino al simbolo...finito.
int a;
do{
   a=getc(pf);
   if (a=='*'){ 
               return;
              }
   putc(a,stdout);
               
  }while(a != EOF);
}

char* sstring(FILE *pf,int m){// rimanda una stringa..finito.
int a,i=0;
char *x=malloc(128*sizeof(char));
do{
   a=getc(pf);
   if(a==m){
            return x;
           }
   *(x+i)=a;
   i++;
  }while(a!=EOF);
}

void controle(FILE* pf,int f){// controlla 2 stringhe.. finito.
 char *temp;
do{
   move(f,pf);
   temp = sstring(pf,'\n');
  }while (strcmp(temp,id)!=0);
free(temp);
}
void readchoices(FILE* pf){
int c;
//deleteEvent();
controle(pf,'+');
Events.text=id;
do{
   move('/',pf);
   id=sstring(pf);
   if (strcmp(id,"#"))return;
   //addEvent();
  }while(1);
}

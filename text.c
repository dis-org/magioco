#include"text.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void readevent(char *ID){
int x;
FILE *pf;
pf = fopen("events.txt","r");
if (pf==NULL){ 
              fprintf(stderr,"errore\n");
              exit(EXIT_FAILURE);
              }
  controle(pf,ID);
  printtext(pf);
do{
   move('>',pf);
   x=getc(pf);
   if (x=='i'){
   
              }
   if (x=='e'){
   
              }
  }while(x!='#');
  x=getc(pf);
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

char* sstring(FILE *pf){// rimanda una stringa..finito.
int c='/',a,i=0;
char *x=malloc(128*sizeof(char));
do{
   a=getc(pf);
   if(a==c){
            return x;
           }
   *(x+i)=a;
   i++;
  }while(a!=EOF);
}

void controle(FILE* pf, char* id){// controlla 2 stringhe.. finito.
 char *temp;
do{
   move('^',pf);
   temp = sstring(pf);
  }while (strcmp(temp,id)!=0);
free(temp);
}

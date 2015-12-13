#include"text.h"
#include<stdio.h>
#include<stdlib.h>

void readevent(void){
int x='#';
char *id;
FILE *pf;
pf = fopen("test.txt","r");
if (pf==NULL){ 
              printf("errore");
              exit(EXIT_FAILURE);
              }; 
  control(pf);            
  fclose(pf);
}            

void move(int a,FILE* pf){
int c;
while(c != a){
               c=getc(pf);
              if (c==EOF) break;
              }
}

void read(FILE*pf){
int a;
do{
   a=getc(pf);
   if (a=='*'){ 
               return;
              }
   putc(a,stdout);
               
  }while(a != EOF);
}

char* sstring(FILE *pf){
int c='/',a;
char *x=malloc(128*sizeof(char));
do{
   a=getc(pf);
   if(a==c){
            return x;
           }
   *x=c;
  }while(c!=EOF);
}

void controle(char*x;FILE* pf){
do{
  move('^',text);
  




}






























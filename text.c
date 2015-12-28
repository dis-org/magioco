#include "universal.h"
#include <stdio.h>      
#include <stdlib.h>
#include <string.h>

extern Data_t Local;

void readevent(char* id, char* t){
  char x=0,*f,*n;
  FILE *pf;
  _Bool add= 0;
  pf = fopen("custom/events.txt","r");
  if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire events.txt (readevent)\n");
    exit(EXIT_FAILURE);
  }
  controle(pf,'/','\n',id);
  printtext(pf);

  if(!Local.done)
    {
      add= 1;
      Local.done= 1;
    }

  do{
    move('-',pf);
    x=getc(pf);
    if (x=='*'|| x=='>'|| x=='#') break;
    if(add)
      {
        if (x=='i'){
          getc(pf);
          f=sstring(pf,'.');
          n=sstring(pf,'\n');
          int uses=atoi(n);
          strcpy(id,f);
          free(f);
          free(n);
          isearch(uses, id);
        }
        if (x=='e'){
          getc(pf);
          f=sstring(pf,'\n');
          strcpy(id,f);
          free(f);
          esearch(id);
        }
      }
  }while(x!=EOF);
  if (x=='*'){
    *t='c';
    f=sstring(pf,'\n');
    strcpy(id,f);
    free(f);
    rewind(pf);
    readchoices(pf, id);
    Local.chosen= 1;
  }
  if (x=='>'){
    *t='t';
    f=sstring(pf,'\n');
    strcpy(id,f);
    free(f);
  }
  if (x=='#')
    *t='g';

  fclose(pf);
}

void move( char a, FILE* pf){ //muove il puntatore fino al simbolo...finito.
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
  if (!x){
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
  return NULL;
}

void controle(FILE* pf,char f,char x,char* id){ // controlla 2 stringhe.. finito.
  char *temp;
  do{
    move(f,pf);
    temp = sstring(pf,x);
  }while (strcmp(temp,id));// da aggiungere parametro 
  free(temp);
}

void readchoices(FILE* pf, char* id){
  char *x;
  char *temp=calloc(128,sizeof(char));
  if (!temp){
    fprintf(stderr,"Errore: allocazione non riuscita (readchoices)\n");
    exit(EXIT_FAILURE);
  }
  controle(pf,'+','\n',id);
  strcpy(Local.Events.text,id);
  while(1){
    move('/',pf);
    x=sstring(pf,'\n');
    strcpy(temp,x);
    free(x);
    if (!strcmp(temp,"#"))
      break;
    addChoice(&Local.Events, temp);
  }
  free(temp);
}

void isearch(short uses, char* id){
  FILE* pf;
  char* t;
  pf=fopen("custom/items.txt","r");
  if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire items.txt\n");
    exit(EXIT_FAILURE);
  }
  controle(pf,'/','.',id);
  char type=getc(pf);
  getc(pf);
  t=sstring(pf,'.');
  int usev=atoi(t);
  free(t);
  t=sstring(pf,'.');
  int trwv=atoi(t);
  free(t);
  t=sstring(pf,'\n');
  int defv=atoi(t);
  free(t);
  Item_t* temp;
  switch(type){
  case'p':
    temp= searchItem(&Local.Bag, id);
    if (temp){
      temp->Info.uses+=uses;
      break;
    }
  case'u':
    addItem(&Local.Bag, id, type, usev, trwv, defv, uses);
    break;
  }
  fclose(pf);
}
void esearch(char* id){ //da rivedere
  FILE* pf;
  pf=fopen("custom/enemies.txt","r");
  if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire enemies.txt\n");
    exit(EXIT_FAILURE);
  }
  short y, z;
  char x,*temp;
  controle(pf,'/','.', id);
  temp=sstring(pf,'.');
  y=atoi(temp);
  free(temp);
  temp=sstring(pf,'\n');
  z=atoi(temp);
  free(temp);
  addEnemy(&Local.Battle, id, y, z);
  while(1){
    move('-', pf);
    temp=sstring(pf,'/');
    if (!strcmp(temp,"#")){ 
      free(temp);
      break;
    }
    strcpy(id,temp);
    free(temp);
    temp=sstring(pf,'.');
    x=*temp;
    free(temp);
    temp=sstring(pf,'\n');
    y=atoi(temp);
    free(temp);
    addAction(Local.Battle.Last, id, x, y);
  }
  fclose(pf);
}

#include "universal.h"
#include <stdio.h>	
#include <stdlib.h>
#include <string.h>

extern Data_t Local;

void readevent(){
  char x,*f,*n;
  FILE *pf;
  pf = fopen("custom/events.txt","r");
  if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire events.txt (readevent)\n");
    exit(EXIT_FAILURE);
  }
  controle(pf,'/','\n');
  printtext(pf);
  do{
    move('-',pf);

    x=getc(pf);
    if (x=='*'|| x=='>'|| x=='#') break;
    if (x=='i'){
      getc(pf);
      f=sstring(pf,'.');
      n=sstring(pf,'\n');
      int uses=atoi(n);
      strcpy(Local.id,f);
      free(f);
      free(n);
      isearch(uses);
    }
    if (x=='e'){
      getc(pf);
      f=sstring(pf,'\n');
      strcpy(Local.id,f);
      free(f);
      esearch();
    }
  }while(x!=EOF);
  if (x=='*'){
    n= calloc(128,sizeof(char));
    if (!n){
      fprintf(stderr,"Errore: allocazione non riuscita (readevent)\n");
      exit(EXIT_FAILURE);
    }
    strcpy(n, Local.id);
    Local.state='c';
    f=sstring(pf,'\n');
    strcpy(Local.id,f);
    free(f);
    rewind(pf);
    readchoices(pf);
    strcpy(Local.id, n);
    Local.chosen= 1;
  }
  if (x=='>'){
    Local.state='t';
    f=sstring(pf,'\n');
    strcpy(Local.id,f);
    free(f);
  }
  if (x=='#')
    Local.state='g';

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

void controle(FILE* pf,char f,char x){ // controlla 2 stringhe.. finito.
  char *temp;
  do{
    move(f,pf);
    temp = sstring(pf,x);
  }while (strcmp(temp,Local.id));// da aggiungere parametro 
  free(temp);
}

void readchoices(FILE* pf){
  char *x;
  char *temp=calloc(128,sizeof(char));
  deleteChoices(&Local.Events);
  controle(pf,'+','\n');
  strcpy(Local.Events.text,Local.id);
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

void isearch(short uses){
  FILE* pf;
  char* t;
  pf=fopen("custom/items.txt","r");
  if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire items.txt\n");
    exit(EXIT_FAILURE);
  }
  controle(pf,'/','.');
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
    temp= searchItem(&Local.Bag, Local.id);
    if (temp){
      temp->Info.uses+=uses;
      break;
    }
  case'u':
    addItem(&Local.Bag, Local.id, type, usev, trwv, defv, uses);
    break;
  }
  fclose(pf);
}
void esearch(){
  FILE* pf;
  pf=fopen("custom/enemies.txt","r");
  if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire enemies.txt\n");
    exit(EXIT_FAILURE);
  }
  short y;
  char x,*temp;
  controle(pf,'/','.');
  temp=sstring(pf,'\n');
  y=atoi(temp);
  free(temp);
  addEnemy(&Local.Battle, Local.id, y);
  while(1){
    move('-', pf);
    temp=sstring(pf,'/');
    if (!strcmp(temp,"#")){ 
      free(temp);
      break;
    }
    strcpy(Local.id,temp);
    free(temp);
    temp=sstring(pf,'.');
    x=*temp;
    free(temp);
    temp=sstring(pf,'\n');
    y=atoi(temp);
    free(temp);
    addAction(Local.Battle.Last, Local.id, x, y);
  }
  fclose(pf);
}

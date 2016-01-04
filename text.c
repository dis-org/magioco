#include "universal.h"  
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
  puts("");

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
	  print_center(id);
          isearch(uses, id);
        }
        if (x=='e'){
          getc(pf);
          f=sstring(pf,'\n');
          strcpy(id,f);
          free(f);
	  print_center(id);
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
  Choice_t* C;
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
    if(!strcmp(temp,"#"))
      break;
    C= addChoice(&Local.Events);
    strcpy(C->text, temp);
  }
  free(temp);
}

void isearch(short uses, char* id){
  FILE* pf;
  char type, *temp;
  Item_t* I;

  pf=fopen("custom/items.txt","r");
  if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire items.txt\n");
    exit(EXIT_FAILURE);
  }
  controle(pf,'/','.',id);
  type=getc(pf);
  getc(pf);
  switch(type){
  case'p':
    I= searchItem(&Local.Bag, id);
    if (I){
      I->Info.uses+=uses;
      break;
    }
  case'u':
    I= addItem(&Local.Bag);
    strcpy(I->Info.name, id);
    I->Info.type=type;
    I->Info.uses= uses;
    temp=sstring(pf,'.');
    I->Info.damage=atoi(temp);
    free(temp);
    temp=sstring(pf,'.');
    I->Info.trowvalue=atoi(temp);
    free(temp);
    temp=sstring(pf,'\n');
    I->Info.defvalue=atoi(temp);
    free(temp);
    break;
  }
  fclose(pf);
}
void esearch(char* id){
  FILE* pf;
  char x,*temp;
  Enemy_t* E;
  Action_t* A;

  pf=fopen("custom/enemies.txt","r");
  if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire enemies.txt\n");
    exit(EXIT_FAILURE);
  }
  E= addEnemy(&Local.Battle);
  controle(pf,'/','.', id);
  strcpy(E->Info.name, id);
  temp=sstring(pf,'.');
  E->Info.health= atoi(temp);
  free(temp);
  temp=sstring(pf,'\n');
  E->Info.defence= atoi(temp);
  free(temp);
  while(1){
    move('-', pf);
    x=getc(pf);
    if (x=='#')
      break;
    A= addAction(Local.Battle.Last);
    A->Info.type= x;
    move('.',pf); //basterebbe un getc(pf)
    temp=sstring(pf,'.');
    A->Info.value= atoi(temp);
    free(temp);
    temp=sstring(pf,'\n');
    strcpy(A->Info.text, temp);
    free(temp);
  }
  fclose(pf);
}

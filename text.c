#include "universal.h"  
#include <stdlib.h>
#include <string.h>

extern Data_t Local;

void readevent(char* id, char* t){
  char x=0,*f,*n;
  FILE *pf;
  _Bool add= 0;
  int num;

  pf = fopen("custom/events.txt","r");
  if (!pf)
    fopen_error(__func__);
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
    if (x=='*'|| x=='>'|| x=='#' || x=='?') break;
    if(add)
      {
        if (x=='i'){
          move('.', pf);
          f=sstring(pf,'.');
          n=sstring(pf,'\n');
          num= atoi(n);
          strcpy(id,f);
          free(f);
          free(n);
          print_center(id);
          isearch(num, id);
        }
	else
	  if (x=='e'){
	    move('.',pf);
	    f=sstring(pf,'\n');
	    strcpy(id,f);
	    free(f);
	    print_center(id);
	    esearch(id);
	  }
	  else
	    if (x=='d'){
	      move('.',pf);
	      n= sstring(pf,'\n');
	      num= atoi(n);
	      free(n);
	      //output?
	      Local.damage= num;
	    }
	    else
	      if (x=='s')
		save();
	
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
  else
    if (x=='>'){
      *t='t';
      f=sstring(pf,'\n');
      strcpy(id,f);
      free(f);
    }
    else
      if (x=='#')
	*t='g';
      else
	if (x=='?')
	  *t= 'i';

  fclose(pf);
}

void move( char a, FILE* pf){ //muove il puntatore fino al simbolo...finito.
  char c;
  do{
    c=getc(pf);
    if (c==EOF)
      eof_error(__func__,a);
  }while(c != a);
}

void printtext(FILE*pf){// stampa il testo fino al simbolo...finito.
  char a;
  while(1)
    {
      a=getc(pf);
      if(a==EOF)
	eof_error(__func__,'#');
      if (a=='#'){ 
	putc('\n',stdout);
	return;
      }
      putc(a,stdout);        
    }
}

char* sstring(FILE *pf,char m){// rimanda una stringa..finito.
  char a;
  int i= 0;
  char *x=calloc(128,sizeof(char));
  if (!x)
    alloc_error(__func__);
  while(1)
    {
      a=getc(pf);
      if(a==EOF)
	eof_error(__func__,m);
      if(a==m){
	return x;
      }
      *(x+i)=a;
      i++;
    }
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
  Item_t* I;

  if (!temp)
    alloc_error(__func__);
  controle(pf,'+','\n',id);
  strcpy(Local.Events.text,id);
  while(1){
    move('/',pf);
    x=sstring(pf,'\n');
    strcpy(temp,x);
    free(x);
    if(temp[0]=='#')
      break;
    if(temp[0]=='?')
      {
        x= sstring(pf,'.');
        strcpy(temp, x);
        free(x);
        I= searchItem(&Local.Bag, temp);
        if(I)
          {
            x= sstring(pf, '\n');
            if(I->Info.uses < atoi(x))
              {
                free(x);
                continue;
              }
            else
              free(x);
            x=sstring(pf,'\n');
            strcpy(temp, x);
            free(x);
          }
        else
          continue;
      }
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
  if (!pf)
    fopen_error(__func__);
  controle(pf,'/','.',id);
  type=getc(pf);
  move('.',pf);
  if(uses < 0)
    {
      I=searchItem(&Local.Bag, id);
      if(I->Info.uses+uses >0)
        I->Info.uses+= uses;
      else
        deleteItem(&Local.Bag, I);
      return;
    }
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
  if (!pf)
    fopen_error(__func__);
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

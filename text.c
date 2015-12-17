#include "universal.h"
#include <stdio.h>	
#include <stdlib.h>
#include <string.h>

extern Data_t Local;

void readevent(){
  char x,*f;
  FILE *pf;
  pf = fopen("Custom/events.txt","r");
  if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire events.txt\n");
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
      f=sstring(pf,'\n');
      strcpy(Local.id,f);
      free(f);
      //iserch();
    }
    if (x=='e'){
      getc(pf);
      f=sstring(pf,'\n');
      strcpy(Local.id,f);
      free(f);
      // eserch();
    }
  }while(x!=EOF);
  if (x=='*'){
    Local.state='c';
    f=sstring(pf,'\n');
    strcpy(Local.id,f);
    free(f);
    fseek(pf,0L,SEEK_SET);
    readchoices(pf);
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
  deleteChoices(&Local.Events);
  controle(pf,'+','\n');
  strcpy(Local.Events.text,Local.id);
  do{
    move('/',pf);
    x=sstring(pf,'\n');
    strcpy(Local.id,x);
    free(x);
    if (!strcmp(Local.id,"#"))
      return;
    addChoice(Local.id, &Local.Events);
  }while(1);
}

void isearch(){
  FILE* pf;
  pf=fopen("custom/items.txt","r");
  if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire items.txt\n");
    exit(EXIT_FAILURE);
  }
  controle(pf,'/','.');
  char *type=sstring(pf,'.');
  int usev=atoi(sstring(pf,'.'));
  int trwv=atoi(sstring(pf,'.'));
  int defv=atoi(sstring(pf,'.'));
  int uses=atoi(sstring(pf,'.'));
  Item_t* temp;
  switch(*type){
  case'p':
    temp= searchItem(Local.id, &Local.Bag);
    if (temp){
      temp->uses+=uses;
      break;
    }
  case'u':
    addItem(&Local.Bag, Local.id, *type, usev, trwv, defv, uses);
    break;
  }
  fclose(pf);
}
void esearch(){
FILE* pf;
pf=fopen("custom/enemies.txt","r");
if (!pf){ 
 fprintf(stderr,"Errore: impossibile aprire items.txt\n");
 exit(EXIT_FAILURE);
}
short life;
char x,*temp;
controle(pf,'/','.');
temp=sstring(pf,'\n');
life=atoi(temp);
free(temp);
//addEnemy(Local.id,life);
while(1){
 move(pf, '-' );
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
 life=atoi(temp);
 free(temp);
 //addAction(Local.Battle.Last,Local.id,x,life);
 }

}

void save(){
  FILE *pf;
  char a[100]="saves/";
  strcat(a,Local.name);
  pf=fopen(a,"wb");
  fwrite(&Local,sizeof(Data_t),1,pf);
  }

void load(){
  FILE *pf;
  char a[100]="saves/";
  strcat(a,Local.name);
  pf=fopen(a,"r");
  if (!pf){ 
    fprintf(stderr,"nessun salvataggio\n");
    Local.state='m';
    }
  fread(&Local,sizeof(Data_t),1,pf);
};

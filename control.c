#include "universal.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern Data_t Local;
int line=0;

void test_story(){
  char temp[128]= "Start";
  FILE *t1, *t2, *t3;
  t1=fopen("custom/events.txt","r");
  t2=fopen("custom/enemies.txt","r");
  t3=fopen("custom/items.txt","r");
  if(!t1 || !t2 || !t3)
    folders_error();
    
  test_event(t1,t2,t3,temp);
  
  fclose(t1); 
  fclose(t2);
  fclose(t3);
}

void test_event(FILE* eventi, FILE* nemici, FILE* oggetti, char* id){
  rewind(eventi);
  
        if (x=='i'){
          x=getc(pf);
          temp=test_string(pf,'.');
          x=getc(pf);
          semp=test_string(pf,'\n');
          if (number(semp)){
            //fprintf(stderr,"errore in evento lineare %s\n",temp); //OUTPUT
            return;
          }
          test_item(temp,line);
        }
        if (x=='e'){
          x=getc(pf);
          temp=sstring(pf,'\n');
          test_enemy(temp,line);
        }
      }
      if (x=='*'){
        id=sstring(pf,'\n');
        test_choice(pf,id,line);
        return;
      }
      if (x=='>'){
        id=sstring(pf,'\n');
        test_event(pf,id,line);
        return;
      }
      if (x=='#'){
        return;
      }
    }
    if(feof(pf))
      break;
  }
  fprintf(stderr,"errore in evento lineare %s\n",id); //OUTPUT
  exit(EXIT_FAILURE);
  return;
}

void test_choice(FILE* pf,char* id,int* line){
  rewind(pf);
  char *temp;
  while (feof(pf)){
    move('+',pf);
    temp=sstring(pf,'\n');
    if (!strcmp(id,temp)){
      while(1){
        move('/',pf);
        temp=sstring(pf,'\n');
        if(!strcmp(temp,"#")) return;
        test_event(pf,temp,line);
      }
      fprintf(stderr,"errore nell' evento scelta (%s)\n",id); //OUTPUT
      exit(EXIT_FAILURE);
      return;
    }
  }
}

void test_item(char* id, int* line){
  FILE* pf;
  char *temp;
  pf = fopen("custom/items.txt","r");
  if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire items.txt\n"); //OUTPUT
    exit(EXIT_FAILURE);
  }
  while (feof(pf)){
    move('/',pf);
    temp=sstring(pf,'.');
    if (!strcmp(id,temp)){
      free(temp);
      temp=sstring(pf,'.');
      if ( *temp!='p' && *temp!='u' ){
        fprintf(stderr,"errore nell' oggetto (%s)\n",id); //OUTPUT
        exit(EXIT_FAILURE);
        return;
      }
      free(temp);
      temp=sstring(pf,'.');
      if (number(temp)){
        fprintf(stderr,"errore nell' oggetto (%s)\n",id); //OUTPUT
        exit(EXIT_FAILURE);
        return;
      }
      free(temp);
      temp=sstring(pf,'.');
      if (number(temp)){
        fprintf(stderr,"errore nell' oggetto (%s)\n",id); //OUTPUT
        exit(EXIT_FAILURE);
        return;
      }
      free(temp);
      temp=sstring(pf,'\n');
      if (number(temp)){
        fprintf(stderr,"errore nell' oggetto (%s)\n",id); //OUTPUT
        exit(EXIT_FAILURE);
        return;
      }
      free(temp);
                    
    }
  }
  return; 
}

void test_enemy(char* id, int *line){
  FILE* pf;
  char *temp;
  char x;
  pf = fopen("custom/enemies.txt","r");
  if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire enemies.txt\n"); //OUTPUT
    exit(EXIT_FAILURE);
  }
  while (feof(pf)){
    move('/',pf);
    temp=sstring(pf,'.');
    if (!strcmp(id,temp)){
      free(temp);
      temp=sstring(pf,'.');
      if  (number(temp)){
        fprintf(stderr,"errore nel nemico (%s)\n",id); //OUTPUT
        exit(EXIT_FAILURE);
        return;
      }
      temp=sstring(pf,'\n');
      if  (number(temp)){
        fprintf(stderr,"errore nel nemico (%s)\n",id); //OUTPUT
        exit(EXIT_FAILURE);
        return;
      }
      move('-',pf);
      x=getc(pf);
      getc(pf);
      if (x!='r' && x!='m' && x!='d' && x!='#'){
        fprintf(stderr,"errore nel nemico (%s)\n",id); //OUTPUT
        exit(EXIT_FAILURE);
        return;
      }
      if (x=='#'){
        return;
      }
      x=getc(pf);
      if (isdigit(x)){
        fprintf(stderr,"errore nel nemico (%s)\n",id); //OUTPUT
        exit(EXIT_FAILURE);
        return;
      }
    }

  }
  fprintf(stderr,"errore nel nemico (%s)\n",id); //OUTPUT
  exit(EXIT_FAILURE);
  return;
    }

int number(char *num){
  char x='n';
  int i=0;
  while (x=='n'){
    if (num[i]=='\0'){
      x='s';
      continue;
    }
    if(num[i]<'0' || num[i]>'9') return 3;
  }
  return 0;
}
void test_move( char a, FILE* pf){
  char c;
  do{
    c=getc(pf);
    if (c == a) return;
  }while(c!=EOF);
  // errore
}void controlt(FILE* pf,char f,char x,char* id){ .
  char *temp;char* sstring(FILE *pf,char m){// rimanda una stringa..finito.
  char a;
  int i= 0;
  char *x=calloc(128,sizeof(char));
  if (!x){
    fprintf(stderr,"Errore: allocazione non riuscita (sstring)\n"); //OUTPUT
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
  do{
    test_move(f,pf);
    temp = test_string(pf,x);
  }while (strcmp(temp,id));// da aggiungere parametro 
  free(temp);
}char* test_string(FILE *pf,char m){
  char a;
  int i= 0;
  char *x=calloc(128,sizeof(char));
  if (!x){
    //fprintf(stderr,"Errore: allocazione non riuscita (sstring)\n"); //OUTPUT
  }
  do{
    a=getc(pf);
    if(a==m){
      return x;
    }
    *(x+i)=a;
    i++;
  }while(a!=EOF);
  //errore
  return NULL;
}

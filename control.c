#include "universal.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern Data_t Local;

void check_folders()
{
  FILE *pf, *t1, *t2, *t3;
  pf=fopen("saves/check.tmp","w");
  t1=fopen("custom/events.txt","r");
  t2=fopen("custom/enemies.txt","r");
  t3=fopen("custom/items.txt","r");
  if(!pf || !t1 || !t2 || !t3)
    folders_error();
  fclose(pf);
  fclose(t1); 
  fclose(t2);
  fclose(t3);
  remove("saves/check.tmp");
}

void test_story(){
  char temp[128]= "Start";
  FILE *pf;
  int line= 0;
  pf= fopen("custom/events.txt","r");
  if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire events.txt\n"); //OUTPUT
    exit(EXIT_FAILURE);
  }
  test_event(pf,temp,&line);
  fclose(pf);
}

void test_event(FILE* pf, char* id, int* line){
  rewind(pf);
  char *temp,*semp;
  char x='i';
  while (1){
    move('/', pf);
    temp=sstring(pf,'\n');
    if (!strcpy(id,temp)){
      move('*',pf);
      while(x=='*' || x=='>' || x=='#'){
        move('-',pf);
        x=getc(pf);
        if (x=='i'){
          x=getc(pf);
          temp=sstring(pf,'.');
          x=getc(pf);
          semp=sstring(pf,'\n');
          if (number(semp)){
            fprintf(stderr,"errore in evento lineare %s\n",temp); //OUTPUT
            exit(EXIT_FAILURE);
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
    if(!isdigit(num[i])) return 3;
  }
  return 0;
}

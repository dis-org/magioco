#include<stdlib.h>
#include<string.h>
#include"universal.h"
extern Data_t Local;
void test_story(){
  char *temp=&Local.id;
  FILE *pf;
  pf = fopen("custom/events.txt","r");
  if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire events.txt\n");
    exit(EXIT_FAILURE);
  }
  test_event(pf,temp);
}
void test_event(FILE* pf, char* id){
  rewind(pf);
  char *temp;
  char x='i';
  while (feof(pf)){
    move(pf,'/');
    temp=sstring(pf,'\n');
    if (!strcpy(id,temp)){
      move(pf,'*');
      while(x=='*' || x=='>' || x=='#'){
        move(pf,'-');
        x=getc(pf);
        if ((x=getc(pf))=='i'){
          temp=sstring(pf,'.');
          test_item(temp);
        }
        if ((x=getc(pf))=='e'){
          temp=sstring(pf,'\n');
          test_enemy(temp);
        }
      }
      if ((x=getc(pf))=='*'){
        id=sstring(pf,'\n');
        test_choice(pf,id);
        return;
      }
      if ((x=getc(pf))=='>'){
        id=sstring(pf,'\n');
        test_event(pf,id);
        return;
      }
      if ((x=getc(pf))=='#'){
        return;
      }
    }

  }

  printf(stderr,"errore in evento lineare %s",id);
  return;
}

void test_choice(FILE* PF,char* id){
  rewind(pf);
  char *temp;
  while (feof(pf)){
    move(pf,'+');
    temp=sstring(pf,'\n');
    if (!strcmp(id,temp)){
      while(1){
        move(pf,'/');
        temp=sstring(pf,'\n');
        if(strcmp(temp,'#')) return;
        test_event(pf,temp);
      }
      printf(stderr,"errore nell' evento scelta (%s)",id);
      return;
    }
  }
}
void test_item(char* id){
FILE* pf;
char *temp;
pf = fopen("custom/items.txt","r");
if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire items.txt\n");
    exit(EXIT_FAILURE);
  }
  while (feof(pf)){
  move(pf,'/');
  temp=sstring(pf,'.');
  if (!strcmp(id,temp)){
                    free(temp);
                    temp=sstring(pf,'.');
                    if ( *temp!='p' || *temp!='u' ){
                                            printf(stderr,"errore nell' ogetto (%d)",id);
                                            return;
                                           }
                    free(temp);
                    temp=sstring(pf,'.');
                    if (stdigit(temp)){
                                            printf(stderr,"errore nell' ogetto (%s)",id);
                                            return;
                                           }
                    free(temp);
                    temp=sstring(pf,'.');
                    if (stdigit(temp)){
                                            printf(stderr,"errore nell' ogetto (%s)",id);
                                            return;
                                           }
                    free(temp);
                    temp=sstring(pf,'\n');
                    if (stdigit(temp)){
                                            printf(stderr,"errore nell' ogetto (%s)",id);
                                            return;
                                           }
                    free(temp);
                    
                   }
  }
 return; 
}
void test_enemy(char* id){

}
void test_enemy(char* id){
FILE* pf;
char *temp;
pf = fopen("custom/enemies.txt","r");
if (!pf){ 
    fprintf(stderr,"Errore: impossibile aprire enemies.txt\n");
    exit(EXIT_FAILURE);
  }
  while (feof(pf)){
  move(pf,'/');
  temp=sstring(pf,'.');
  if (!strcmp(id,temp)){
  free(temp);
                    temp=sstring(pf,'\n');
                   if  (stdigit(temp)){
                   printf(stderr,"errore nel nemico (%s)",id);
                   }
  
  }


}

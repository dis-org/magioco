#include "universal.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern Data_t Local;
int line= 0;

void test_story(_Bool all){
  char temp[128]= "Start";
  FILE *t1, *t2, *t3;
  t1=fopen("custom/events.txt","r");
  t2=fopen("custom/enemies.txt","r");
  t3=fopen("custom/items.txt","r");
  if(!t1 || !t2 || !t3)
    folders_error();
  if(all)
    test_event(t1,t2,t3,temp,&line);
  fclose(t1); 
  fclose(t2);
  fclose(t3);
}

void test_event(FILE* events, FILE* enemies, FILE* items, char* id,int* line){
  rewind(events);
  char *temp,*semp;
  char x;
      controlt(events,'/','\n',id);
      do{
    x=getc(events);
    if (c == EOF) //errore;
    if ( c == '-') // errore ;
    if (c=='\n') line++;
  }while(c!='*');
      while(x=='*' || x=='>' || x=='#'){
	test_move('-',events);
	x=getc(events);
	if (x=='i'){
	  
	  temp=test_string(events,'.');
	  x=getc(events);
	  semp=test_string(events,'\n');
	  if (number(semp)){
	    // errore
	  }
	  test_item(items,temp);
	}
	if (x=='e'){
	  x=getc(events);
	  temp=sstring(events,'\n');
	  test_enemy(enemies,temp);
	}
      }
      if (x=='*'){
	id=sstring(events,'\n');
	test_choice(events, enemies, items,id);
	return;
      }
      if (x=='>'){
	id=sstring(events,'\n');
	test_event(events,items,enemies,id);
	free(id);
	return;
      }
      if (x=='#'){
	return;
      }
      // errore
    }



/*void test_choice(FILE* events,FILE* enemies,FILE* items,char* id){*/
/*  char *temp;*/
/*  rewind(events);*/
/*  while (feof(events)){*/
/*    move('+', events);*/
/*    temp=sstring(events,'\n');*/
/*    if (!strcmp(id,temp)){*/
/*      while(1){*/
/*        move('/', events);*/
/*        temp=sstring(events,'\n');*/
/*        if(!strcmp(temp,"#")) return;*/
/*        test_event(events, enemies, items, temp, line);*/
/*      }*/
/*      fprintf(stderr,"errore nell' evento scelta (%s)\n",id); //OUTPUT*/
/*      exit(EXIT_FAILURE);*/
/*      return;*/
/*    }*/
/*    // errore*/
/*  }*/


/*void test_item(FILE* pf, char* id){*/
/*  char *temp;*/

/*  pf = fopen("custom/items.txt","r");*/
/*  if (!pf){ */
/*    fprintf(stderr,"Errore: impossibile aprire items.txt\n"); //OUTPUT*/
/*    exit(EXIT_FAILURE);*/
/*  }*/
/*  while (feof(pf)){*/
/*    move('/',pf);*/
/*    temp=sstring(pf,'.');*/
/*    if (!strcmp(id,temp)){*/
/*      free(temp);*/
/*      temp=sstring(pf,'.');*/
/*      if ( *temp!='p' && *temp!='u' ){*/
/*        fprintf(stderr,"errore nell' oggetto (%s)\n",id); //OUTPUT*/
/*        exit(EXIT_FAILURE);*/
/*        return;*/
/*      }*/
/*      free(temp);*/
/*      temp=sstring(pf,'.');*/
/*      if (number(temp)){*/
/*        fprintf(stderr,"errore nell' oggetto (%s)\n",id); //OUTPUT*/
/*        exit(EXIT_FAILURE);*/
/*        return;*/
/*      }*/
/*      free(temp);*/
/*      temp=sstring(pf,'.');*/
/*      if (number(temp)){*/
/*        fprintf(stderr,"errore nell' oggetto (%s)\n",id); //OUTPUT*/
/*        exit(EXIT_FAILURE);*/
/*        return;*/
/*      }*/
/*      free(temp);*/
/*      temp=sstring(pf,'\n');*/
/*      if (number(temp)){*/
/*        fprintf(stderr,"errore nell' oggetto (%s)\n",id); //OUTPUT*/
/*        exit(EXIT_FAILURE);*/
/*        return;*/
/*      }*/
/*      free(temp);*/
/*                    */
/*    }*/
/*  }*/
/*  return; */
/*}*/

/*void test_enemy(FILE* pf,char* id){*/
/*  char *temp;*/
/*  char x;*/

/*  pf = fopen("custom/enemies.txt","r");*/
/*  if (!pf){ */
/*    fprintf(stderr,"Errore: impossibile aprire enemies.txt\n"); //OUTPUT*/
/*    exit(EXIT_FAILURE);*/
/*  }*/
/*  while (feof(pf)){*/
/*    move('/',pf);*/
/*    temp=sstring(pf,'.');*/
/*    if (!strcmp(id,temp)){*/
/*      free(temp);*/
/*      temp=sstring(pf,'.');*/
/*      if  (number(temp)){*/
/*        fprintf(stderr,"errore nel nemico (%s)\n",id); //OUTPUT*/
/*        exit(EXIT_FAILURE);*/
/*        return;*/
/*      }*/
/*      temp=sstring(pf,'\n');*/
/*      if  (number(temp)){*/
/*        fprintf(stderr,"errore nel nemico (%s)\n",id); //OUTPUT*/
/*        exit(EXIT_FAILURE);*/
/*        return;*/
/*      }*/
/*      move('-',pf);*/
/*      x=getc(pf);*/
/*      getc(pf);*/
/*      if (x!='r' && x!='m' && x!='d' && x!='#'){*/
/*        fprintf(stderr,"errore nel nemico (%s)\n",id); //OUTPUT*/
/*        exit(EXIT_FAILURE);*/
/*        return;*/
/*      }*/
/*      if (x=='#'){*/
/*        return;*/
/*      }*/
/*      x=getc(pf);*/
/*      if (isdigit(x)){*/
/*        fprintf(stderr,"errore nel nemico (%s)\n",id); //OUTPUT*/
/*        exit(EXIT_FAILURE);*/
/*        return;*/
/*      }*/
/*    }*/
/*  }*/
/*  fprintf(stderr,"errore nel nemico (%s)\n",id); //OUTPUT*/
/*  exit(EXIT_FAILURE);*/
/*  return;*/
/*}*/

int number(char *num){ // fine
  char x='n';
  int i=0;

  while (x=='n'){
    if (num[i]=='\0'){
      x='s';
      continue;
    }
    if(num[i]<'0' || num[i]>'9') return 3;
    i++;
  }
  return 0;
}

void test_move( char a, FILE* pf){// fine
  char c;
  do{
    c=getc(pf);
    if (c == a) return;
    if (c=='\n') line++;
  }while(c!=EOF);
  // errore end of file
}

 controlt(FILE* pf,char f,char m,char* id){ //fine 
   char *temp;
   if (!x) 
     alloc_error(__func__);
 do{ 
   test_move(f,pf); 
   temp = test_string(pf,m); 
  }while (strcmp(temp,id));
 free(temp); 
 } 

char* test_string(FILE *pf,char m){// fine
  char a;
  int i= 0;
  char *x=calloc(128,sizeof(char));
  if (!x)
    alloc_error(__func__);
  do{
    a=getc(pf);
    if(a==m){
      return x;
    }
    *(x+i)=a;
    i++;
  }while(i<= 128);
  //errore
  return NULL;
}

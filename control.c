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
     puts("evento");
    test_event(t1,t2,t3,temp);
  fclose(t1); 
  fclose(t2);
  fclose(t3);
}

void test_event(FILE* events, FILE* enemies, FILE* items, char* id){
  rewind(events);
  char *temp,*semp;
  char x;
      controlt(events,'/','\n',id);
      do{
    x=getc(events);
    if (x == EOF)  puts("errore1");//errore;
    if (x == '-')  puts("errore2");// errore ;
    if (x =='\n') line++;
  }while(x!='*');
      do{
         test_move('-',events);
	x=getc(events);
	if (x =='*' || x =='>' || x =='#' ) break;
	if (x=='i'){
	  x=getc(events);
	  temp=test_string(events,'.');
	  semp=test_string(events,'\n');
	  if (number(semp)){
	    // errore
	    puts("errore3");
	  }
	  //test_item(items,temp);
	  puts("oggetto");
	  free(temp);
	  free(semp);
	}
	if (x=='e'){
	  x=getc(events);
	  temp=test_string(events,'\n');
	  //test_enemy(enemies,temp);
	  puts("nemico");
	  free(temp);
	}
      }while(1);
      if (x=='*'){
	id=test_string(events,'\n');
	puts("scelta");
	test_choice(events, enemies, items,id);
	free(id);
	
	return;
      }
      if (x=='>'){
	id=test_string(events,'\n');
	puts("evento");
	test_event(events,items,enemies,id);
	free(id);
	
	return;
      }
      if (x=='#'){
      puts("fine");
	return;
      }
      puts("errore4");
      // errore
    }



void test_choice(FILE* events,FILE* enemies,FILE* items,char* id){
  rewind(events);
  char *temp;
      controlt(events,'+','\n',id);
      while(1){
        move('/', events);
        temp=test_string(events,'\n');
        if(temp[0]=='#') return;
        puts("evento");
        test_event(events, enemies, items, temp);
        free(temp);
      }
      puts ("errore scelta");
    }
  


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
   puts("errorem");
  // errore end of file
}

void controlt(FILE* pf,char f,char m,char* id){ //fine 
   char *temp;
 do{ 
   test_move(f,pf); 
   temp = test_string(pf,m); 
  }while (strcmp(temp,id));
 free(temp); 
 } 

char* test_string(FILE *pf,char m){// fine
  char a;
  
  char *x=calloc(128,sizeof(char));
  if (!x)
     puts("errorea");//alloc_error(__func__);

   for (int i=0;i<=128;i++){
    a=getc(pf);
    if(a==m){
    printf("\n");
      return x;
    }
    *(x+i)=a;
    printf("%d  ",i);
  }
   puts("erroree qio");
  //errore
  return NULL;
}

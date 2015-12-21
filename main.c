#include "universal.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Data_t Local;
_Bool buffered;

int main()
{
  _Bool on= 1;

  Local.state='m';
  Local.previous='q';
  Local.chosen= 1;
  Local.health= 3;

  next_page();
  print_intro();
  press_a();

  while(on)
    {
      next_page();

      if(!Local.health)
        Local.state='g';

      if(Local.Battle.enemies)
        Local.state='b';

      switch(Local.state)
        {
        case'm':
          print_menu();
          if(choice(&Local.chosen, 3))
            switch(Local.chosen)
              {
              case 1:
                readsaves();
                do{
                  next_page();
                  print_Choices(&Local.Events,Local.chosen);
                }while(!choice(&Local.chosen, Local.Events.choices)&& Local.state!='q');
                if(Local.Events.choices && Local.state!='q')
                  {
                    select(&Local.Events, Local.name, Local.chosen);
                    //deleteChoices(&Local.Events);
                    load();//fosse così facile...
                  }
                Local.chosen= 1;
                continue;
              case 2:
                next_page();
                if(new_name())
                  {
                    Local.state='t';
                    Local.phase='i';
                    strcpy(Local.id,"Start");
                    Local.chosen= 1;
                    Local.enemy_chosen= 0;
                    Local.item_chosen= 1;
                    Local.use_chosen= 1;
                    Local.health= 3;
                    save();
                  }
                press_a();
                continue;
              case 3:
                next_page();
                print_ahah();
                Local.chosen= 1; //*
                press_a();
                continue;
              }
          else
            continue;
        case't':
          readevent();
          press_a();
          continue;
        case'c':
          readchoices();
          print_Choices(&Local.Events, Local.chosen);
          if(choice(&Local.chosen, Local.Events.choices))
            {
              select(&Local.Events, Local.id, Local.chosen);
              Local.state='t';
              Local.chosen= 1;
            }
          continue;
        case'b':
          battle();
          continue;
        case'g':
          print_gameover();
          press_a();
          if(Local.state=='q')
            on=0;
          else
            {
              deleteChoices(&Local.Events);
              //deleteItems(&Local.Bag);
              //deleteEnemies(...);
              Local.state='m';
            }
          continue;
        case'q':
          print_quit();
          if(choice(&Local.chosen, 3))
            switch(Local.chosen)
              {
              case 1:
		if(Local.previous!='m')
		  {
		    switch_state();                
		    save();//da controllare
		    switch_state();
		    press_a();
		  }
                continue;
              case 2:
                deleteChoices(&Local.Events);
                //deleteItems(&Local.Bag);
                //deleteEnemies(...);
                Local.chosen= 1; //* 
                Local.state='m';
                Local.previous='q';
                continue;
              case 3:
                on= 0;
                continue;
              }
        }
    }
  next_page();
  return 0;
}

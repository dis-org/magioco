#include "universal.h"

extern Data_t Local;

void battle(void)
{
  Item_t *Item, *G;
  Enemy_t* Enemy;
  Action_t* Action;

  if(!Local.Battle.enemies)
    {
      G= Local.Ground.First;
      for(int x= 0; x<Local.Ground.items; x++)
        {
          Item= addItem(&Local.Bag);
          Item->Info= G->Info;
          G= G->Next;
        }
      deleteItems(&Local.Ground);
      Local.state='t';
      return;
      //****
    }

  print_Enemies();
  print_stats();
  switch(Local.phase)
    {
    case'i':
      print_Items();
      if(!Local.Bag.items && !Local.defending)
	{
	  if(press_a())
	    Local.phase='a';
	}
      else if(choice(&Local.item_chosen, Local.Bag.items+Local.defending))
	{
	  if(Local.item_chosen==Local.Bag.items+1)
	    {
	      Local.defending= 0;
              Local.defence= 0;
              Item= addItem(&Local.Bag);
              Item->Info= Local.Defending;
            }
          Local.phase='u';
        }
      break;
    case'u':
      print_Uses(item_sel());
      if(choice(&Local.use_chosen, 3))
        {
          switch(Local.use_chosen)
            {
            case 1: //usa
              Local.enemy_chosen= 1;
              Local.phase='1';
              break;
            case 2: //lancia
              Local.enemy_chosen= 1;
              Local.phase='2';
              break;
            case 3: //difenditi
              if(Local.defending)
                {
                  Item= addItem(&Local.Bag);
                  Item->Info= Local.Defending;
                }
              Item= item_sel();
              Local.defence= Item->Info.defvalue;
              Local.Defending= Item->Info;
              deleteItem(&Local.Bag, Item);
              Local.defending= 1;
              Local.phase='a';
              break;
            }
          break;
        }
      else if(Local.state=='q')
        {
          switch_state();
          Local.phase='i';
        }
      break;
    case'1':
      Item= item_sel();
      print_sel(Item);
      if(choice(&Local.enemy_chosen, Local.Battle.enemies+1))
        {
          if(Local.enemy_chosen== Local.Battle.enemies+1)
            {
              Local.enemy_chosen= 0;
              self_damage(Item->Info.damage);
            }
          if(!--Item->Info.uses)
            deleteItem(&Local.Bag, Item);
          Local.phase='a';
        }
      else if(Local.state== 'q')
        {
          switch_state();
          Local.enemy_chosen= 0;
          Local.phase='u';
        }
      break;
    case'2':
      Item= item_sel();
      print_sel(Item);
      if(choice(&Local.enemy_chosen, Local.Battle.enemies))
        {
          if(Item->Info.type=='u')
            {
              G= addItem(&Local.Ground);
              G->Info= Item->Info;
              deleteItem(&Local.Bag, Item);
            }
          else if(!--Item->Info.uses)
            deleteItem(&Local.Bag, Item);
          if(Local.defending)
            {
              Item= addItem(&Local.Bag);
              Item->Info= Local.Defending;
              Local.defending= 0;
              Local.defence= 0;
            }
          Local.ranged= 1;
          Local.phase='a';
        }
      else if(Local.state== 'q')
        {
          switch_state();
          Local.enemy_chosen= 0;
          Local.phase='u';
        }
      break;
    case'a':
      Enemy= Local.Battle.First;
      for(int x=1; x<Local.current_enemy; x++)
        Enemy= Enemy->Next;
      Action= Enemy->First;
      print_Action(Enemy);
      press_a();

      //azione nemica
      switch(Action->Info.type)
        {
        case'm':
          if(Local.ranged)
            break;
          else if(Local.defending)
            {
              if(Local.Defending.type=='p') //da decidere se si perde del tutto o no
                Local.defending=0;
              else if(Local.defence)
                resist(Action->Info.value);
              if(Local.defence)
                {
                  Local.defence--;
                  if(!Local.defence)
                    {
                      Item= addItem(&Local.Bag);
                      Item->Info= Local.Defending;
                      Local.defending= 0;
                    }
                }
            }
          else
            self_damage(Action->Info.value);
          break;
        case'r':
          if(Local.defence)
            if(Local.Defending.defvalue < Action->Info.value)
              self_damage(Action->Info.value);
            else
              resist(Action->Info.value);
          else
            self_damage(Action->Info.value);
          break;
        case'd':
          Enemy->Info.defence= Action->Info.value;
        }

      //attacco del giocatore (solo se il nemico attuale è il bersaglio dell'attacco
      if(Enemy==enemy_sel() && !Local.defending)
        {
          Item= item_sel();
          if(!Local.ranged)
            {
              if(Action->Info.type!='r')
                enemy_damage(Enemy, Item->Info.damage);
            }
          else if(!Enemy->Info.defence)
            {
              if(!Item)
                Item= Local.Ground.Last;
              enemy_damage(Enemy, Item->Info.trowvalue);
            }
        }
      
      Enemy->Last->Next= Action;
      Enemy->First= Action->Next;
      Enemy->Last= Action;
      Action->Next= NULL;
      if(Enemy->Next)
        Local.current_enemy++;
      else
        {
          Local.use_chosen= 1;
          Local.item_chosen= 1;
          Local.enemy_chosen= 0;
          Local.current_enemy= 1;
          Local.ranged= 0;
          Local.phase='i';
        }
      break;
    }
}

Enemy_t* enemy_sel()
{
  if(!Local.enemy_chosen)
    return NULL;
  Enemy_t* Temp= Local.Battle.First;
  for(int x=1; x<Local.enemy_chosen; x++)
    Temp= Temp->Next;
  return Temp;
}

Item_t* item_sel()
{
  if(!Local.item_chosen)
    return NULL;
  Item_t* Temp= Local.Bag.First;
  for(int x=1; x<Local.item_chosen; x++)
    Temp= Temp->Next;
  return Temp;
}

void enemy_damage(Enemy_t* Enemy, int damage) //danno al nemico (compresa difesa)
{
  if(damage>=0)
    {
      while(damage--)
        if(Enemy->Info.defence)
          Enemy->Info.defence-= 1;
        else if(Enemy->Info.health)
          Enemy->Info.health-= 1;
      if(!Enemy->Info.health)
        deleteEnemy(&Local.Battle, Enemy);
    }
  else if(damage)
    Enemy->Info.health-= damage;
}

void self_damage(int damage) //danno diretto alla vita del giocatore
{
  if(damage>=0)
    for(int x= 0; x<damage && Local.health; x++)
      Local.health-= 1;
  else
    Local.health-= damage;
}

void resist(int damage) //danno al gicatore difeso
{
  for(int x= 0; x<damage; x++)
    if(!--Local.Defending.uses)
      {
	Local.defending= 0;
	break;
      }
}

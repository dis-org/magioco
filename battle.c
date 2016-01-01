#include "universal.h"
#include <stdio.h>

extern Data_t Local;

void battle(void)
{
  Item_t* Item;
  //  Item_t* Blocking;

  print_Enemies();
  print_Stats();
  switch(Local.phase)
    {
    case'i':
      print_Items();
      if(choice(&Local.item_chosen, Local.Bag.items))
        Local.phase='u';
      break;
    case'u':
      Item= item_sel();
      print_Uses(Item);
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
	      Local.defence= Item->Info.defvalue;
	      Item->Info.uses-= 1; //sia u che p ...sicuro?
	      if(!Item->Info.uses)
		deleteItem(&Local.Bag, Item);
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
      print_Sel(Item);
      Use(Item);
      break;
    case'2':
      Trow(item_sel());
      break;
    case 'a':
      /* Action(); */
      puts("missing");
      press_a();
      Local.ranged= 0;
      Local.phase= 'i';
      break;
    }
}

 Enemy_t* enemy_sel()
{
  Enemy_t* Temp= Local.Battle.First;
  for(int x=1; x<Local.enemy_chosen; x++)
    Temp= Temp->Next;
  return Temp;
}

Item_t* item_sel()
{
  Item_t* Temp= Local.Bag.First;
  for(int x=1; x<Local.item_chosen; x++)
    Temp= Temp->Next;
  return Temp;
}

void value(unsigned short* health, unsigned short* defence, int usevalue)
{
  if(usevalue<0)
    for(int x= 0; x > usevalue && *health; x--)
      if(*defence)
	*defence-= 1; //resist();
      else
	*health-= 1;
  else
    *health+= usevalue;
}

void Use(Item_t* Item)
{
  if(choice(&Local.enemy_chosen, Local.Battle.enemies+1))
    {
      if(Local.enemy_chosen== Local.Battle.enemies+1)
	value(&Local.health, &Local.defence, Item->Info.usevalue);
      else
	{
	  Enemy_t* Enemy= enemy_sel();
	  value(&Enemy->Info.health, &Enemy->Info.defence, Item->Info.usevalue);
	}
      Local.phase= 'a';
      Local.enemy_chosen= 0;
      Item->Info.uses-= 1; //sia u che p ...sicuro?
      if(!Item->Info.uses)
	deleteItem(&Local.Bag, Item);
    }
  else if(Local.state== 'q')
    {
      switch_state();
      Local.enemy_chosen= 0;
      Local.phase='u'; // chosen?
    }
}

void Trow()
{
  if (choice(&Local.enemy_chosen, Local.Battle.enemies))
    {
      enemy_sel();
      item_sel();
      if (Local.Battle.First->Info.defence)  //trow<def
        NULL;
      else              //trow>use
        Local.Battle.First->Info.health += Local.Bag.First->Info.trowvalue;
    }
  if (Local.Bag.First->Info.type=='u')
    /* deleteItem(&Local.Bag, Local.Bag.First->Info.name) */;    
  else
    Local.Bag.First->Info.uses-= 1;
}

void Action()
{
  if (Local.Battle.First->First->Info.type=='d')                
    Local.Battle.First->Info.defence += Local.Battle.First->First->Info.value;
  else if (Local.Battle.First->First->Info.type=='u' && Local.Battle.First->First->Info.value > 0)              //usa su se stesso, discutibile (lo vogliamo fare?)
    Local.Battle.First->Info.health += Local.Battle.First->First->Info.value;
  else
    {
      if (Local.defence)        
        {
          if(Local.Battle.First->First->Info.type=='u')         
            Local.defence=0;                                                            
          else
            NULL;
        }
      else      
        {
          if(Local.Battle.First->First->Info.type=='u') 
            {
              if (Local.use_chosen==3)  //se l'ultimo item usato era di tipo trow (u vs t)
                NULL;
              else                                              //u vs u
                Local.health += Local.Battle.First->First->Info.value;
            }
          else          //t vs t, t vs u 
            Local.health += Local.Battle.First->First->Info.value;
        }
    }
  Local.Battle.First->Last->Next = Local.Battle.First->First;
  Local.Battle.First->First = Local.Battle.First->First->Next;
  printf ("%s\n\nPremere 'a' continuare.\n", Local.Battle.First->First->Info.text);      //discutibile anche questo ahah
  press_a();    

}


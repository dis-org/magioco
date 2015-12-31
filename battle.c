#include "universal.h"
#include <stdio.h>

extern Data_t Local;

void battle(void)
{
  print_Enemies();
  print_Stats();
  switch(Local.phase)
    {
    case'i':
      print_Items();
      if(choice(&Local.item_chosen, Local.Bag.items))
        Local.phase='u';
      break;
    case 'u':
      print_Uses(item_sel());
      if(choice(&Local.use_chosen, 3))
	{
	  switch(Local.use_chosen)
	    {
	    case 1: //usa su di te
	      Use();
	      break;
	    case 2: //lancia
	      Trow();
	      break;
	    case 3: //difenditi
	      item_sel();
	      Local.defence += Local.Bag.First->Info.defvalue;
	      Local.Bag.First->Info.uses-= 1; //sia u che p ...sicuro?
	      break;
	    }
	  Local.phase='a';
	  break;
	}
      else if(Local.state=='q')
	{
	  switch_state();
	  Local.phase='i';
	}
      break;
    case 'a':
      print_Items();
      Action();
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

void Use()
{
  if(choice(&Local.enemy_chosen, Local.Battle.enemies+1))
    {
      
    }
}

void enemy_Use()
{
  //Sono decisamente convinto che non funzionerà.
  if (choice(&Local.enemy_chosen, Local.Battle.enemies))
    {
      enemy_sel();
      item_sel();
      if (Local.Bag.First->Info.usevalue>=0) 
        Local.Battle.First->Info.health += Local.Bag.First->Info.usevalue; 
      else
        {
          if (Local.Battle.First->Info.defence)      //il nemico ha difesa (use>def)
            Local.Battle.First->Info.defence=0;
          else
            {
              if(Local.Battle.First->First->Info.type=='t')  //il nemico non ha difsa, e la sua azione sarà di trow (use<trow)
                NULL; 
              else
                Local.Battle.First->Info.health += Local.Bag.First->Info.usevalue;
            }
        }
    } 

  if(Local.Bag.First->Info.type=='u')        //se è unitario, diminuisco la durata
    Local.Bag.First->Info.uses--;
  else
    deleteItem(&Local.Bag, Local.Bag.First->Info.name);    //se è pluritatrio lo elimino (lo volevamo così, boh?)
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
    deleteItem(&Local.Bag, Local.Bag.First->Info.name);    
  else
    Local.Bag.First->Info.uses-= 1;
}

void Action ()
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


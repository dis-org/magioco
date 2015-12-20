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
      print_Uses();
      if (choice(&Local.use_chosen, 5))
        switch(Local.use_chosen)
          {
          case 1: //usa su di te
          	item_sel();
            Local.health += Local.Bag.First->usevalue;
            Local.Bag.First->uses--; //sia u che p
            break;
          case 2: //usa su nemico
            enemy_Use();
            break;
          case 3: //lancia
            Trow();
            break;
          case 4: //difenditi
            item_sel();
			Local.defence += Local.Bag.First->defvalue;
			Local.Bag.First->uses--; //sia u che p
            break;
          case 5: //tora all'inventario
            break;  
          }
      if (Local.Battle.First->health==0)
  		/*deleteEnemy(Local.Battle.First);*/	//ha poco senso a definizione, da riguaardare
  	  if(Local.Bag.First->uses==0)
  		/*deleteItem(Local.Bag.First);*/	//ha poco senso a definizione, da riguaardare
      Local.phase= Local.use_chosen==5 ? 'i':'a';
      break;
    case 'a':
      print_Items();
      //azioni
      break;
    }
}


Enemy_t* enemy_sel()
{
	for(int x=1; x<Local.Battle.enemies; x++)
	{
		if (Local.enemy_chosen==x)
			break;
		else
		{
			Local.Battle.First= Local.Battle.First->Next;	
        	continue;
      	}
	}
	return Local.Battle.First;
}

Item_t* item_sel()
{
	for(int x=1; x<Local.Bag.items; x++)
	{
		if(Local.item_chosen==x)
			break;
		else
		{
			Local.Bag.First= Local.Bag.First->Next;
			continue;
		}
	}
	return Local.Bag.First;
}

void enemy_Use()
{
  //Sono decisamente convinto che non funzionerà.
  if (choice(&Local.enemy_chosen, Local.Battle.enemies))
    {
     enemy_sel();
     item_sel();
     if (Local.Bag.First->usevalue>=0)	
   	   Local.Battle.First->health += Local.Bag.First->usevalue; 
   	 else
   	  {
   	    if (Local.Battle.First->defence)	//il nemico ha difesa (use>def)
   	      Local.Battle.First->defence=0;
   	    else
   	     {
   	    	if(Local.Battle.First->First->type=='t')	//il nemico non ha difsa, e la sua azione sarà di trow (use<trow)
   	    		NULL; //lol?
   	    	else
   	    		Local.Battle.First->health += Local.Bag.First->usevalue;
   	  	 }
   	  }
    } 

  if(Local.Bag.First->type=='u')	//se è unitario, diminuisco la duarta
  	Local.Bag.First->uses--;
  else
 /*deleteItem(Local.Bag.First);*/	//ha poco senso a definizione, da riguaardare	//se è pluritatrio li elimino (lo volevamo così, boh?)
}

void Trow()
{
	if (choice(&Local.enemy_chosen, Local.Battle.enemies))
	{
		enemy_sel();
		item_sel();
		if (Local.Battle.First->defence)	//trow<def
			NULL; //LOL?
		else		//trow>use
			Local.Battle.First->health += Local.Bag.First->trowvalue;
	}
	if (Local.Bag.First->type=='u')
		/*deleteItem(Local.Bag.First);*/	//ha poco senso a definizione, da riguaardare
	else
		Local.Bag.First->uses--;
}
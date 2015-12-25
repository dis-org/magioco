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
            Local.health += Local.Bag.First->Info.usevalue;
            Local.Bag.First->Info.uses--; //sia u che p
            break;
          case 2: //usa su nemico
            enemy_Use();
            break;
          case 3: //lancia
            Trow();
            break;
          case 4: //difenditi
            item_sel();
            Local.defence += Local.Bag.First->Info.defvalue;
            Local.Bag.First->Info.uses--; //sia u che p
            break;
          case 5: //tora all'inventario
            break;  
          }
      if (Local.Battle.First->Info.health==0)
        deleteEnemy(&Local.Battle, Local.Battle.First->Info.name);        
      if(Local.Bag.First->Info.uses==0)
        deleteItem(&Local.Bag, Local.Bag.First->Info.name);          
      Local.phase= Local.use_chosen==5 ? 'i':'a';
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

  if(Local.Bag.First->Info.type=='u')        //se è unitario, diminuisco la duarta
    Local.Bag.First->Info.uses--;
  else
    deleteItem(&Local.Bag, Local.Bag.First->Info.name);    //se è pluritatrio li elimino (lo volevamo così, boh?)
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
    Local.Bag.First->Info.uses--;
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
  printf ("%s\n\nPremere 'a'continuare.\n", Local.Battle.First->First->Info.text);      //discutibile anche questo ahah
  press_a();    

}


#include "var.h"

void addAction(Enemy_t* Enemy, char* text, char type, short value);
void addEnemy(char* name, short health, short defence);
void addItem(Item_List* List, char* name, char type, int usev, unsigned short trwv, unsigned short defv, int uses);
item_t* serch(){
 item_t *temp;
 temp=bag.first;
 while (temp!=NULL){
  if (!strcmp(id,temp->name)){
   break;
  }
                                              
  temp=temp->next;
 }
  return temp; 
}

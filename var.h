//variabili universali
#include "struct.h"
char state;	
char phase; //tipo state, ma per il combattimento
_Bool buffered;
char id[128];
short event_chosen;
short enemy_chosen;
short item_chosen;
short use_chosen;
char name[64];
short health;
short defence;
Choice_List Events;
Item_List Bag;
Enemy_List Battle;

//variabili universali
#include "struct.h"
char state;
_Bool buffered;
char id[128];
short event_chosen;
short enemy_chosen;
short item_chosen;
short use_chosen;
Choice_List Events;
Choice_List Uses; //possibili utilizzi degli oggetti (predefinito)
Choice_List Items; //?
Choice_List Enemies; //?? non so se serve
Item_List Bag;
Enemy_List Battle;

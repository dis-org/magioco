//variabili universali
#include "struct.h"
<<<<<<< HEAD
char state;	
char phase; //tipo state, ma per il combattimento
=======
char state;
>>>>>>> 1bd6d5dd5c5a9b63228d2b0f6515f51b56fe58c5
_Bool buffered;
char id[128];
short event_chosen;
short enemy_chosen;
short item_chosen;
short use_chosen;
<<<<<<< HEAD
char name[64];
short health;
short defence;
Choice_List Events;
=======
Choice_List Events;
Choice_List Uses; //possibili utilizzi degli oggetti (predefinito)
Choice_List Items; //?
Choice_List Enemies; //?? non so se serve
>>>>>>> 1bd6d5dd5c5a9b63228d2b0f6515f51b56fe58c5
Item_List Bag;
Enemy_List Battle;

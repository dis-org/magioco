//Choices
typedef struct Choice{ //possibili opzioni
  char text[128];//convertire tutto a stringa di testo
  struct Choice* Next;
} Choice_t;

typedef struct{ //ogni scelta è una lista di opzioni
  char text[128];
  unsigned short choices;
  Choice_t* First;
  Choice_t* Last;
} Choice_List_t;

//Enemies
typedef struct{
  char text[256];
  char type;
  short value;
} Action_Data_t;

typedef struct Action{
  Action_Data_t Info;
  struct Action* Next;
} Action_t;

typedef struct{
  char name[64];
  unsigned short health;
  unsigned short defence;
  unsigned short actions;
} Enemy_Data_t;

typedef struct Enemy{ //ogni nemico contine una lista dinamica di azioni
  Enemy_Data_t Info;
  Action_t* First;
  Action_t* Last; //quando un'azione viene compiuta va spostata in fondo alla lista
  struct Enemy* Next;
} Enemy_t;

typedef struct{
  unsigned short enemies;
  Enemy_t* First;
  Enemy_t* Last;
} Enemy_List_t; //doppiamente dinamica

//Items
typedef struct{
  char name[64]; //da rivedere
  char type; //unitario 'u' o pluritario 'p'
  int damage; //positivo= danno, negativo= vita
  unsigned short trowvalue; 
  unsigned short defvalue; 
  int resistence;
  int quantity;
} Item_Data_t;

typedef struct Item{
  Item_Data_t Info;
  struct Item* Next;
} Item_t;

typedef struct{
  unsigned short items;
  Item_t* First;
  Item_t* Last;
} Item_List_t;

//Local data
typedef struct Data{
  char name[32];
  char id[128];;
  char state;
  char previous;
  char phase; //tipo state, ma per il combattimento
  _Bool done;
  short chosen;
  short enemy_chosen;
  short item_chosen;
  short use_chosen;
  unsigned short health;
  unsigned short defence; //difesa (solo in combattimento)
  _Bool ranged; //se corpo a corpo o a distanza (0= corpo a corpo)
  _Bool defending;
  short current_enemy;
  Choice_List_t Events;
  Item_List_t Bag;
  Item_List_t Ground; //oggetti persi in combattimento
  Item_Data_t Defending;
  Enemy_List_t Battle;
} Data_t;

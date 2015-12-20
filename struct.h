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
  char name[64]; //con un nome
  unsigned short health;
  unsigned short defence;
  unsigned short actions;
} Enemy_Data_t;

typedef struct Enemy{ //ogni nemico è una lista dinamica di azioni
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

typedef struct{
  char name[64];
  char type; //unitario 'u' o pluritario 'p' cambia la scritta tra durata e quantità
  int usevalue; //sia su nemici che su se stessi
  unsigned short trowvalue; //i danni che fa al nemico se scagliata su di esso
  unsigned short defvalue; //magari indica anche quanta durata consuma
  int uses; //viene modificato in modo diverso a seconda del tipo
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

typedef struct Data{
  char state;
  char previous;
  char phase; //tipo state, ma per il combattimento
  _Bool buffered;
  char id[128];
  short chosen;
  short enemy_chosen;
  short item_chosen;
  short use_chosen;
  char name[32];
  unsigned short health;
  unsigned short defence; //difesa (solo in combattimento)*
  _Bool ranged; //se corpo a corpo o a distanza (0= corpo a corpo)*
  Choice_List_t Events;
  Item_List_t Bag;
  Enemy_List_t Battle;
} Data_t;
//* queste variabili non sono inizializzate nel main e potrebbero riportare valori precedenti, da inizializzare in battle()

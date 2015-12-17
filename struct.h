typedef struct Choice{ //possibili opzioni
  char text[128];//convertire tutto a stringa di testo
  struct Choice* Next;
} Choice_t;

typedef struct{ //ogni scelta è una lista di opzioni
  char text[128];
  unsigned short choices;
  Choice_t* First;
  Choice_t* Last;
} Choice_List;

typedef struct Action{
  char text[256];
  char type;
  short value;
  struct Action* Next;
} Action_t;

typedef struct Enemy{ //ogni nemico è una lista dinamica di azioni
  char name[64]; //con un nome
  short health;
  short defence;
  Action_t* First;
  Action_t* Last; //quando un'azione viene compiuta va spostata in fondo alla lista
  struct Enemy* Next;
} Enemy_t;

typedef struct{
  unsigned short enemies;
  Enemy_t* First;
  Enemy_t* Last;
} Enemy_List; //doppiamente dinamica

typedef struct Item{
  char name[64];
  char type; //unitario 'u' o pluritario 'p' cambia la scritta tra durata e quantità
  int usevalue; //sia su nemici che su se stessi
  unsigned short trowvalue; //i danni che fa al nemico se scagliata su di esso
  unsigned short defvalue; //magari indica anche quanta durata consuma
  int uses; //viene modificato in modo diverso a seconda del tipo
  struct Item* Next;
} Item_t;

typedef struct{
  unsigned short items;
  Item_t* First;
  Item_t* Last;
} Item_List;

typedef struct Data{
  char state;	
  char phase; //tipo state, ma per il combattimento
  _Bool ranged; //se corpo a corpo o a distanza (0= corpo a corpo)
  _Bool buffered;
  char id[128];
  short chosen;
  short enemy_chosen;
  short item_chosen;
  short use_chosen;
  char name[64];
  short health;
  short defence;
  Choice_List Events;
  Item_List Bag;
  Enemy_List Battle;
} Data_t;

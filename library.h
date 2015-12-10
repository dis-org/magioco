// tutte le strutture e i programmi per utilizzarle

typedef struct Event{
  char name[64]; //per lettura da file
  char text[128];
  char type;
  char 
  struct Event* Next;
} Event_t;

typedef struct{ //evento scelta come lista dinamica di eventi
  Event_t* First;
  Event_t* Last;
} Event_Choice;

typedef struct Action{
  char text[256];
  char type;
  short value;
} Action_t;

typedef struct Enemy{ //ogni nemico è una lista dinamica di azioni
  char name[64]; //con un nome
  Action_t* First;
  Action_t* Last; //quando un'azione viene compiuta va spostata in fondo alla lista
  struct Enemy* Next;
} Enemy_t;

typedef struct{
  Enemy_t* First;
  Enemy_t* Last;
} Enemy_List; //doppiamente dinamico

typedef struct Item{
  struct Info{
    char name[64];
    char type; //cosa fa
    short value; //come lo fa
    short uses; //utilizzi
  };
  struct Item* Next;
} Item_t;

typedef struct{
  Item_t* First;
  Item_t* Last;
} Item_List;

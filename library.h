// tutte le strutture e i programmi per utilizzarle

typedef struct Event{
  unsigned int id; //per lettura da file
  char type; //da unire con ID
  char choice_text[64];
  char text[1024];
  unsigned int range;
  struct Event* Next;
} Event_t;

typedef struct Action{
  char text[256];
  char type;
  short value;
} Action_t;

typedef struct Enemy{ //ogni nemico è una lista dinamica di azioni
  char name[64];
  Action_t* First;
  Action_t* Last;
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

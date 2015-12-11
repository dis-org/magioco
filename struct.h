typedef struct Choice{ //possibili opzioni
  char text[128];//convertire tutto a stringa di testo
  struct Choice* Next;
} Event_t;

typedef struct{ //ogni scelta è una lista di opzioni
  char text[256];
  Choice_t* First;
  Choice_t* Last;
} Choice_List;

typedef struct Action{
  char text[256];
  char type;
  short value;
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
  Enemy_t* First;
  Enemy_t* Last;
} Enemy_List; //doppiamente dinamico

typedef struct Item{
  struct Info{
    char name[64];
    short mvalue;
    short rvalue;
    short dvalue;
    int uses;
    int //da rivedere 
  };
  struct Item* Next;
} Item_t;

typedef struct{
  Item_t* First;
  Item_t* Last;
} Item_List;

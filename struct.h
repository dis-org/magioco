typedef struct Choice{ //possibili opzioni
  char text[128];//convertire tutto a stringa di testo
  struct Choice* Next;
} Choice_t;

typedef struct{ //ogni scelta è una lista di opzioni
  char text[128];
  Choice_t* First;
  Choice_t* Last;
} Choice_List;

typedef struct Action{
  char text[256];
  char type;
  unsigned short value;
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
} Enemy_List; //doppiamente dinamica

typedef struct Item{
  struct Info{
    char name[64];
    char type; //unitario 'u' o pluritario 'p' cambia la scritta tra durata e quantità
    int usevalue; //sia su nemici che su se stessi
    unsigned short trowvalue; //i danni che fa al nemico se scagliata su di esso
    unsigned short defvalue; //magari indica anche quanta durata consuma
    int uses; //viene modificato in modo diverso a seconda del tipo
  };
  struct Item* Next;
} Item_t;

typedef struct{
  Item_t* First;
  Item_t* Last;
} Item_List;

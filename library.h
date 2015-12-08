// tutte le strutture e i programmi per utilizzarle

typedef struct Event{
  unsigned int id; //per lettura da file
  char type; //da unire con ID
  char choice_text[64];
  char text[1024];
  unsigned int range;
  struct Event* Next;
} Event_t;

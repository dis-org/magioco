// tutte le strutture e i programmi per utilizzarle

typedef struct Event {
  unsigned int id; //per lettura da file
  char text[1024];
  unsigned short choices;
  char choice_text[3][64];
  struct Event* out; //da cambiare in unsigned int (id)
} Event_t;

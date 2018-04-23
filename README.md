      __  __                   __                       
     /  \/  \    ____    ____ /\_\   ____   ___   ____
    /\ \__/\ \  /  _ \  / __ \\/_/  / __ \ / __\ / __ \
    \ \ \_/ \ \/\ \_\ \/\ \_\ \/\ \/\ \_\ \\ \__/\ \_\ \
     \ \_\ \ \ \ \__/\_\ \__/\ \ \_\ \____/ \___\ \____/
      \/_/  \/_/\/_/\/_/\/\____/\/_/\/___/ \/___/\/___/ 
                         \/___/                         
    CREDITS TO:
    Filippo Mariani   FilMar
    Giorgio Mazza     Shizen39
    Claudio Pannacci  Kappanneo
    Lorenzo Santagà   santiasd

1. INTRODUZIONE

Gioco RPG testuale con eventi, oggetti e nemici letti da file di testo modificabili.

Il gioco è un susseguirsi di vari eventi lineari e scelte che porteranno il giocatore a trovare oggetti e ad usarli per sconfiggere vari nemici. In oltre, il giocatore avrà la possibilità di creare e personalizzare una storia (cfr. cap 7).

2. PREPARAZIONE

Per garantire il corretto funzionamento di Magioco è necessario che nella directory in cui è contenuto l'eseguibile "Magioco", siano presenti due cartelle nominate "saves" e "custom" (senza virgolette). La prima dovrà essere vuota, e conterrà i salvataggi che verranno creati nel corso del gioco. La seconda dovrà contenere tre file di testo, i quali costituiranno la storia di Magioco: 
  - events.txt (cfr. cap 7, par 1);
  - enemies.txt (cfr. cap 7, par 2);
  - items.txt (cfr. cap 7, par 3).


3. EVENTI 

Nel corso della storia il giocatore incontrerà eventi, i quali lo condurranno a scelte che porteranno a diramare la storia stessa. Questi eventi potranno presentarsi in forma diversa:
  - Eventi lineari: eventi composti da un testo ed una serie di avvenimenti come: guadagnare o perdere vita, ottenere oggetti, affrontare nemici;
  - Eventi scelta: fondamentalmente una raccolta di eventi lineari con un titolo, possono includere scelte condizionate che si possono selezionare solo avendo un oggetto nel proprio inventario.


4. NEMICI

Nella fase di combattimento, il giocatore si troverà a dover affrontare uno o più nemici contemporaneamente. Questi saranno caratterizzati da:
  - Nome;
  - Vita (1 punto vita è rappresentato da un '*');
  - Difesa (1 punto difesa è rappresentato da una ')');
  - Serie di azioni, che possono essere di tipo attacco (ravvicinato o a distanza) o di tipo difesa (cfr. cap 6).


5. OGGETTI

Il giocatore è fornito di un inventario oggetti, visualizzabile esclusivamente in fase di battaglia. Durante un evento scelta, il giocatore potrà trovare degli oggetti che saranno aggiunti al suo inventario, i quali saranno utilizzabili per superare un combattimento o un ulteriore evento scelta.
  
Gli oggetti si dividono in due classi principali:
  - Unitari: oggetti che possiedono una resistenza, consumata la quale l'oggetto sarà eliminato dall'inventario.
  - Pluritari: oggetti privi di resistenza, e per questo mono uso, ma cumulabili in più oggetti (quantità).

Gli oggetti posseggono tre tipi di valori, a seconda dell'uso che il giocatore ne fa durante la fase di combattimento (cfr. cap 6):
   - Valore da mischia: valore aggiunto (se il valore è negativo) o tolto (se il valore è positivo) alla vita del giocatore o alla vita/difesa del nemico selezionato (cfr. cap 7, par 3);
  - Danno da lancio: valore tolto alla vita del nemico selezionato;
  - Valore di difesa: valore che assume la difesa del giocatore.

Queste sono solo le caratteristiche intrinseche degli oggetti, per approfondire i loro usi, si rimanda al capitolo COMBATTIMENTO (cfr. cap 6);


6. COMBATTIMENTO

Un evento scelta può portare ad una fase di combattimento; questa è caratterizzata dalla presenza di uno o più nemici con i quali il giocatore, con opportuni oggetti, dovrà combattere.
Immediatamente dopo l'evento scelta, compariranno gli eventuali oggetti trovati e i nomi dei nemici incontrati.
Nella schermata di combattimento, si presenterà in ordine dall'alto verso il basso:
  - Lista di nemici con vita e difesa (a sinistra) (cfr. cap 4);
  - Statistiche del giocatore, nome, eveentuale  difesa ('(') e vita ('*') (a destra);
  - Inventario del giocatore (cfr. cap 5);
Il combattimento si svolgerà a turni; Il turno del giocatore e quello dei nemici accadranno allo stesso tempo, il giocatore non saprà quale sarà l'azione del nemico.
Entrato in questa fase, il giocatore dovrà selezionare un oggetto da usare dal suo inventario.
Gli usi che il giocatore può fare di un qualsiasi oggetto sono tre:

`>> Usa <<`

Il giocatore selezionerà se usare l'oggetto in questione su un nemico o su se stesso. In entrambi i casi il comportamento dell'utilizzo varia a seconda del valore da mischia dell'oggetto, il quale potrà curare o danneggiare la vita del giocatore o del nemico selezionare (cfr. cap 5);
La durata/quantità dell'oggetto - sia pluritario che unitario - diminuirà di una unità.

`<< Lancia` 

Il giocatore selezionerà un nemico sul quale lanciare l'oggetto in questione che, nel caso sia privo di difesa, danneggerà la sua vita;
Si noti che, nel caso in cui l'oggetto selezionato sia di tipo pluritario , la sua quantità verrà ridotta di una unità, mentre nel caso sia unitario, l'oggetto lanciato non sarà più recuperabile ne utilizzabile in combattimeento, se non a fine battaglia -in caso di successo-.

`((Blocca`
    
Il giocatore alzerà una difesa pari al valore  da difesa dell'oggetto selezionato. Si noti che di fianco all'oggetto in questione comparirà la scritta "((difesa))", ad indicare che il giocatore sta attualmente usando l'oggetto per difendersi; per tale motivo se il giocatore (in turni succesivi) deciderà di usare tale oggetto in altri modi, questo non garantirà più la difesa al giocatore (o se lo utilizzerà nuovamente per difendersi, la difesa precedente sarà sostituita, ricaricando le barre di difesa. L'oggetto utilizzato in difesa perderà resistenza pari all'attacco del nemico ogni volta che blocca un colpo, se l'oggetto è pluritario (e quindi privo di resistenza) esso parerà il colpo ma verrà distrutto e quindi rimosso dall'inventario.

Una volta selezionato l'uso dell'oggetto, verranno mostrate in  sequenza le azioni-attacco dei nemici (cfr. cap 4) e succesivamente i risultati del singolo scontro (cfr. cap 6, par 1);

6.1. Dinamiche di combattimento.

Come già detto, il giocatore potrà (1) usare, (2) lanciare o (3) difendersi con un oggetto (lasciamo da parte il caso in cui si sceglie di usarlo sul giocatore).
Allo stesso modo, un nemico eseguirà un'azione di tipo (1) attacco ravvicinato, (2) a distanza o (3) di difesa.
Gli  attacchi da mischia (1) -sia del giocatore che del nemico- comportano l'avvicinamento dell'attaccante verso il bersaglio, rendendo l'attaccante vulnerabile da eventuali attacchi a distanza (2) del bersaglio. D'altra parte l'attacco da mischia (1) è in grado di danneggiare la difesa (3) del bersaglio -a seconda del valore dell'azione o dell'oggetto usato-. Se il valore dell'attacco è maggiore del valore di difesa del bersaglio, la difesa non sarà in grado di proteggerlo e il danno sarà diretto alla vita del bersaglio.
Gli attacchi da lancio (2) -sia del giocatore che del nemico- non comportano l'avvicinamento dell'attaccante verso il bersaglio, per cui eventuali attacchi da mischia (1) da partee del bersaglio, saranno schivati dall'attaccante in quanto fuori portata. D'altra parte gli attacchi a distanza (2) non sono in grado di danneggiare la difesa (3) del bersaglio, tranne nel caso in cui il valore degli attacchi da lancio è maggiore del valore di difesa del bersaglio, il quale daanneggerà direttamente la vita del bersaglio.
In modo grossolano il sistema è il seguente (molto simile al sistema sasso-carta-forbici):

                                        Mischia 
                                     >          > 
                               Lancio      <     Difesa   
                          

7. GRAMMATICA

Come accennato nel capitolo INTRODUZIONE, il giocatore potrà creare una storia giocabile comprensiva di eventi, nemici ed oggetti;
Ciò sarà possibile sviluppando queste tre componenti nei rispettivi files, che necessitano però  di una grammatica, per poter poi montare le diverse diramazioni della storia. Di seguito sono riportate le regole grammaticali dei singoli files.

1) events.txt

Per una descrizione dettagliata di cosa sono e dei vari tipi di eventi, si rimanda al capitolo EVENTI (cfr. cap 3).

Gli eventi lineari sono composti da:
 - Un ID preceduto dal simbolo '/' che vine letto fino alla fine della riga ('\n').
 - Il testo (dalla riga successiva all'ID fino al simbolo '#') è ciò che verrà stampato al momento dell'esecuzione dell'evento, mantenendo l'indentazione del file di testo.
 
 - Uno o più comandi introdotti dal simbolo '-', vegono distinti dal carattere successivo:
 
    -i.NOME_OGGETTO.QUANTITA' aggiunge oggetto o aumenta la quantità di un oggetto pluritario
                              se la quantità è negativa gli utilizzi dell'oggetto vengono ridotti
    -e.NOME_NEMICO            aggiunge un nemico da affrontare
    
    -d.DANNO                  diminuisce la vita del giocatore (se negativo la aumenta)
    -s                        salva la partita
    
    ->ID_EVENTO rimanda ad un' evento lineare
    -*ID_SCELTA rimanda ad una scelta
    -# termina la sessione di gioco (schermata di game over)
    -? termina la sessione di gioco rimandando direttamente all'intro
    
I primi 4 comandi possono essere ripetuti (anche se ha senso solo per i primi due), mentre degli altri 4 (>,*,#,?) deve essercene sempre solo uno (il programma di lettura si ferma al primo che trova).

Ogni evento deve essere definito (ovvero deve comprendere il testo da stampare ed i comandi) la prima volta che nel file vine utilizzato il il suo ID dopo il simbolo '/', sia se fa parte di una scelta sia se è un evento singolo.

Gli eventi scelta sono introdotti dal simbolo '+' seguito dall' ID della scelta;
La scelta legge fino ad arrivare alla combinazione di simboli "/#" salvando tutti gli ID degli eventi compresi come testo.
L'unica eccezione è quella delgi eventi condizionati, che non presentano direttamente l'id ma sono introdotti dalla combinazione di simboli "/?". Essi presentano una condizione (composta da il nome di un oggetto e la quantità richiesta) e sulla riga successiva l'ID dell'evento a cui rimandano (non preceduto da '/') il quale deve essere definito esternamente alla scelta. E' importante che ogni scelta abbia almeno un evento non condizionato.

ESEMPIO:

    __________________________________________________________________________________
    
    /Start
    Testo iniziale#
      -*SCELTA

    +SCELTA

    /EVENTO_1
    Torna alla scelta (non succede niente)#
      -*SCELTA

    /EVENTO_2
    Affronta un nemico#
      -e.NEMICO

      ->FINE

    /EVENTO_3
    Esegue un evento lineare#
      ->EVENTO_LINEARE

    /? -evento condizionato-
    OGGETTO.(quantità richiesta)
    FINE

    [...]

    /# -fine scelta-

    /EVENTO_LINEARE
    Aggiunge un oggetto#
      -i.OGGETTO.(quantità)
      -*SCELTA

    /FINE
    Testo finale#
      -# -game over-
    __________________________________________________________________________________

2) enemies.txt

Per una descrizione dettagliata dei nemici e delle loro azioni, si rimanda al capitolo NEMICI (cfr. cap 4), e per le dinamiche del combattimento al capitolo COMBATTIMENTO (cfr. cap 6, par 1).

ESEMPIO:

    __________________________________________________________________________________
      
    /NEMICO.(vita).(difesa)
    -(tipo di azione).(valore azione).TESTO AZIONE
    [...]
    -#
    __________________________________________________________________________________
    

Il nome del nemico (in caps) è anche il suo ID quindi va copiato negli eventi che lo utilizzano
Il (tipo di azone) può essere:

 - 'm' : "melee", se è un attacco a distanza ravvicinata
 - 'r' : "ranged", se è un attacco a distanza
 - 'd' : "defence", se è una forma di difesa
 
Il (valore di azione) indica rispettivamente il danno corpo a corpo, il danno a distanza e la capacità del colpo di superare la difesa del giocatore, il numero di punti di difesa ottenuti.

3) items.txt

Per una descrizione dettagliata dei vari tipi di oggetti e dei loro usi, si rimanda al capitolo OGGETTI (cfr. 4), e per le dinamiche del combattimento al capitolo COMBATTIMENTO (cfr. cap 6, par 1).

ESEMPIO:

    __________________________________________________________________________________
    
    /OGGETTO.(tipo).(danno).(danno a distanza).(valore di difensa)
    __________________________________________________________________________________
 

Il nome dell'oggetto (in caps) è anche il suo ID quindi va copiato negli eventi che lo utilizzano
Il (tipo) dell'oggetto può essere:

 - 'u' : "unitario", ad esempio un a spada o uno scudo; ogni oggetto viene aggiunto separatamente e il numero di usi viene considerato resistenza
 - 'p' : "pluritario", ad esempio pozioni, coltelli da lancio o arco con frecce; ogni oggetto trovato dopo il primo aumenta il numero di usi che viene considerato quantità (o munizioni)
 
Il (danno) indica quanta vita toglie se usato su di se o su un nemico, se negativo risulta in una cura.
Il (danno a distanza) indica sia quanta vita perde il nemico su di cui l'oggetto è lanciato, sia la capacità dell'oggetto di colpire il bersaglio.

Il (valore di difesa) indica sia il numero di attacchi a corpo a corpo che l'oggetto è in grado di bloccare in una volta, sia la sua capacità di fermare colpi a distanza.

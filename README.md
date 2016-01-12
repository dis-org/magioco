(1) INTRODUZIONE
Santi lol


(2) PRELIMINARI
Per garantire il corretto funzionamento di Magioco è necessario che nella directory in cui è contenuto l'eseguibile "Magioco", siano presenti due cartelle nominate "saves" e "custom" (senza virgolette).
La prima dovrà essere vuota, e conterrà i salvataggi che verranno creati nel corso del gioco.
La seconda dovrà contenere tre file di testo, i quali costituiranno la storia di Magioco: 
- events.txt (cfr. cap 7, par 1);
- enemies.txt (cfr. cap 7, par 2);
- items.txt	(cfr. cap 7, par 3).


(3)	EVENTI 
Nel corso della storia il giocatore incontrerà eventi, i quali lo condurranno a scelte che porteranno a diramare la storia stessa.
Questi eventi potranno presentarsi in forma diversa:
-Eventi lineari: eventi contenenti testo;
-Eventi scelta: eventi composti, possono condurre ad altri eventi scelta, eventi lineari, eventi che modificano vita ed oggetti del giocatore, eventi che si verificano solo sotto determinate condizioni, o eventi che portano ad una fase di combattimento.


(4) NEMICI
Nella fase di combattimento, il giocatore si troverà a dover affrontare uno o più nemici contemporaneamente.
Questi saranno caratterizzati da:
-Nome;
-Vita (1 punto vita è rappresentato da un "*");			
-Difesa (1 punto difesa è rappresentato da una ")");
-Serie di azioni, che possono essere di tipo attacco (ravvicinato o a distanza) o di tipo difesa (cfr. cap 6).


(5) OGGETTI
Il giocatore è fornito di un inventario oggetti, visualizzabile esclusivamente in fase di battaglia.
Durante un evento scelta, il giocatore potrà trovare degli oggetti che saranno aggiunti al suo inventario, i quali saranno utilizzabili per superare un combattimento o un ulteriore evento scelta.
Gli oggetti si dividono in due classi principali:
-Unitari: oggetti che possiedono una resistenza, consumata la quale l'oggetto sarà eliminato dall'inventario.
-Pluritari: oggetti privi di resistenza, e per questo mono uso, ma cumulabili in più oggetti (quantità).
Gli oggetti posseggono tre tipi di valori, a seconda dell'uso che il giocatore ne fa durante la fase di combattimento (cfr. cap 6):
-Valore da mischia: valore aggiunto (se il valore è negativo) o tolto (se il valore è positivo) alla vita del giocatore o alla vita/difesa del nemico selezionato (cfr. cap 7, par 3);
-Danno da lancio: valore tolto alla vita del nemico selezionato;
-Valore di difesa: valore che assume la difesa del giocatore.
Queste sono solo le caratteristiche intrinseche degli oggetti, per approfondire i loro usi, si rimanda al capitolo COMBATTIMENTO (cfr. cap 6);


(6) COMBATTIMENTO
Un evento scelta può portare ad una fase di combattimento; questa è caratterizzata dalla presenza di uno o più nemici con i quali il giocatore, con opportuni oggetti, dovrà combattere.
Immediatamente dopo l'evento scelta, compariranno gli eventuali oggetti trovati e i nomi dei nemici incontrati.
Nella schermata di combattimento, si presenterà in ordine dall'alto verso il basso:
-Lista di nemici con vita e difesa (a sinistra) (cfr. cap 4);
-Statistiche del giocatore, nome, eveentuale  difesa ("(") e vita ("*") (a destra);
-Inventario del giocatore (cfr. cap 5);
Il combattimento si svolgerà a turni; Il turno del giocatore e quello dei nemici accadranno allo stesso tempo, il giocatore non saprà quale sarà l'azione del nemico.
Entrato in questa fase, il giocatore dovrà selezionare un oggetto da usare dal suo inventario.
Gli usi che il giocatore può fare di un qualsiasi oggetto sono tre:
- >> Usa << : Il giocatore selezionerà se usare l'oggetto in questione su un nemico o su se stesso. In entrambi i casi il comportamento dell'utilizzo varia a seconda del valore da mischia dell'oggetto, il quale potrà curare o danneggiare la vita del giocatore o del nemico selezionare (cfr. cap 5);
La durata/quantità dell'oggetto - a seconda sia pluritario o unitario - diminuirà di una unità.
- << Lancia	: Il giocatore selezionerà un nemico sul quale lanciare l'oggetto in questione che, nel caso sia privo di difesa, danneggerà la sua vita;
Si noti che, nel caso in cui l'oggetto selezionato sia di tipo pluritario , la sua quantità verrà ridotta di una unità, mentre nel caso sia unitario, l'oggetto lanciato non sarà più recuperabile ne utilizzabile in combattimeento, se non a fine battaglia -in caso di successo-.
- ((Blocca	: Il giocatore alzerà una difesa pari al valore  da difesa dell'oggetto selezionato. Si noti che di fianco all'oggetto in questione comparirà la scritta "((difesa))", ad indicare che il giocatore sta attualmente usando l'oggetto per difendersi; per tale motivo se il giocatore (in turni succesivi) deciderà di usare tale oggetto in altri modi, questo non garantirà più la difesa al giocatore (o se lo utilizzerà nuovamente per difendersi, la difesa precedente sarà sostituita, diminuendone la quantità/resistenza). 
Una volta selezionato l'uso dell'oggetto, verranno mostrate in  sequenza le azioni-attacco dei nemici (cfr. cap 4) e succesivamente i risultati del singolo scontro (cfr. cap 6, par 1);

1) Dinamiche di combattimento.
Come già detto, il giocatore potrà (1) usare, (2) lanciare o (3) difendersi con un oggetto (lasciamo da parte il caso in cui si sceglie di usarlo sul giocatore).
Allo stesso modo, un nemico eseguirà un'azione di tipo (1) attacco ravvicinato, (2) a distanza o (3) di difesa.
Gli  attacchi da mischia (1) -sia del giocatore che del nemico- comportano l'avvicinamento dell'attaccante verso il bersaglio, rendendo l'attaccante vulnerabile da eventuali attacchi a distanza (2) del bersaglio. D'altra parte l'attacco da mischia (1) è in grado di danneggiare la difesa (3) del bersaglio -a seconda del valore dell'azione o dell'oggetto usato-. Se il valore dell'attacco è maggiore del valore di difesa del bersaglio, la difesa non sarà in grado di proteggerlo e il danno sarà diretto alla vita del bersaglio.
Gli attacchi da lancio (2) -sia del giocatore che del nemico- non comportano l'avvicinamento dell'attaccante verso il bersaglio, per cui eventuali attacchi da mischia (1) da partee del bersaglio, saranno schivati dall'attaccante in quanto fuori portata. D'altra parte gli attacchi a distanza (2) non sono in grado di danneggiare la difesa (3) del bersaglio, tranne nel caso in cui il valore degli attacchi da lancio è maggiore del valore di difesa del bersaglio, il quale daanneggerà direttamente la vita del bersaglio.
In modo grossolano il sistema è il seguente (molto simile al sistema sasso-carta-forbici):
								Mischia 
							 >		      > 
					   Lancio 	   <	   Difesa 	
					   							


(7) GRAMMATICA
Come accennato nel capitolo INTRODUZIONE, il giocatore potrà creare una storia giocabile comprensiva di eventi, nemici ed oggetti;
Ciò sarà possibile sviluppando queste tre componenti nei rispettivi files, che necessitano però  di una grammatica, per poter poi montare le diverse diramazioni della storia. Di seguito sono riportate le regole grammaticali dei singoli files.
1) events.txt 
Per una descrizione dettagliata di cosa sono e dei vari tipi di eventi, si rimanda al capitolo EVENTI (cfr. cap 3).
<INSERIRE TUTORIAL DEL PANNO?>

2) enemies.txt 
Per una descrizione dettagliata dei nemici e delle loro azioni, si rimanda al capitolo NEMICI (cfr. cap 4), e per le dinamiche del combattimento al capitolo COMBATTIMENTO (cfr. cap 6, par 1).
<INSERIRE TUTORIAL DEL PANNO?>

3) items.txt 
Per una descrizione dettagliata dei vari tipi di oggetti e dei loro usi, si rimanda al capitolo OGGETTI (cfr. 4), e per le dinamiche del combattimento al capitolo COMBATTIMENTO (cfr. cap 6, par 1).
<INSERIRE TUTORIAL DEL PANNO?>

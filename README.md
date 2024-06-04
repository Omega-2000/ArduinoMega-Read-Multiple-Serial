# ArduinoMega-Read-Multiple-Serial

**HARDWARE**
- Scheda Arduino Mega, con montato shield millefori
- Microcontrollore ATMEGA2560
- Alimentazione 5V
- Scheda collegata alle varie seriali tramite connettori dedicati (attualmente il dispositivo è stato preparato per potersi connettere alle 2 seriali presenti sulla scheda di Potenza Flexa Easylite/Welte)
- Scheda collegata al DeviceTest o a un computer via USB, il dispositivo potrà interfacciarsi con le seriali collegate alla scheda

***FW e HW preparato su misura per effettuare e agevolare i 2 test che devono essere eseguiti sulla scheda di potenza Flexa Easylite/Welte***
***Quindi per utilizzare questo FW o questa configurazione su altre applicazioni, dovranno essere fatte delle modifiche per poter adattare questo sistema ad altri***

**AMBIENTE DI SVILUPPO**
- Arduino IDE

**LINGUAGGIO DI PROGRAMMAZIONE**
- C++

**FUNZIONAMENTO IN SINTESI**
- Il programma rimarrà sempre in ascolto di entrambe le seriali collegate e rimarrà anche in attesa di comandi inviati in seriale. A seconda del comando inviato in seriale, verrà inviato lo stesso a una seriale o all'altra.

**FUNZIONAMENTO CODICE**
- serialEvent() : funzione che legge la seriale e all'invio di "\n" ritorna "true" che indicherà la lettura della seriale avvenuta e si potrà passare al controllo del comando ricevuto

- confronta_stringhe() : funzione che filtrerà i messaggi inviati in seriale e gli invierà alla seriale opportuna

- isValidMessage(String message) : funzione a cui si passa una stringa e che ritorna true se la stringa non contiene caratteri speciali, oppure false se la stringa non è valida

- isPrintable(char c) : funzione che controlla se il carattere che gli viene passato è un carattere speciale oppure no

# CifrarioVigenere
Il cifrario di Vigenere è una tecnica di crittografia classica che utilizza una chiave per cifrare il testo in chiaro. A differenza di altri cifrari più semplici, come il cifrario di Cesare, il cifrario di Vigenere utilizza una chiave di lunghezza variabile, rendendolo più sicuro.

**Funzionamento:**
1. **Chiave:** La chiave nel cifrario di Vigenere è una sequenza di caratteri che viene utilizzata per cifrare il testo. Ogni carattere della chiave corrisponde a un carattere nel testo in chiaro.

2. **Cifratura:** Per cifrare un messaggio, si ripete la chiave lungo l'intera lunghezza del testo in chiaro. Ogni carattere del testo in chiaro viene poi spostato di un certo numero di posizioni in base al corrispondente carattere della chiave. Questo processo rende più difficile individuare i pattern nel testo cifrato.

3. **Decifratura:** Per decifrare il messaggio cifrato, si utilizza la stessa chiave. Si ripete la chiave lungo la lunghezza del testo cifrato e si spostano i caratteri cifrati all'indietro di un numero di posizioni corrispondente al carattere della chiave. Questo riporta il testo al suo stato originale.

**Esempio testuale:**
Supponiamo di avere il testo in chiaro: "HELLO" e la chiave "KEY". Per cifrare la parola "HELLO", ripetiamo la chiave lungo la sua lunghezza:

Testo in chiaro:   H   E   L   L   O
Chiave:             K   E   Y   K   E

Ora, cifriamo ogni carattere del testo in chiaro spostandolo di un numero di posizioni corrispondente al suo corrispondente carattere della chiave. Ad esempio, se A è 0, B è 1, ecc., e H è la ottava lettera, sposteremo H di otto posizioni, ottenendo Q:

Testo cifrato:      R  I  J  V  S 

Quindi, il testo cifrato risultante per "HELLO" con la chiave "KEY" è "RIJVS". Per decifrare, si utilizza lo stesso processo in direzione opposta, riportando il testo cifrato a "HELLO".

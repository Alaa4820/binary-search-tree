# binary-search-tree
> Progetto del corso 'Programmazione C++' del giugno del 2022 (Università Milano-Bicocca)

Il progetto consiste nella realizzazione di una classe generica che implementa
un albero binario di ricerca. L’albero è formato da un insieme di elementi T
contenuti in nodi connessi in una struttura gerarchica padre-figlio e NON deve
permettere l’inserimento di dati duplicati. Deve essere possibile per l’utente
scegliere la strategia usata per confrontare due dati T.

Oltre ai metodi fondamentali, la classe deve permettere:
- Di conoscere il numero totale di dati inseriti nell’albero;
- Il controllo di esistenza un elemento T;
-. Di accedere ai dati presenti nell’albero tramite un iteratore a sola lettura e di tipo forward. L’ordine con il quale sono ritornati i dati non è rilevante.
- Di stampare il contenuto dell'albero usando operator<<. La stampa deve
- Implementare inoltre un metodo subtree che, passato un dato d dello stesso tipo del dato contenuto nell’albero, ritorna un nuovo albero. Il nuovo albero deve corrispondere al sottoalbero avente come radice il nodo con il valore d. Ad esempio l'esecuzione di B=A.subtree(8) potrebbe corrispondere alla situazione in figura:
![image](https://user-images.githubusercontent.com/101665044/190692420-60bef3e0-964a-43c1-ac9e-6b6db04e64a8.png)

- Implementare una funzione globale printIF che dato un albero binario di tipo T, e un predicato P, stampa a schermo tutti i valori contenuti nell’albero che soddisfano il predicato. 
Utilizzare dove opportuno la gestione delle eccezioni. Gestite con una logica
opportuna i casi limite/di errore.

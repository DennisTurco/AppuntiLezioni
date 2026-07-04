# Esercizi C

Raccolta di esercizi e lezioni di programmazione in C, pensati per essere seguiti in ordine crescente di difficoltà.

## Contenuti

| Cartella | Argomento |
| --- | --- |
| `cicli/` | Cicli (`for`, `while`) ed esercizi introduttivi |
| `array/` | Array monodimensionali: somma, media, massimo/minimo, ordinamento |
| `funzioni/` | Definizione e utilizzo di funzioni |
| `funzioni_ricorsive/` | Ricorsione (fattoriale, somma ricorsiva) |
| `puntatori/` | Puntatori, `malloc` e gestione della memoria |
| `struct/` | Strutture dati (`struct`) |
| `stringhe/` | Manipolazione di stringhe e cifrari |
| `file/` | Lettura e scrittura su file |
| `liste/` | Liste collegate |
| `alberi/` | Alberi binari |
| `random/` | Numeri casuali (dadi, giochi semplici) |
| `AlgoritmiSorting/` | Algoritmi di ordinamento (bubble sort, partition sort) |
| `esami/` | Tracce ed esempi di esame (battaglia navale, forza 4, morse, palindromi) |

Ogni cartella contiene tipicamente un file introduttivo e una sottocartella `esercizi/` con gli esercizi da svolgere.

## Come compilare ed eseguire

Con **gcc**:

```bash
gcc nome_file.c -o nome_file
./nome_file        # su Windows: nome_file.exe
```

Per attivare gli avvisi del compilatore (consigliato):

```bash
gcc -Wall nome_file.c -o nome_file
```

# Esercizi C#

Raccolta di esercizi e lezioni di programmazione in C#, dagli array alle applicazioni desktop con Windows Forms.

## Contenuti

| Cartella | Argomento |
| --- | --- |
| `Array/` | Esercizi introduttivi su array |
| `Matrici/` | Esercizi su matrici (Esercizio1-5, difficoltà crescente) |
| `windows_form/` | Applicazioni desktop con Windows Forms: calcolatrice, sveglia, gestione magazzino, calcolo frazioni, ecc. |

## Come compilare ed eseguire

Ogni esercizio è un progetto .NET indipendente. Dalla cartella del progetto (quella con il file `.csproj`):

```bash
dotnet run
```

> I progetti `windows_form/` richiedono Windows (dipendono da `net8.0-windows`).

## Note

Le cartelle `bin/`, `obj/` e `.vs/` sono generate automaticamente dal build e non vanno modificate a mano: se qualcosa non compila, spesso basta cancellarle e ricompilare.

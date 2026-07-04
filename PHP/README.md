# Esercizi PHP

Raccolta di esercizi PHP, principalmente orientati all'interazione con un database MySQL (form, CRUD, query).

## Contenuti

| Cartella/File | Argomento |
| --- | --- |
| `Riassunto/RiassuntoPHP.php` | Riepilogo/cheat sheet della sintassi PHP |
| `Esercizio1/` | CRUD su "personaggi" e "casate" (insert, delete, ricerche) |
| `Esercizio2/` | Esercizio introduttivo |
| `Esercizio3/` | Gestione dipendenti e prodotti (più varianti progressive) |
| `EsercizioApicoltori/` | Gestione apiari/apicoltori, inserimento dati, richieste GET |
| `EsercizioCollegamento/` | Elaborazione dati da form (`processa.php`) |
| `EserciziSimulazioneVerifica/` | Simulazioni di verifica (es1-es10) |
| `esempio_cookie_sessioni.php` | Esempio di gestione di cookie e sessioni |

## Come eseguire

Gli esercizi che leggono/scrivono su database richiedono un server locale con PHP e MySQL (es. **XAMPP** o **MAMP**). Con il server avviato:

```bash
php -S localhost:8000
```

e poi apri `http://localhost:8000/<cartella>/<file>.php` dal browser.

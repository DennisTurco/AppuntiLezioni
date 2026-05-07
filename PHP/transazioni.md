# Transazioni

- **COMMIT**   $\rightarrow$ se tutto va a buon fine, allora salviamo tutto.
- **ROLLBACK** $\rightarrow$ se si verifica un errore nella query, si annulla l'operazione fallita e si torna allo stato precedente.

# Transazioni in PHP

1. `mysqli_autocommit($conn, false/true)`: permette di attivare o disattivare l'autocommit di mysql:
    - `true`: ogni query viene subito salvata (autocimmit attivo)
    - `false`: per salvare serve fare commit manuale. Per effettuare il commit manuale il comando e': `mysqli_commit($conn)`
1. `mysqli_rollback($conn)`: serve per annullare tutte le operazioni fatte nella transazione corrente

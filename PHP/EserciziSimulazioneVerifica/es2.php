<!-- Scrivi un programma PHP che:
• riceve tramite POST i campi titolo e prezzo;
• si connette al database negozio;
• inserisce un nuovo prodotto nella tabella prodotti;
• stampa un messaggio di conferma -->

<?php
$titolo = $_POST['titolo'];
$prezzo = $_POST['prezzo'];

$conn = new mysqli("localhost", "root", "", "negozio");
if ($conn->connect_error) {
    die("Connessione fallita");
}

$sql = "INSERT INTO prodotti (titolo, prezzo)
        VALUES('$titolo', '$prezzo')";

if($conn->query($sql)) {
    echo "Prodotto inserito correttamente";
} else {
    echo "Errore inserimento prodotto";
}

$conn->close();
?>
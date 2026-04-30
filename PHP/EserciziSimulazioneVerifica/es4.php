<!-- Scrivi un programma PHP che:
• si connette al database biblioteca;
• aggiorna il campo disponibile di un libro con un determinato id;
• stampa un messaggio che conferma l’aggiornamento. -->

<?php
$id = $_POST['id'];

$conn = new mysqli("localhost", "root", "", "biblioteca");
if ($conn->connect_error) {
    die("Connessione fallita");
}

$sql = "UPDATE libri
        SET disponibile = 0
        WHERE id = '$id'";

if ($conn->query($sql)) {
    echo "Libro aggiornato con successo";
} else {
    echo "Errore aggiornamento";
}

$conn->close();
?>
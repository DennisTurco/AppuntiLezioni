<!--
Scrivi un programma PHP che:
• si connette al database scuola;
• esegue una query che seleziona nome e cognome degli studenti;
• stampa ogni riga nel formato:
Studente: <nome> <cognome>
-->

<?php
$conn = new mysqli("localhost", "root", "", "scuola");
if ($conn->connect_error) {
    die("Connessione fallita");
}

$sql = "SELECT nome, cognome FROM studenti";
$result = $conn->query($sql);

while ($row = $result->fetch_assoc()) {
    echo "Studente: " . $row["nome"] . " " . $row["cognome"] . "<br>";
}

$conn->close();
?>
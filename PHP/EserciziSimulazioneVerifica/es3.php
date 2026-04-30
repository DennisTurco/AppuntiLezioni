<!-- Scrivi un programma PHP che:
• riceve username e password via POST;
• si connette al database utentiDB;
• esegue una query per verificare se esiste un utente con quelle credenziali;
• stampa: Accesso consentito oppure Accesso negato -->

<?php
$username = $_POST['username'];
$password = $_POST['password'];

$conn = new mysqli("localhost", "root", "", "utentiDB");
if ($conn->connect_error) {
    die("Connessione fallita");
}

$sql = "SELECT * FROM utenti
        WHERE username = '$username'
        AND password = '$password'";

$result = $conn->query($sql);

if ($result->num_rows > 0) {
    echo "Accesso consentito";
} else {
    echo "Accesso negato";
}

$conn->close();
?>
<!DOCTYPE html>
<html>
<body>

<form method="POST">
  <label>Inserisci i dati:</label><br>
  Nome: <input type="text" name="nome"><br>
  Età: <input type="text" name="eta"><br>
  <input type="submit" value="Invia">
</form>

<?php
// Verifica se i dati del form sono stati inviati
if (isset($_POST['nome']) && isset($_POST['eta'])) {
    echo "<p>Valori inseriti correttamente: Nome = " . htmlspecialchars($_POST['nome']) . ", Età = " . htmlspecialchars($_POST['eta']) . "</p>";
}

// Definizione di un array associativo
$persona = array(
    "nome" => "Luca",
    "eta" => 30
);

// Visualizzazione dei valori dell'array
echo "<p>Nome: " . $persona['nome'] . "</p>";
echo "<p>Età: " . $persona['eta'] . "</p>";

// Scorrere l'array con un foreach
foreach ($persona as $chiave => $valore) {
    if ($chiave == "eta") {
        echo "<p>Età (dal foreach): $valore</p>";
    }
}

// COOKIE
setcookie("utente", "Luca", time() + 3600); // dura 1 ora
if (isset($_COOKIE["utente"])) {
    echo "<p>Cookie trovato. Ciao, " . $_COOKIE["utente"] . "!</p>";
}

// SESSIONI
session_start(); // deve sempre venire prima di qualunque output HTML

$_SESSION["utente"] = "Luca";
echo "<p>Sessione attiva. Ciao, " . $_SESSION["utente"] . "!</p>";

// Per cancellare tutte le variabili di sessione
session_unset();

// Per distruggere completamente la sessione
session_destroy();
?>

</body>
</html>

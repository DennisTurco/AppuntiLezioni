<!DOCTYPE html>
<html>
<head>
    <title>Conteggio Personaggi per Casata</title>
</head>
<body>
    <h2>Numero di personaggi per casata</h2>

    <?php
    // Connessione al database
    $conn = mysqli_connect("localhost", "root", "", "hogwarts") or die("Errore di connessione: " . mysqli_connect_error());

    // Query per ottenere il numero di personaggi per casata
    $query = "SELECT c.denominazione AS casata, COUNT(p.id_personaggio) AS numero_personaggi
            FROM personaggi p
            JOIN casehw c ON p.id_casa = c.id_casa
            GROUP BY c.denominazione
            ORDER BY numero_personaggi DESC
    ";

    $result = mysqli_query($conn, $query);

    // Controllo risultati
    if (mysqli_num_rows($result) > 0) {
        echo "<table border='1'>";
        echo "<tr><th>Casata</th><th>Numero di Personaggi</th></tr>";

        while ($row = mysqli_fetch_assoc($result)) {
            echo "<tr>";
            echo "<td>" . htmlspecialchars($row['casata']) . "</td>";
            echo "<td>" . $row['numero_personaggi'] . "</td>";
            echo "</tr>";
        }

        echo "</table>";
    } else {
        echo "Nessun dato trovato.";
    }

    // Chiusura connessione
    mysqli_close($conn);
    ?>
</body>
</html>

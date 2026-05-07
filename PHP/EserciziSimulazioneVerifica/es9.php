<?php

$conn = new mysqli("localhost", "root", "", "scolastico");
if ($conn->connect_error) {
    die("Connessione fallita");
}

$sql = "SELECT
            s.nome,
            s.cognome,
            AVG(v.voto) AS media_studente,
            (
                SELECT AVG(v2.voto)
                FROM
                    voti v2
                    INNER JOIN studenti s2 ON s2.id = v2.id_studente
                WHERE
                    s2.classe = s.classe -- perche' deve essere della sua stessa classe
            ) AS media_classe
        FROM
            studenti s
            INNER JOIN voti v ON v.id_studente = s.id
        GROUP BY s.nome, s.cognome
        HAVING media_studente > media_classe
        ORDER BY media_studente DESC
        ";

$result = $conn->query($sql);

while ($row = $result->fetch_assoc()) {
    echo "...";
}

$conn->close();
?>
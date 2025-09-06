<?php
    $conn = mysqli_connect("localhost", "root", "password", "apicoltori");

    $NomeRegione = mysqli_real_escape_string($conn, trim($_POST['NomeRegione']));
    $NomeTipologia = mysqli_real_escape_string($conn, trim($_POST['NomeTipologia']));

    // ottengo l'id della regione tramite il nome
    $query = "SELECT IdRegione FROM Regioni WHERE Nome = '$NomeRegione'";
    $resultRegione = mysqli_query($conn, $query);
    $row = mysqli_fetch_array($resultRegione);
    $IdRegione = $row[0];

    // ottengo l'id della tipologia tramite il nome
    $query = "SELECT IdTipologiai FROM Tipologie WHERE Nome = '$NomeTipologia'";
    $resultTipologia = mysqli_query($conn, $query);
    $row = mysqli_fetch_array($resultTipologia);
    $IdTipologia = $row[0];

    // costruisco la stampa grafica del risultato
    $grafica = "<h1> Apicoltori della regione $NomeRegione con tipologia miele $NomeTipologia </h1><br>";

    // ottenimento degli apicoltori
    $query = "SELECT a.Nome, a.Cognome, a.Email, a.LinkSito
    FROM
        apicoltori a
        INNER JOIN Apiari ap ON ap.IdApicoltore = a.IdApicoltore
        INNER JOIN Localita l ON l.IdLocalita = ap.IdLocalita
        INNER JOIN Comuni c ON c.IdComune = l.IdComune
        INNER JOIN Province p ON p.IdProvincia = c.IdProvincia
        INNER JOIN Regioni r ON r.IdRegione = p.IdRegione
        INNER JOIN Miele m ON m.IdMiele = ap.IdMiele
        INNER JOIN Tipologie t ON t.IdTipologia = m.IdTipologia
    WHERE
        r.IdRegione = $IdRegione
        AND t.IdTipologia = $IdTipologia
    ";
    $result = mysqli_query($conn, $query);
    if (mysqli_num_rows($result) == 0) {
        $grafica .= "<p> Nessun apicoltore trovato </p>";
    } else {
        $grafica .= "<table>
            <tr>
                <th> Nome </th>
                <th> Cognome </th>
                <th> Email </th>
                <th> Link del sito </th>
            </tr>
        ";

        while ($row = mysqli_fetch_array($result)) {
            $grafica .= "<tr>
                    <td> {$row['Nome']} </td>
                    <td> {$row['Cognome']} </td>
                    <td> {$row['Email']} </td>
                    <td> {$row['LinkSito']} </td>
                </tr>
            ";
        }
        $grafica .= "</table>";
    }

    echo $grafica;
    mysqli_close($conn);
?>
<!-- la parte dell'html inquesto caso è abbastanza complessa e non è nemmeno richiesta
 quindi per evitare confusione e codice inutile, la skippiamo -->

<?php
    $conn = mysqli_connect("localhost", "root", "password", "apicoltori");

    $regione = mysqli_real_escape_string($conn, trim($_POST['regione'])); // nome della regione

    //  ottenere l'id della regione in base al nome che ci è stato passato
    $query = "SELECT IdRegione FROM Regioni WHERE Nome = '$regione'";
    $result = mysqli_query($conn, $query);
    if (!$result) {
        echo "Errore: Nome regione inesistente!";
        mysqli_close($conn);
        exit;
    }
    $row = mysqli_fetch_array($result);
    $IdRegione = $row['IdRegione'];

    $query = @"SELECT a.IdApiario, l.Nome AS localita
    FROM
        Regioni r
        INNER JOIN Province p ON p.IdRegione = r.IdRegione
        INNER JOIN Comuni c ON c.IdProvince = p.IdProvince
        INNER JOIN Localita l ON l.IdComune = c.IdComune
        INNER JOIN Apiari a ON a.IdLocalita = l.IdLocalita
    WHERE
        r.IdRegione = $IdRegione";

    $result = mysqli_query($conn, $query);
    if (mysqli_num_rows($result) == 0) {
        echo "Non ci sono apiari per la regione selezionata.";
    } else {
        $tabella = "
            <table>
                <tr>
                    <th> Id Apiario </th>
                    <th> Localita </th>
                </tr>";

        while ($row = mysqli_fetch_array($result)) {
            $tabella .= "
            <tr>
                <td> {row[0]} </td>
                <td> {row[1]} </td>
            </tr>";
        }

        $tabella .= "</table>";
    }

    mysqli_close($conn);
?>
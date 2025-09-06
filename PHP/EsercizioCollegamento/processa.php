<?php
    if (isset($_POST['maricola']) && isset($_POST['nome']) && isset($_POST['cognome']) && isset($_POST['sipendio'])) {
        $conn = mysqli_conn("localhost", "root", "", "dipendenti");

        $matricola = mysqli_real_escape_string($conn, trim($_POST['matricola']));
        $nome = mysqli_real_escape_string($conn, trim($_POST['nome']));
        $cognome = mysqli_real_escape_string($conn, trim($_POST['cognome']));
        $stipendio = mysqli_real_escape_string($conn, trim($_POST['stipendio']));
        $note = mysqli_real_escape_string($conn, trim($_POST['note']));

        $query = "INSERT INTO Dipendenti VALUES ('$matricola', '$nome', '$cognome', '$stipendio', '$note')";

        $result = mysqli_query($conn, $query);

        if ($result) {
            echo "Dipendente aggiunto con successo!";
        } else {
            echo "Errore durante l'inserimento del dipendente";
        }

        mysqli_close($conn);
    }
<?
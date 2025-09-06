<!-- ##################### INSERIMENTO ##################### -->
<!-- Nota: form obbligatorio per chiedere valori -->
<?php
    if (isset($_GET['idPersona']) && isset($_GET['nome']) && isset($_GET['cognome'])) {
        
        $conn = mysqli_connect("localhost", "root", "", "persone");

        $idPersona = mysqli_real_escape_string($conn, trim($_GET['idPersona']));
        $nome = mysqli_real_escape_string($conn, trim($_GET['nome']));
        $cognome = mysqli_real_escape_string($conn, trim($_GET['cognome']));

        $query = "INSERT INTO persone (idPersona, nome, cognome) VALUES ('$idPersona', '$nome', '$cognome')";

        $result = mysqli_query($conn, $query);
        if ($result) {
            echo "Aggiunta avvenuta con successo";
        } else {
            echo "Errore durante l'inserimento";
        }

        mysqli_close($conn);
    }
?>

<!-- Ipotizziamo che dobbiamo modificare/aggiornare il nome della persona con l'id passato -->
<!-- ##################### AGGIORNAMENTO ##################### -->
<!-- Nota: form obbligatorio per chiedere valori -->
<?php
    if (isset($_GET['idPersona']) && isset($_GET['nome'])) {
        
        $conn = mysqli_connect("localhost", "root", "", "persone");

        $idPersona = mysqli_real_escape_string($conn, trim($_GET['idPersona']));
        $nome = mysqli_real_escape_string($conn, trim($_GET['nome']));

        $query = "UPDATE persone SET nome = '$nome' WHERE idPersona = '$idPersona'";

        $result = mysqli_query($conn, $query);
        if ($result) {
            echo "Aggiornamento avvenuto con successo";
        } else {
            echo "Errore durante l'aggiornamento";
        }

        mysqli_close($conn);
    }
?>

<!-- Ipotizziamo di eliminare una persona da un id passato -->
<!-- ##################### RIMOZIONE ##################### -->
<!-- Nota: form obbligatorio per chiedere valori -->
<?php
    if (isset($_GET['idPersona'])) {
        
        $conn = mysqli_connect("localhost", "root", "", "persone");

        $idPersona = mysqli_real_escape_string($conn, trim($_GET['idPersona']));

        $query = "DELETE persone WHERE idPersona = '$idPersona'";

        $result = mysqli_query($conn, $query);
        if ($result) {
            echo "Eliminazione avvenuta con successo";
        } else {
            echo "Errore durante l'eliminazione";
        }

        mysqli_close($conn);
    }
?>

<!-- ##################### SELEZIONE/VISUALIZZAZIONE ##################### -->
<!-- Nota: form opzionale -->
<?php
	$conn = mysqli_connect("localhost","root","","persone"); 

	$query = "SELECT p.idPersona, p.nome, p.cognome 
                FROM persone p";
	
	$result = mysqli_query($conn, $query);
	
    // Questo pezzo serve solo se volete stampare l'elenco in tabella
	if (mysqli_query($result) > 0) {
		while($row = mysqli_fetch_assoc($result)) {
			echo "<tr>";
			echo "<td>" . $row['idPersona'] . "</td>";
			echo "<td>" . $row['nome'] . "</td>";
			echo "<td>" . $row['cognome'] . "</td>";
			echo "</tr>";
		}
	} else {
		echo "<tr><td colspan='3'>Nessuna persona trovata</td></tr>";
	}
		
	mysqli_close($conn);
?>
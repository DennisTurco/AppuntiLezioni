<html>  
<head> 
	
  <title>Personaggi per casata</title>  
</head>  
<body> 
	<h1> Personaggi per casata </h1>   

	<form method="GET", action="stampaCasataInput.php">
		<label for="casata"> Inserisci il nome della casata: </label>
		<input type=text" id="casata" nome="casata" required> <br><br>
		
		<button type="submit">Cerca</button>  
	</form>
<br><br>
<?php
	if (isset($_GET['casata'])) {

		//stringa di connessione (server e Db)
		$conn=mysqli_connect("localhost","root","","hogwarts") or die("Errore di connessione al DBMS My-SQL: " . mysqli_connect_error); 
		
		$casata = mysqli_real_escape_string($conn, trim($_GET['casata']));

		$query = " SELECT p.id_personaggio, p.nome, c.denominazione AS casata
					FROM personaggi p
					INNER JOIN casehw c ON c.id_casa = p.id_casa
					WHERE c.denominazione = ?"

		$stmt = mysqli_prepare($conn, $query);
		mysqli_stmt_bind_param($stmt, "s", $casata);
		mysqli_stmt_execute($stmt);
		$result = mysqli_stmt_get_result($stmt);

		if (mysqli_query($result) > 0) {
			echo "<h2> Personaggi della casata $casata:</h2>";
			echo "<table>";
			echo "<tr><th>ID</th> <th>Nome</th> <th>Casata</th></tr>";
			while($row = mysqli_fetch_assoc($result)) {
				echo "<tr>";
				echo "<td>" . $row['id_personaggio'] . "</td>";
				echo "<td>" . $row['nome'] . "</td>";
				echo "<td>" . $row['casata'] . "</td>";
				echo "</tr>";
			}
			echo "</table>";
		} else {
			echo "<tr><td colspan='3'>Nessun personaggio trovato</td></tr>";
		}
	
		mysqli_stmt_close($stmt);
        mysqli_close($conn);

		//funzione di reindirizzamento url temporizzato (sec)della pagina ad una predefinita a //partire da localhost sel server web
		header('Refresh: 5; url="http:/harrypotter/"');
	}
	
		
?>

</body>  
</html> 
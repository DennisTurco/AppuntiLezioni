<html>  
<head> 
	
  <title>test inserimento in php</title>  
</head>  
<body>
	<h2> Inserisci nuovo personaggio </h2>
	<form action="" method="GET">
		<label for="id_personaggio"> ID: </label>
		<input type="number" id="id_personaggio" name="id_personaggio" required> <br><br>

		<label for="nome"> Nome: </label>
		<input type="text" id="nome" name="nome" required> <br><br>

		<label for="casata"> Casata: </label>
		<select id="casata" name="casata" required>
			<option value="1"> Corvonero </option>
			<option value="2"> Grifondoro </option>
			<option value="3"> Serpeverde </option>
			<option value="4"> Tassorosso </option>
		</select><br><br>

		<input type="submit" value="Inserisci">

	</form>
<br><br>
<?php
	//raccolta dati dal FORM (id Personaggio implicito è autoincrement,nome //personaggio,casata)
	//Controllo inserimento valori nel form
	if(isset($_GET['nome']) && isset($_GET['casata']) && isset($_GET['id_personaggio'])) {
		
		//stringa di connessione (server e Db)
		$conn=mysqli_connect("localhost","root","","hogwarts") or die("Errore di connessione al DBMS My-SQL: " . mysqli_connect_error);  

		// pulizia per evitare sql injection
		$id_personaggio = mysqli_real_escape_string($conn, trim($_GET['id_personaggio']));
		$nome = mysqli_real_escape_string($conn, trim($_GET['nome']));
		$casata = mysqli_real_escape_string($conn, trim($_GET['casata']));
		 
		//stampa di prova dati raccolti dal form
		echo "ID_personaggio:   $id_personaggio <br>";
		echo "personaggio:  $nome <br>";
		echo "casata:   $casata <br>";
			
		//scrittura query di INSERIMENTO del personaggio tabella personaggi (DML)
		$query="INSERT INTO personaggi (id_personaggio,nome,id_casa) VALUES ('$id_personaggio', '$nome', '$casata')";

		//esecuzione della query (false-->nessun inserimento,true-->inserimento OK)
		$result=mysqli_query($conn,$query);
		
		//niente dati da fare dump, BASTA verificare $result
		if($result)
			echo "inserimento di $nome della casata di $casata avvenuto con successo!!!";
		else 
			echo "inserimento di $nome NON avvenuto con successo!!!";
		}

		mysqli_close($conn);

		//funzione di reindirizzamento url temporizzato (sec)della pagina ad una predefinita a //partire da localhost sel server web
		header('Refresh: 5; url="http:/harrypotter/"');
	?>
</body>  
</html> 
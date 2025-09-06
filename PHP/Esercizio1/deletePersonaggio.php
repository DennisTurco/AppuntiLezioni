<html>  
<head> 
	
  <title>test cancellazione in php</title>  
</head>  
<body>   
<h2> Inserisci id personaggio da eliminare</h2>
	<form action="" method="GET">
		<label for="id_personaggio"> ID: </label>
		<input type="number" id="id_personaggio" name="id_personaggio" required> <br><br>

		<input type="submit" value="Elimina">

	</form>
<?php
	//raccolta dati dal FORM (id Personaggio implicito è autoincrement,nome //personaggio,casata)
	//Controllo inserimento valori nel form
	if(isset($_GET['id_personaggio'])) {
		
		//stringa di connessione (server e Db)
		$conn=mysqli_connect("localhost","root","","hogwarts") or die("Errore di connessione al DBMS My-SQL: " . mysqli_connect_error); 

		$id_personaggio = mysqli_real_escape_string($conn, trim($_GET['id_personaggio']));
		 
		//stampa di prova dati raccolti dal form
		echo "ID_personaggio:   $id_personaggio <br>";
						
		//scrittura query di CANCELLAZIONE del personaggio tabella personaggi (DML)
		$query="DELETE personaggi WHERE '$id_personaggio' = id_personaggio";
		$result=mysqli_query($conn,$query);
		
		//niente dati da fare dump, BASTA verificare $result
		if($result)
			echo "Eliminazione personaggio con id = $id_personaggio avvenuto con successo!!!";
		else 
			echo "Eliminazione NON avvenuta con successo";
		
		}
		
	mysqli_close($conn);

	header('Refresh: 5; url="http:/harrypotter/"');

?>
	
</body>  
</html> 
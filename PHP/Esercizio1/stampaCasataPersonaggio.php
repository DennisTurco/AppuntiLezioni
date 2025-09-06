<html>  
<head> 
	
  <title>Personaggi con 'y' e 'h'</title>  
</head>  
<body> 
	<h1> Personaggi con 'y' e 'h' nel nome </h1>   

	<table>
		<tr>
			<th> Nome personaggio</th>
			<th> Casata </th>
		</tr>
	</table>
<br><br>
<?php
	//stringa di connessione (server e Db)
	$conn=mysqli_connect("localhost","root","","hogwarts") or die("Errore di connessione al DBMS My-SQL: " . mysqli_connect_error); 

	$query="SELECT p.nome, c.denominazione AS casata
			FROM personaggi p,
			INNER JOIN casehw c ON c.id_casa = p.id_casa
			WHERE p.nome LIKE '%y%' AND p.nome like '%h%'";
	
	//esecuzione della query (false-->nessun inserimento,true-->inserimento OK)
	$result=mysqli_query($conn,$query);
	
	if (mysqli_query($result) > 0) {
		while($row = mysqli_fetch_assoc($result)) {
			echo "<tr>";
			echo "<td>" . $row['nome'] . "</td>";
			echo "<td>" . $row['casata'] . "</td>";
			echo "</tr>";
		}
	} else {
		echo "<tr><td colspan='3'>Nessun personaggio trovato</td></tr>";
	}
	
	mysqli_close($conn);

	//funzione di reindirizzamento url temporizzato (sec)della pagina ad una predefinita a //partire da localhost sel server web
	header('Refresh: 5; url="http:/harrypotter/"');
?>

</body>  
</html> 
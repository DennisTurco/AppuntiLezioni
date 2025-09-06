<html>  
<head>  
  <title>test inserimento in php</title>  
</head>  
<body>    
<form action="insertPersonaggio.php" method="GET"><BR>
inserimento di un nuovo personaggio della saga di Harry Potter<BR><BR>
ID_personaggio:<input type="text" name="id_personaggio" placeholder="ID_personaggio" required>
&nbsp &nbsp &nbspnome:&nbsp<input type="text" name="nome" placeholder="nome" required><BR><BR>
Casa di appartenenza:<BR>
<?php
	//stringa di connessione (server e Db)
	$conn=mysqli_connect("localhost","root","","hogwarts") or die("Errore di connessione al DBMS My-SQL: " . mysqli_connect_error); 

	$query="SELECT * FROM casehw";

	//esecuzione della query 
	$result=mysqli_query($conn,$query);
	if ($result)
	{echo "query eseguita correttamente" OR die("errore in esecuzione della query"); 
   }
	
	?>
	<select name="casata">
	<?php
	// verifichiamo se ci sono delle tuple
	if (mysqli_num_rows($result)!=0)
	{//dump delle casate nella lista
		while($row=mysqli_fetch_array($result))
		{
		?>

		<option value=<?php echo ("$row[0]")  ?>><?php echo ($row[0])?>--<?php echo ($row[1])?>
		</option>
		<?php
		} //while
	}// if
	else
		echo"nessuna casata nel db";
	?>
	
</select><BR><BR>
	
<p><input type="submit" value="inserisci personaggio"></p>
</form>
</body>  
</html> 
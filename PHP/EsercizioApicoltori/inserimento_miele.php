<html>
    <head>
        <title> Inserimento Miele </title>
    </head>
    <body>
        <h1> Inserisci Miele </h1>
        <form method="post" action="">
            <label for="tipologia">Tipologia: </label> <br>
            <select name="tipologia" id="tipologia">
                <option value="0"> Scegliere la tipologia </option>
                <option value="1"> identità nazionale </option>
                <option value="2"> identità regionale </option>
                <option value="3"> identità territoriale </option>
                <option value="4"> D.O.P. </option>
            </select> <br><br>

            <label for="nome">Nome miele: </label> <br>
            <input type="text" id="nome" name="nome"> <br><br>

            <label for="descrizione">Descrizione (opzionale): </label> <br>
            <textarea id="descrizione" name="descrizione"></textarea><br><br>

            <input type="submit" id="submit">
        </form>

        <!-- Inserimento miele Lato server -->
        <?php
            if (isset($_POST['nome'])) {
                $conn = mysqli_connect("localhost", "root", "password", "apicoltori");

                $nome = mysqli_real_escape_string($conn, trim($_POST['nome']));
                $tipologia = $_POST['tipologia'];
                $descrizione = mysqli_real_escape_string($conn, trim($_POST['descrizione']));

                $query = "INSERT INTO Miele VALUES ('$tipologia', '$nome', '$descrizione')";

                $result = mysqli_query($conn, $query);
                if ($result) {
                    echo "Inserimento avvenuto con successo!";
                } else {
                    echo "Erore durante l'inserimento del miele, si prega di ripetere";
                }

                mysqli_close($conn);
            }
        ?>
    </body>
</html>
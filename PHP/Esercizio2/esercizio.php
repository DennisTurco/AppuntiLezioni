<!DOCTYPE html>
<html>
    <head> 
        <titel>Esercizio</title>
    </head>

    <body>
        <h1> Iscrizione al corso di musica </h1>
        <form method="post" action="corso.php">
            <label for="strumento"> Strumento:</label><br>
            <select name="strumento" id="strumento">
                <option value="chitarra">Chitarra</option>
                <option value="basso">Basso</option>
                <option value="batteria">Batteria</option>
            </select>
            <br><br>

            <label>Livello:</label><br>
            <input type="radio" name="livello" value="principiante"> Principiante <br>
            <input type="radio" name="livello" value="medio"> Medio <br>
            <input type="radio" name="livello" value="avanzato"> Avanzato <br><br>

            <label>Giorni disponibili: </label><br>
            <input type="checkbox" name="giorni[]" value="lunedì"><br>
            <input type="checkbox" name="giorni[]" value="mercoledì"><br>
            <input type="checkbox" name="giorni[]" value="venerdì"><br><br>

            <label>Ulteriori richieste: </label><br>
            <textarea name="richiesta" rows="4" cols="30"></textarea><br><br>

            <input type="submit" value="Invia">
        </form>

        <?php
            echo "strumento selezionato: " . $_POST['strumento'] . "<br>";
            echo "livello selezionato: " . $_POST['livello'] . "<br>";
            if (!empty($_POST['giorni'])) {
                echo "Giorni selezionati: <br>";
                foreach ($_POST['giorni'] as $giorno) {
                    echo $giorno . "<br>";
                }
            }
            else {
                echo "nessun giorno selezionato <br>";
            }
            echo "ulteriori richieste: " . $_POST['richieste'];
        ?>

    </body>
</html>
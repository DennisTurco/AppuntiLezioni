<html>
    <head><title>Lista Dipendenti</title></head>

    <body>
        <h1>Dipendenti</h1>

        <?php
            $conn = mysqli_connect("localhost", "root", "password", "Dipendenti");

            $query = "SELECT nominativo, qualifica
            FROM Personale
            WHERE id_dip IN ('D2', 'D4', 'D5')";

            if (mysqli_num_rows($result) == 0) {
                echo "Non ci sono dipendenti";
            } else {
                $tabella = "
                    <table>
                        <tr>
                            <th> nominativo </th>
                            <th> qualifica </th>
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
    </body>

</html>
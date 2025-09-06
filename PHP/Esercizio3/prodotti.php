<html>
    <head><title>Lista Prodotti</title></head>

    <body>
        <h1>Prodotti</h1>

        <?php
            $conn = mysqli_connect("localhost", "root", "password", "Prodotti");

            $query = "SELECT DISTINCT is_prod
            FROM Composizioni";

            if (mysqli_num_rows($result) == 0) {
                echo "Non ci sono prodotti";
            } else {
                $tabella = "
                    <table>
                        <tr>
                            <th> Id prodotto </th>
                        </tr>";

                while ($row = mysqli_fetch_array($result)) {
                    $tabella .= "
                    <tr>
                        <td> {row[0]} </td>
                    </tr>";
                }

                $tabella .= "</table>";
            }

            mysqli_close($conn);
        ?>
    </body>

</html>
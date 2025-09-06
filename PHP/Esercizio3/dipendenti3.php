<html>
    <head><title>Lista Dipendenti</title></head>

    <body>
        <h1>Dipendenti</h1>

        <?php
            $conn = mysqli_connect("localhost", "root", "password", "Dipendenti");

            $query = "SELECT matricola, nominativo, stipendio
            FROM Personale
            WHERE id_dip = 'D4'
            ORDER BY matricola";

            if (mysqli_num_rows($result) == 0) {
                echo "Non ci sono dipendenti";
            } else {
                $tabella = "
                    <table>
                        <tr>
                            <th> matricola </th>
                            <th> nominativo </th>
                            <th> stipendio </th>
                        </tr>";

                while ($row = mysqli_fetch_array($result)) {
                    $tabella .= "
                    <tr>
                        <td> {row[0]} </td>
                        <td> {row[1]} </td>
                        <td> {row[2]} </td>
                    </tr>";
                }

                $tabella .= "</table>";
            }

            mysqli_close($conn);
        ?>
    </body>

</html>
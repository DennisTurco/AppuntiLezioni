<html>
    <head><title>Lista Dipendenti</title></head>

    <body>
        <h1>Dipendenti</h1>

        <?php
            $conn = mysqli_connect("localhost", "root", "password", "Dipendenti");

            $query = "SELECT provincia, matricola, nominativo, stipendio
            FROM Personale
            WHERE nominativo like 'Ros%'";

            if (mysqli_num_rows($result) == 0) {
                echo "Non ci sono dipendenti";
            } else {
                $tabella = "
                    <table>
                        <tr>
                            <th> provincia </th>
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
                        <td> {row[3]} </td>
                    </tr>";
                }

                $tabella .= "</table>";
            }

            mysqli_close($conn);
        ?>
    </body>

</html>
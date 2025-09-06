<html>
    <head><title>Lista brani</title></head>

    <body>
        <h1>Brani</h1>

        <?php
            $conn = mysqli_connect("localhost", "root", "password", "brani");

            $query = "SELECT Album.totolo, numero_brano, Brani.titolo, durata
            FROM Album, Brani
            WHERE Album.id_album = Brani.id_album
            AND casa_discografica = 'BlueLabel'
            AND anno = 2022";

            if (mysqli_num_rows($result) == 0) {
                echo "Non ci sono brani";
            } else {
                $tabella = "
                    <table>
                        <tr>
                            <th> Titolo album</th>
                            <th> Numero brano </th>
                            <th> Titolo brano </th>
                            <th> durata </th>
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
<?php

...

$sql = "SELECT
            p.nome,
            p.categoria,
            SUM(o.quantita) AS pezzi_venduti,
            SUM(o.quantita * p.prezzo) AS incasso
        FROM
            prodotti p
            INNER JOIN ordini o ON o.id_prodotto = p.id
        GROUP BY p.nome, p.categoria
        HAVING pezzi_venduti >= 20
        ORDER BY incasso DESC
        ";

...
?>
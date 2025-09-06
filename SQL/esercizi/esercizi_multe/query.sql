--1) Visualizzare le multe (data infrazione, cognome agente, nome agente, importo, tipologia, modello auto) 
--   ricevute a partire dal'inizio dell'anno ad oggi (2024-11-19)
SELECT
    i.Data,
    a.cognome,
    a.nome,
    i.importo,
    i.TipoInfrazione,
    au.Modello
FROM
    infrazioni i, agenti a, auto au
WHERE
    i.Matricola = a.Matricola
    AND i.Targa = au.Targa
    AND i.Data BETWEEN '2024-01-01' AND '2024-11-19';

-- 2) Contare le multe di ogni marca auto
SELECT
    au.Marca,
    COUNT(i.Id_Infrazione) AS NumeroInfrazioni
FROM
    infrazioni i, auto au
WHERE
    i.Targa = au.Targa
GROUP BY
    au.Marca;

-- 3) Visualizzare i proprietari multati provenienti da Fornovo, Collecchio, Soliqnano, Varano Melegari
SELECT DISTINCT
    a.Nome,
    a.Cognome,
    a.Citta
FROM
    automobilisti a, auto au, infrazioni i
WHERE
    a.C_Fiscale = au.C_Fiscale
    AND au.Targa = i.Targa
    AND a.Citta in ('Fornovo', 'Collecchio', 'Solignano', 'Varano Melegari');
 
-- 4) Visualizzare il proprietario (CF, cognome, nome) "esemplare" (il minor numero di multe, a partire almeno da una multa)
WITH InfractionCounts AS (
    SELECT
        a.C_Fiscale,
        a.Nome,
        a.Cognome,
        COUNT(i.Id_Infrazione) AS NumeroInfrazioni
    FROM
        infrazioni i, automobilisti a, auto au
    WHERE
        a.C_Fiscale = au.C_Fiscale
        AND au.Targa = i.Targa
    GROUP BY
        a.C_Fiscale, a.Nome, a.Cognome
    HAVING
        COUNT(i.Id_Infrazione) >= 1 -- almeno una multa
)
SELECT
    C_Fiscale,
    Nome,
    Cognome,
    NumeroInfrazioni
FROM
    InfractionCounts
WHERE
    NumeroInfrazioni = (SELECT MIN(NumeroInfrazioni) FROM InfractionCounts);

-- 5) Visualizzare i/il proprietario/i (CF) che ha ricevuto infrazioni il cui importo medio sia maggore dell'importo medio 
--    delle infrazioni
SELECT
    a.C_Fiscale,
    a.Nome,
    a.Cognome,
    AVG(i.importo) AS ImportoMedio
FROM
    automobilisti a, auto au, infrazioni i
WHERE
    a.C_Fiscale = au.C_Fiscale
    AND au.Targa = i.Targa
GROUP BY
    a.C_Fiscale, a.Nome, a.Cognome
HAVING
    AVG(i.importo) > (SELECT AVG(inf.importo) from infrazioni inf);

-- 6) Visualizzare le auto che non hanno mai ricevuto infrazioni. 
-- (versione OUTER e versione subquery (differenza di insiemi))
-- versione OUTER JOIN
SELECT
    au.Targa,
    au.Modello,
    au.Marca
FROM
    auto au
    LEFT JOIN infrazioni i ON i.Targa = au.Targa
WHERE
    i.Targa is NULL;


-- versione subquery
SELECT
    Targa,
    Modello,
    Marca
FROM
    auto
WHERE
    Targa NOT IN (SELECT Targa FROM infrazioni)
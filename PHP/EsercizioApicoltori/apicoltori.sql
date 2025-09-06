CREATE TABLE Regioni (
    IdRegione INT PRIMARY KEY,
    Nome VARCHAR(255) NOT NULL
);

CREATE TABLE Province (
    IdProvincia INT PRIMARY KEY
    IdRegione INT,
    Nome VARCHAR(255) NOT NULL,
    FOREIGN KEY (IdRegione) REFERENCES Regioni (IdRegione)
);

CREATE TABLE Comuni (
    IdComune INT PRIMARY KEY,
    IdProvincia INT,
    CAP VARCHAR(10) NOT NULL,
    Nome VARCHAR(255) NOT NULL,
    FOREIGN KEY (IdProvincia) REFERENCES Province (IdProvincia)
);

CREATE TABLE Localita (
    IdLocalita INT PRIMARY KEY,
    IdComune INT,
    Nome VARCHAR(255) NOT NULL,
    FOREIGN KEY (IdComune) REFERENCES Comuni (IdComune)
);

CREATE TABLE Apicoltori (
    IdApicoltore INT PRIMARY KEY,
    Nome VARCHAR(32) NOT NULL,
    Cognome VARCHAR(32) NOT NULL,
    Email VARCHAR(32) NOT NULL,
    Telefono VARCHAR(32) NOT NULL,
    LinkSito VARCHAR(255),
    [Password] VARCHAR(255) NOT NULL,
);

CREATE TABLE Produzioni (
    IdProduzione INT PRIMARY KEY,
    IdApicoltore INT,
    Anno INT NOT NULL,
    FOREIGN KEY (IdApicoltore) REFERENCES Apicoltori (IdApicoltore)
);

CREATE TABLE Tipologie (
    IdTipologia INT PRIMARY KEY,
    Nome VARCHAR(255) NOT NULL,
    Descrizione VARCHAR(455)
);

CREATE TABLE Miele (
    IdMiele INT PRIMARY KEY,
    IdTipologia INT,
    Nome VARCHAR(255) NOT NULL,
    Descrizione VARCHAR(455),
    FOREIGN KEY (IdTipologia) REFERENCES Tipologie (IdTipologia)
);

CREATE TABLE Apiari (
    IdApiario INT PRIMARY KEY,
    IdLocalita INT,
    IdApicoltore INT,
    IdMiele INT,
    Nome VARCHAR(255) NOT NULL,
    Descrizione VARCHAR(455),
    FOREIGN KEY (IdLocalita) REFERENCES Localita (IdLocalita),
    FOREIGN KEY (IdApicoltore) REFERENCES Apicoltori (IdApicoltore),
    FOREIGN KEY (IdMiele) REFERENCES Miele (IdMiele),
);

CREATE TABLE ProduzioneApiario (
    IdApiario INT,
    IdProduzione INT,
    PesoProduzione DECIMAL(19,2) NOT NULL,
    Descrizone VARCHAR(455),
    PRIMARY KEY (IdApiario, IdProduzione),
    FOREIGN KEY (IdApiario) REFERENCES Apiari (IdApiario),
    FOREIGN KEY (IdProduzione) REFERENCES Produzioni (IdProduzione),
);



-------------------------------------- INTERROGAZIONI
-- le interrogazioni espresse in linguaggio SQL che restituiscono:
-- a) l’elenco degli apicoltori che producono miele DOP in una determinata regione;
SELECT
    a.Nome,
    a.Cognome,
    t.Nome,
    r.Nome
FROM
    Apicoltori a
    INNER JOIN Apiari ap ON ap.IdApicoltore = a.IdApicoltore
    INNER JOIN Localita l ON l.IdLocalita = ap.IdLocalita
    INNER JOIN Comuni c ON c.IdComune = l.IdComune
    INNER JOIN Provincie p ON p.IdProvincia = c.IdProvincia
    INNER JOIN Regioni r ON r.IdRegione = p.IdRegione
    INNER JOIN Miele m ON m.IdApiario = ap.IdApiario
    INNER JOIN Tipologia t ON t.IdTipologia = m.IdTipologia
WHERE
    t.Nome LIKE '%D.O.P.%'
    OR t.Nome LIKE '%DOP%';

-- b) il numero complessivo di apiari per ciascuna regione;
SELECT
    r.Nome,
    COUNT(ap.IdApiario) AS NumeroDiApiari
FROM
    Apiari ap
    INNER JOIN Localita l ON l.IdLocalita = ap.IdLocalita
    INNER JOIN Comuni c ON c.IdComune = l.IdComune
    INNER JOIN Provincie p ON p.IdProvincia = c.IdProvincia
    INNER JOIN Regioni r ON r.IdRegione = p.IdRegione
GROUP BY
    r.Nome

-- c) le quantità di miele prodotto in Italia lo scorso anno per ciascuna delle quattro tipologie;
SELECT
    SUM(pa.PesoProduzione),
    t.Nome
FROM
    Produzioni p
    INNER JOIN ProduzioneApiario pa ON pa.IdProduzione = p.IdProduzione
    INNER JOIN Apiari ap ON ap.IdApiario = p.IdApiario
    INNER JOIN Miele m ON m.IdApiario = ap.IdApiario
    INNER JOIN Tipologia t ON t.IdTipologia = m.IdTipologia
WHERE
    p.Anno = 2024
GROUP BY
    t.Nome
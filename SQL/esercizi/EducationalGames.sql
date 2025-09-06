-- implementare nel dbms lo schema logico proposto nell'esame di stato allegato in chat 'Educational games'.
-- Creare il db provando ad eseguire un pò di istruzioni DDL (db-schema), 
-- sotto implementate, prenderne un paio di riferimento e poi provare in completa autonomia 
-- a implementare le tabelle in ddl.
-- Inserire almeno 3-5 dati per ogni tabella

-------------------------- TABELLE ----------------------------
CREATE TABLE GameCategories (
    IDCategia INT PRIMARY KEY,
    Nome VARCHAR(255) NOT NULL
);

CREATE TABLE Games (
    IDGioco INT PRIMARY KEY,
    Titolo VARCHAR(255) NOT NULL,
    Descrizione VARCHAR(455),
    IDCategoria INT,
    FOREIGN KEY (IDCategia) REFERENCES GameCategories(IDCategia)
);

CREATE TABLE Playes (
    IDGiocatore INT PRIMARY KEY,
    Nickname VARCHAR(100) NOT NULL,
    Email VARCHAR(100),
);

CREATE TABLE Questions (
    IDDomanda INT PRIMARY KEY,
    Domanda VARCHAR(455) NOT NULL,
    Punteggio INT NOT NULL,
    IDGioco INT,
    FOREIGN KEY (IDGioco) REFERENCES Games(IDGioco)
);

CREATE TABLE Answers (
    IDRisposta INT PRIMARY KEY,
    Risposta VARCHAR(455) NOT NULL,
    Corretta BOOLEAN NOT NULL,
    IDDomanda INT,
    IDGiocatore INT,
    FOREIGN KEY (IDDomanda) REFERENCES Questions(IDDomanda),
    FOREIGN KEY (IDGiocatore) REFERENCES Players(IDGiocatore),
);

-------------------------- INSERT NELLE TABELLE ----------------------------
INSERT INTO GameCategories(IDCategoria, Nome) VALUES (1, 'Matematica');
INSERT INTO GameCategories(IDCategoria, Nome) VALUES (2, 'Storia');
INSERT INTO GameCategories(IDCategoria, Nome) VALUES (3, 'Geografia');

INSERT INTO Games(IDGioco, Titolo, Descrizione, IDCategoria) VALUES (1, 'Quiz Matematico', 'Semplice quiz matematico', 1); 
INSERT INTO Games(IDGioco, Titolo, Descrizione, IDCategoria) VALUES (2, 'La Storia dei Mondi', '', 2); 
INSERT INTO Games(IDGioco, Titolo, Descrizione, IDCategoria) VALUES (3, 'Geografichiamo', '', 3);

INSERT INTO Players(IDGiocatore, Nickname, Email) VALUES (1, 'Tracker', 'tracker@gmail.com');
INSERT INTO Players(IDGiocatore, Nickname, Email) VALUES (2, 'PistoleroMaledetto89', 'erpistolero@gmail.com');

INSERT INTO Questions(IDDomanda, Domanda, Punteggio, IDGioco) VALUES (1, 'Quanto fa 4-4*2?', 12, 1);
INSERT INTO Questions(IDDomanda, Domanda, Punteggio, IDGioco) VALUES (2, 'Dimmi le prime 2 cifre decimali di pi greco', 45, 1);
INSERT INTO Questions(IDDomanda, Domanda, Punteggio, IDGioco) VALUES (3, 'Quando avviene la marcia su Roma?', 37, 2);
INSERT INTO Questions(IDDomanda, Domanda, Punteggio, IDGioco) VALUES (4, 'Quando avviene la spedizione dei mille?', 23, 2);
INSERT INTO Questions(IDDomanda, Domanda, Punteggio, IDGioco) VALUES (5, 'Con chi confina Italia a nord? ', 46, 3);
INSERT INTO Questions(IDDomanda, Domanda, Punteggio, IDGioco) VALUES (6, 'Quanti continenti ci sono?', 9, 3);

INSERT INTO Answers(IDRisposta, Risposta, Corretta, IDDOmanda, IDGiocatore) VALUES (1, '0', 'false', 1, 1);
INSERT INTO Answers(IDRisposta, Risposta, Corretta, IDDOmanda, IDGiocatore) VALUES (2, '3 e 14', 'false', 2, 2);
INSERT INTO Answers(IDRisposta, Risposta, Corretta, IDDOmanda, IDGiocatore) VALUES (3, '1948', 'false', 3, 1);
INSERT INTO Answers(IDRisposta, Risposta, Corretta, IDDOmanda, IDGiocatore) VALUES (4, '1860', 'true', 4, 2);
INSERT INTO Answers(IDRisposta, Risposta, Corretta, IDDOmanda, IDGiocatore) VALUES (5, 'Svizzera e Austria', 'false', 5, 1);
INSERT INTO Answers(IDRisposta, Risposta, Corretta, IDDOmanda, IDGiocatore) VALUES (6, '7', 'true', 6, 2);

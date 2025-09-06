-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Creato il: Nov 25, 2024 alle 11:21
-- Versione del server: 10.4.32-MariaDB
-- Versione PHP: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `multe`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `agenti`
--

CREATE TABLE `agenti` (
  `Matricola` int(11) NOT NULL,
  `nome` varchar(50) NOT NULL,
  `cognome` varchar(30) NOT NULL,
  `contatto` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dump dei dati per la tabella `agenti`
--

INSERT INTO `agenti` (`Matricola`, `nome`, `cognome`, `contatto`) VALUES
(2, 'Giacomo', 'Rossi', 'Grossi@comune.pr.it'),
(3, 'Andrea ', 'Gobbi', 'agobbi@comune.pr.it'),
(4, 'Giacomina', 'Rossetti', 'Grossetti@comune.pr.it'),
(5, 'Fulvio ', 'Gobbi', 'fgobbi@comune.pr.it'),
(6, 'Stefan', 'Bratu', 'sbratu@gmail.com');

-- --------------------------------------------------------

--
-- Struttura della tabella `auto`
--

CREATE TABLE `auto` (
  `Targa` varchar(10) NOT NULL,
  `Marca` varchar(25) NOT NULL,
  `Modello` varchar(20) NOT NULL,
  `C_Fiscale` varchar(16) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dump dei dati per la tabella `auto`
--

INSERT INTO `auto` (`Targa`, `Marca`, `Modello`, `C_Fiscale`) VALUES
('CA942ZA', 'Suzuki', 'Ignis 4x4', 'MNLGZN90L30g337k'),
('CG409vv', 'Yaris', 'd4d', 'MNLGZN90L30g337k'),
('FF887za', 'Audi', 'Rsq8', 'FRCMGZ98L22g337z'),
('fg247AA', 'Peugeot', '308 gt', 'MNLGZN90L30g337k');

-- --------------------------------------------------------

--
-- Struttura della tabella `automobilisti`
--

CREATE TABLE `automobilisti` (
  `C_Fiscale` varchar(16) NOT NULL,
  `Nome` varchar(30) DEFAULT NULL,
  `Indirizzo` varchar(25) DEFAULT NULL,
  `Citta` varchar(20) DEFAULT NULL,
  `CAP` varchar(5) DEFAULT NULL,
  `Cognome` varchar(30) NOT NULL,
  `email` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dump dei dati per la tabella `automobilisti`
--

INSERT INTO `automobilisti` (`C_Fiscale`, `Nome`, `Indirizzo`, `Citta`, `CAP`, `Cognome`, `email`) VALUES
('FRCMGZ98L22g337z', 'Federico', 'via rossi 27', 'Parma', '43100', 'Riccardi', 'friccardi@gmail.com'),
('MNLGZN90L30g337k', 'Graziano', 'via stradella 12', 'Collecchio', '43044', 'Maniello', 'gmaniello@iissgadda.it');

-- --------------------------------------------------------

--
-- Struttura della tabella `infrazioni`
--

CREATE TABLE `infrazioni` (
  `Id_Infrazione` varchar(10) NOT NULL,
  `Data` date DEFAULT NULL,
  `Matricola` int(11) DEFAULT NULL,
  `TipoInfrazione` varchar(25) DEFAULT NULL,
  `Importo` double DEFAULT NULL,
  `Targa` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dump dei dati per la tabella `infrazioni`
--

INSERT INTO `infrazioni` (`Id_Infrazione`, `Data`, `Matricola`, `TipoInfrazione`, `Importo`, `Targa`) VALUES
('zz111', '2024-10-01', 4, 'eccesso di velocità', 140, 'CG409vv'),
('zz112', '2024-02-04', 2, 'sosta area Bus', 80, 'FF887za'),
('zz113', '2024-11-05', 3, 'mancata precdenza', 130, 'CA942ZA'),
('zz114', NULL, 5, 'semaforo rosso', 250, 'CA942ZA');

--
-- Indici per le tabelle scaricate
--

--
-- Indici per le tabelle `agenti`
--
ALTER TABLE `agenti`
  ADD PRIMARY KEY (`Matricola`),
  ADD UNIQUE KEY `contatto` (`contatto`);

--
-- Indici per le tabelle `auto`
--
ALTER TABLE `auto`
  ADD PRIMARY KEY (`Targa`),
  ADD KEY `C_Fiscale` (`C_Fiscale`);

--
-- Indici per le tabelle `automobilisti`
--
ALTER TABLE `automobilisti`
  ADD PRIMARY KEY (`C_Fiscale`),
  ADD UNIQUE KEY `email` (`email`);

--
-- Indici per le tabelle `infrazioni`
--
ALTER TABLE `infrazioni`
  ADD PRIMARY KEY (`Id_Infrazione`),
  ADD KEY `AgentiInfrazioni` (`Matricola`),
  ADD KEY `AutoInfrazioni` (`Targa`);

--
-- AUTO_INCREMENT per le tabelle scaricate
--

--
-- AUTO_INCREMENT per la tabella `agenti`
--
ALTER TABLE `agenti`
  MODIFY `Matricola` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- Limiti per le tabelle scaricate
--

--
-- Limiti per la tabella `auto`
--
ALTER TABLE `auto`
  ADD CONSTRAINT `auto_ibfk_1` FOREIGN KEY (`C_Fiscale`) REFERENCES `automobilisti` (`C_Fiscale`);

--
-- Limiti per la tabella `infrazioni`
--
ALTER TABLE `infrazioni`
  ADD CONSTRAINT `AgentiInfrazioni` FOREIGN KEY (`Matricola`) REFERENCES `agenti` (`Matricola`),
  ADD CONSTRAINT `AutoInfrazioni` FOREIGN KEY (`Targa`) REFERENCES `auto` (`Targa`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

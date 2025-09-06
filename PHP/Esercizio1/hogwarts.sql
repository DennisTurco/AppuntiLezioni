-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Creato il: Gen 24, 2025 alle 13:54
-- Versione del server: 10.4.22-MariaDB
-- Versione PHP: 8.1.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `hogwarts`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `casehw`
--

CREATE TABLE `casehw` (
  `id_casa` char(2) NOT NULL,
  `denominazione` varchar(16) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dump dei dati per la tabella `casehw`
--

INSERT INTO `casehw` (`id_casa`, `denominazione`) VALUES
('CN', 'Corvonero'),
('GD', 'Grifondoro'),
('SV', 'Serpeverde'),
('TR', 'Tassorosso');

-- --------------------------------------------------------

--
-- Struttura della tabella `personaggi`
--

CREATE TABLE `personaggi` (
  `id_personaggio` varchar(2) NOT NULL,
  `nome` varchar(32) NOT NULL,
  `id_casa` char(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dump dei dati per la tabella `personaggi`
--

INSERT INTO `personaggi` (`id_personaggio`, `nome`, `id_casa`) VALUES
('BL', 'Bellatrix', 'SV'),
('CD', 'Cedric Diggory', 'TR'),
('DM', 'Draco Malfoy', 'SV'),
('HG', 'Hermione Granger', 'GD'),
('HP', 'Harry Potter', 'GD'),
('LL', 'Luna Lovegood', 'CN'),
('MM', 'Mirtilla Malcontenta', 'CN'),
('RW', 'Ron Weasley', 'GD'),
('SP', 'Severus Piton', 'SV'),
('TL', 'Ted Lupin', 'TR'),
('zx', 'pippox', 'TR');

--
-- Indici per le tabelle scaricate
--

--
-- Indici per le tabelle `casehw`
--
ALTER TABLE `casehw`
  ADD PRIMARY KEY (`id_casa`);

--
-- Indici per le tabelle `personaggi`
--
ALTER TABLE `personaggi`
  ADD PRIMARY KEY (`id_personaggio`),
  ADD KEY `chiave_esterna` (`id_casa`);

--
-- Limiti per le tabelle scaricate
--

--
-- Limiti per la tabella `personaggi`
--
ALTER TABLE `personaggi`
  ADD CONSTRAINT `chiave_esterna` FOREIGN KEY (`id_casa`) REFERENCES `casehw` (`id_casa`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

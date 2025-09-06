use EsercizioInfrazioni

-- visualizzare tutti gli automobilisti
SELECT * FROM dbo.automobilisti

-- visualizzare tutti gli agenti
SELECT * FROM dbo.agenti

-- visualizzare tutte le infrazioni
SELECT * FROM dbo.infrazioni

-- visualizzare tutte le auto
SELECT * FROM dbo.auto

-- visualizzare tutti i nomi e i cognomi degli agenti
SELECT nome, cognome FROM dbo.agenti

-- visualizzare tutti i codici fiscali degli automobilisti
SELECT C_Fiscale FROM dbo.automobilisti

-- visualizzare tutti i nomi e cognomi degli agenti in ordine alfabetico sul cognome
SELECT cognome, nome 
FROM dbo.agenti 
ORDER BY cognome, nome

-- visualizzare tutte le infrazioni ordinate per data più recente
SELECT *
FROM dbo.infrazioni
ORDER BY Data DESC

-- visualizzare tutte le infrazioni con data nulla
SELECT * 
FROM dbo.infrazioni
WHERE Data is NULL

-- visualizzare tutte le infrazioni con un importo compreso tra  tra 100 e 150
SELECT * 
FROM dbo.infrazioni
WHERE Importo >= 100 AND Importo <= 150

-- visualizzare il CF, nome, il cognome dell'automobilista e la targa della sua auto
SELECT a.C_Fiscale, a.nome, a.cognome, au.targa
FROM dbo.automobilisti a, dbo.auto au
WHERE a.C_Fiscale = au.C_Fiscale

-- visualizzare il nome e il cognome dell'agente con il tipo infrazione, l'importo e la data ordinati per data
SELECT a.nome, a.cognome, i.TipoInfrazione, i.Importo, i.Data
FROM dbo.agenti a, dbo.infrazioni i
WHERE a.Matricola = i.Matricola
ORDER BY i.Data DESC

-- come prima ma voglio visualizzare anche la città dell'automobilista
SELECT a.nome, a.cognome, i.TipoInfrazione, i.Importo, i.Data, au.Citta
FROM dbo.agenti a, dbo.infrazioni i, dbo.automobilisti au, dbo.auto aut
WHERE 
    a.Matricola = i.Matricola
    and i.Targa = aut.Targa
    and aut.C_Fiscale = au.C_Fiscale
ORDER BY i.Data DESC


-- visualizzare tutte le multe con data 2024...
SELECT *
FROM dbo.infrazioni
WHERE Data like '2024%'

-- visualizzare tutti gli agenti con '...co...' nel nome
SELECT *
FROM dbo.agenti
WHERE nome like '%co%'

-- visualizzare tutti gli agenti con nome terminante per a
SELECT * 
FROM dbo.agenti
WHERE nome like '%a'

-- visualizzare tutte le macchine (Targa, Marca, Modello) di ogni automobilista (CF, nome, cognome)
SELECT b.C_Fiscale, b.Nome, b.Cognome, a.Targa, a.Marca, a.Modello
FROM dbo.auto a, dbo.automobilisti b
WHERE a.C_Fiscale = b.C_Fiscale
ORDER BY b.C_Fiscale
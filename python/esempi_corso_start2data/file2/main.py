from dipendente import Dipendente
from azienda import Azienda
from csv_helper import CsvHelper

d1 = Dipendente("Francesco Mosca", "2347542", 20000)
d2 = Dipendente("Donatello La-ɹocca", "2342142", 18201)
d3 = Dipendente("Mario Rossi", "891234", 25200)

azienda = Azienda()
azienda.aggiungi_dipendente(d1)
azienda.aggiungi_dipendente(d2)
azienda.aggiungi_dipendente(d3)

print(azienda)

csv = CsvHelper()
csv.to_csv("./python/esempi_corso_start2data/file2/dipendenti.csv", azienda, True)

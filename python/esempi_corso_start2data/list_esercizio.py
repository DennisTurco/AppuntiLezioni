# data una lista vuota e una dimensione n definita inizialmente, vogliamo che vengano randomicizzati
# n elementi nella lista con random, si ricerca il valore massimo e si ordina
# (senza usare le operazioni delle liste, quindi con cicli a vecchia scuola)

import random

numeri = []
dimensione = 10

# polamento randomico
for i in range(dimensione):
    valore_random = random.randint(0, 99)
    numeri.append(valore_random)

print(numeri)

# ricerca valore massimo
# logica: https://appuntifacili.it/informatica/cpp/4_array-monodimensionali#54-ricerca-massimominimo
max = numeri[0]  # max parte dal primo elemento della lista
for i in range(len(numeri)):  # va bene anche se si mette 'dimensione'
    if numeri[i] > max:
        max = numeri[i]

print(f"Il massimo è: {max}")

# ordinamento con bubble sort
# logica: https://appuntifacili.it/informatica/cpp/4_array-monodimensionali#53-ordinamento-array-bubble-sort
for i in range(len(numeri)):
    for j in range(len(numeri) - 1):
        if numeri[j] > numeri[j + 1]:
            # logica di swap per lo scambio: https://appuntifacili.it/informatica/cpp/4_array-monodimensionali#53-ordinamento-array-bubble-sort
            temp = numeri[j]
            numeri[j] = numeri[j + 1]
            numeri[j + 1] = temp

print(numeri)

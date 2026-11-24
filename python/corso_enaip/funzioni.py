import random


def crea_lista_random(lunghezza: int):
    numeri = [0] * lunghezza
    for i in range(lunghezza):
        numeri[i] = random.randint(0, 9)
    return numeri

def ordina_lista(numeri: list[int]):
    for i in range(len(numeri)):
        for j in range(len(numeri)-1):
            if numeri[j] > numeri[j+1]:
                appoggio = numeri[j]
                numeri[j] = numeri[j+1]
                numeri[j+1] = appoggio

numeri = crea_lista_random(10)

print(numeri)

print(f"Massimo: {max(numeri)}")

ordina_lista(numeri)

print(numeri)
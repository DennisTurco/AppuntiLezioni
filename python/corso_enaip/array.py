import random

# creiamo una lista di 10 elementi con valori iniziali a 0
numeri = [0] * 10

print(numeri)

for i in range(10):
    numeri[i] = random.randint(0, 9)

print(numeri)

print(f"Massimo: {max(numeri)}")

# sorting con bubble sort
for i in range(len(numeri)):
    for j in range(len(numeri)-1):
        if numeri[j] > numeri[j+1]:
            appoggio = numeri[j]
            numeri[j] = numeri[j+1]
            numeri[j+1] = appoggio

print(numeri)
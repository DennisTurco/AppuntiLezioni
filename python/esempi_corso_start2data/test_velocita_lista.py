import random
import time

numeri1 = []
numeri2 = {}

print("Popolamento")

for i in range(10000):
    valore_random = random.randint(0, 100)
    numeri1.append(valore_random)
    numeri2[i] = valore_random

print("Calcoli - lista")


# calcoliamo il tempo per ordinare con bubble sort (simulare situazione reale)
start = time.time()
for i in range(len(numeri1)):
    for j in range(len(numeri1) - 1):
        if numeri1[j] > numeri1[j + 1]:
            numeri1[j], numeri1[j + 1] = numeri1[j + 1], numeri1[j]
end = time.time()

print(end - start)

print("Calcoli - dict")

start = time.time()
for i in numeri2.values():
    for j in numeri2.values():
        if numeri2[j] > numeri2[j + 1]:
            numeri2[j], numeri2[j + 1] = numeri2[j + 1], numeri2[j]
end = time.time()

print(end - start)

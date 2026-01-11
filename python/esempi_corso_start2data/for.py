# 2 tipi di cicli: for e while

# stampando tutti i numeri da 0 a 9
for i in range(0, 10, 1):
    print(i, end=" ")

print()

# stampo tutti i numeri da 4 a 10 con passo 2
for i in range(4, 10, 2):
    print(i, end=" ")

print()

# stampo tutti i numeri da 0 a 30 con passo 1, ma pari
for i in range(31):
    if i % 2 == 0:
        print(i, end=" ")

print()

# stampo tutti i numeri da 0 a 30 con passo 1, ma pari. Se incontera il 17 termina il ciclo
for i in range(31):
    if i == 17:
        break # si esce dal ciclo
    if i % 2 == 0:
        print(i, end=" ")

print()

# ciclo al contrario - da 10 a 0
for i in range(10, -1, -1):
    print(i, end=" ")

print()

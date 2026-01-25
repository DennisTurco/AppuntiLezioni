numeri1 = [1, 0, 0, 2, 2, 3, 3]
numeri2 = {1, 0, 0, 2, 2, 3, 3}

# print(numeri1)
# print(numeri2)

print("Accesso singoli elementi con la lista: ")
for i in range(len(numeri1)):
    print(f"{numeri1[i]}", end=" ")

# in questo caso è obbligatorio accedere con il foreach perchè non possibile accesso diretto come per le liste
# Nota: lo stesso meccanismo potrebbe essere usato anche per le liste
print("\nAccesso singoli elementi con il set: ")
for n in numeri2:
    print(f"{n}", end=" ")

print()

# aggiunta elemento alla lista
numeri1.append(100)

# aggiunta elemento al set
numeri2.add(100)

# estensione lista
numeri1.extend((9, 8, 7))

# estensione set
numeri2.update([9, 1, 7])

# rimozione elemento liste
numeri1.remove(1)

# rimozione elemento set
numeri2.remove(1)

print(numeri1)
print(numeri2)


# se l'obbiettivo è quello di: data una lista rimuovere i duplicati: 1. la trasformi in set, 2. la ritrasformi in lista
numeri3 = [1, 4, 3, 2, 1, 4, 2, 2, 3]
passaggio1 = set(numeri3)
passaggio2 = list(passaggio1)
print(passaggio2)
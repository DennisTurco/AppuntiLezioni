lista = []  # dichiarazione lista vuota

for i in range(10):
    lista.append(i)  # metodo per aggiungere elementi nella lista

print(lista)

# aggiungo valore nel mezzo
lista.insert(5, 0)

print(lista)

lista2 = [0, 0, 0]

# estendere lista con altra lista

lista.extend(lista2)

print(lista)

# ordinamento

print(sorted(lista))
print(sorted(lista, reverse=True))

import time
import matplotlib.pyplot as plt

# Range di elementi
sizes = [1000, 5000, 10000, 50000, 100000, 1000000, 10000000]

# Liste per salvare i tempi
list_times = []
tuple_times = []
set_times = []
dict_times = []

for n in sizes:
    # Creiamo le strutture dati
    lista = list(range(n))
    tupla = tuple(range(n))
    insieme = set(range(n))
    dizionario = {i: None for i in range(n)}

    # Elemento da cercare (l'ultimo)
    target = n - 1

    # Lista
    start = time.time()
    target in lista
    list_times.append(time.time() - start)

    # Tupla
    start = time.time()
    target in tupla
    tuple_times.append(time.time() - start)

    # Set
    start = time.time()
    target in insieme
    set_times.append(time.time() - start)

    # Dictionary (chiavi)
    start = time.time()
    target in dizionario
    dict_times.append(time.time() - start)

# Grafico
plt.figure(figsize=(10, 6))
plt.plot(sizes, list_times, marker="o", label="List")
plt.plot(sizes, tuple_times, marker="s", label="Tuple")
plt.plot(sizes, set_times, marker="^", label="Set")
plt.plot(sizes, dict_times, marker="x", label="Dictionary")
plt.xlabel("Number of items")
plt.ylabel("Time (seconds)")
plt.title("Time Performance: List, Tuple, Set, Dictionary")
plt.legend()
plt.grid(True)
plt.show()

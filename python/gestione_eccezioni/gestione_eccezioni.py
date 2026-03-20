n = int(input("Numeratore: "))
d = int(input("Denominatore: "))

lista = [1, 2, 3]

try:
    # nell'ipotesi che d == 0, questa istruzione genererà un eccezione: ZeroDivisionError: division by zero
    risultato = n / d
    print(f"Risultato = {risultato}")

    # se la lista ha solo 3 elementi, non esisterà la posizione 5 -> genera IndexError
    print(lista[5])
except ZeroDivisionError:
    print("impossibile eseguire la divisione")
except IndexError:
    print("posizione lista non valida")
finally:
    print("Finally - Vengo sempre eseguito")

risultato2 = n * d
print(f"Risultato = {risultato2}")

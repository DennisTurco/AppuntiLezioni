# il ciclo for si usa (di norma) quando conosco il numero di iterazioni
# quando non conosciamo il numero delle iterazioni -> ciclo while
# il while è come un if ma il suo blocco viene eseguito ciclicamente (fintanto che la condizione è vera)

x = 3

while x < 1000:
    x = x**2
    print(x, end=" ")

print(f"\n{x}")



# Versione 2

x = 3

while True:
    x = x**2
    if x < 1000:
        print(x, end=" ")
    else:
        break


### chiedo valore finchè non corretto
print()

while True:
    valore = int(input("Dammi un numero compreso da 0 a 10: "))
    if valore < 0 or valore > 10:
        print("Errore: valore non ammesso")
    else:
        break

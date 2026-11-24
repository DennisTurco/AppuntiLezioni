numeri = int(input("Quanti numeri vuoi inserire? "))

somma = 0
for i in range(numeri):
    valore = int(input("valore: "))
    somma = somma + valore # somma += valore

print("La somma e': " + str(somma))
print(f"La media e': {somma/numeri}")
numeri = int(input("Quanti numeri vuoi inserire? "))

somma_pari = 0
numeri_pari = 0
for i in range(numeri):
    valore = int(input("valore: "))
    if valore % 2 == 0:
        somma_pari = somma_pari + valore # somma_pari += valore
        numeri_pari += 1

print("La somma pari e': " + str(somma_pari))
print(f"La media pari e': {somma_pari/numeri_pari}")
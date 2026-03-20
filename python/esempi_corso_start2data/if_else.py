valore = int(input("dammi un numero: "))
if valore % 2 == 0:
    print("valore pari!!!!")

####################################################

numero = int(input("Quanti anni hai? "))

if numero >= 18:
    print("Sei maggiorenne")
else:
    print("Sei minorenne")

####################################################

voto = int(input("Che voto hai preso? "))

if voto < 6:
    print("insufficiente")
elif voto == 6:
    print("sufficiente")
elif voto >= 7 and voto <= 9:
    print("ottimo")
else:
    print("eccellente")

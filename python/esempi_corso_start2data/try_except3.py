while (True):
    try:
        numeratore = int(input("Numeratore: "))
        denominatore = int(input("Denominatore: "))
        print(f"{numeratore}/{denominatore}")
        break
    except ValueError:
        print("Valori immessi non ammissibili")


print("Programma terminato")
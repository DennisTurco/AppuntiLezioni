


try:
    numeratore = int(input("Numeratore: "))
    denominatore = int(input("Denominatore: "))

    risultato = numeratore / denominatore
    print(risultato)
except ValueError as e:
    print(f"Errore: È richiesto un valore intero ---> {type(e)}: {e}")
except ZeroDivisionError as e:
    print(f"Impossibile dividere per 0 ---> {type(e)}: {e}")
finally:
    print("Programma Terminato")

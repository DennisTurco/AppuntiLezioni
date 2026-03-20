# la funzione deve lanciare un eccezione perche' altrimenti dovrebbe ritornare qualcosa
# ma avendo un valore di ritorno float e non potendo eseguire il calcolo, allora meglio lanciare un eccezione
def esegui_divisione(n: int, d: int) -> float:
    if d == 0:
        raise ZeroDivisionError("Non mi passare il denominatore nullo per piacere")
    risultato = n / d
    return risultato


try:
    numeratore = int(input("Numeratore: "))
    denominatore = int(input("Denominatore: "))
    risultato = esegui_divisione(numeratore, denominatore)
    print(risultato)
except ValueError:
    print("Valori immessi non ammissibili")
except ZeroDivisionError as e:
    print(e)


print("Programma terminato")

# eccezione personalizzata senza corpo, serve solo a crearla
class NumeroNegativoError(Exception):
    def __init__(self, message):
        super().__init__()
        self.message = message


try:
    n = int(input("Inserisci un Valore Positivo: "))

    if n < 0:
        raise NumeroNegativoError("Il valore deve essere positivo!")
except NumeroNegativoError as e:
    print(e.message)

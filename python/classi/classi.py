# una classe è una sorta di contenitori di informazioni preferibilmente omogenee.
# Contiene: Attributi e Metodi


class Gatto:
    nazionalita = "Italia"  # attributo della classe

    # metodo costruttore -> ci permette di istanziare (costruire un oggetto vero e proprio)
    def __init__(self, n, c, p):
        self.nome = n  # self indica che sto facendo riferimento ad un'informazione di questa classe
        self.colore = c
        self.peso = p

    def __str__(self):
        return f"Nome: {self.nome}, colore: {self.colore}, peso: {self.peso}, nazionalità: {self.nazionalita}"

    # metodo esempio della classe gatto
    def stampa(self):
        print(f"Nome: {self.nome}, colore: {self.colore}, peso: {self.peso}, nazionalità: {self.nazionalita}")


##################################################################

# per creare un gatto devo istanziarlo
gatto1 = Gatto("Gianni", "Rosa", 12.4)
gatto1.stampa()
print(gatto1)  # chiama automaticamente il metodo __str__()
print(gatto1.nome)
print(gatto1.nazionalita)


gatto2 = Gatto("Franco", "Blu", 34.4)
print(gatto2)


print("-----------------------------------")

# possibile anche creare una lista di gatti
gatti = [gatto1, gatto2]
for gatto in gatti:
    print(gatto)

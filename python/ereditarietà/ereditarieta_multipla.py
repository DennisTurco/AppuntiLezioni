# superclasse (classe base)
class Veicolo:
    def __init__(self, peso, numero_passeggeri, targa, matricola):
        self.peso = peso
        self.numero_passeggeri = numero_passeggeri
        self.targa = targa
        self.matricola = matricola

    def __str__(self):
        return (
            f"peso: {self.peso}, passeggeri: {self.numero_passeggeri}, targa: {self.targa}, matricola: {self.matricola}"
        )


class BarcaVela(Veicolo):
    def __init__(self, peso, numero_passeggeri, targa, matricola):
        super().__init__(peso, numero_passeggeri, targa, matricola)


# sia superclasse (di Macchina, Furgone e Moto), sia derivata (di Veicolo)
class VeicoloMotoreSuStrada(Veicolo):
    def __init__(self, peso, numero_passeggeri, targa, matricola, numero_ruote, cilindrata):
        super().__init__(peso, numero_passeggeri, targa, matricola)
        self.numero_ruote = numero_ruote
        self.cilindrata = cilindrata

    def __str__(self):
        return super().__str__() + f", ruote: {self.numero_ruote}, cilindrata: {self.cilindrata}"

    def accendi_spegni_aria_condizionata(self):
        print("Aria condizionata")


# classe figlia
class Macchina(VeicoloMotoreSuStrada):
    def __init__(self, peso, numero_ruote, numero_passeggeri, cilindrata, targa, matricola):
        super().__init__(peso, numero_ruote, numero_passeggeri, cilindrata, targa, matricola)
        self.aria_condizionata = False  # inizialmente non è attiva

    def accendi_spegni_aria_condizionata(self):
        if self.aria_condizionata:
            self.aria_condizionata = False
        else:
            self.aria_condizionata = True
        print(f"Aria condizionata: {self.aria_condizionata}")
        # equivalente a -> self.aria_condizionata = not self.aria_condizionata


# classe figlia
class Moto(VeicoloMotoreSuStrada):
    def __init__(self, peso, numero_ruote, numero_passeggeri, cilindrata, targa, matricola, nome_casco):
        super().__init__(peso, numero_ruote, numero_passeggeri, cilindrata, targa, matricola)
        self.nome_casco = nome_casco

    def __str__(self):
        # return f"ruote: {self.numero_ruote}, targa: {self.targa}, matricola: {self.matricola}, casco: {self.nome_casco}"
        return super().__str__() + f", casco: {self.nome_casco}"


# classe figlia
class Furgone(VeicoloMotoreSuStrada):
    def __init__(self, peso, numero_ruote, numero_passeggeri, cilindrata, targa, matricola):
        super().__init__(peso, numero_ruote, numero_passeggeri, cilindrata, targa, matricola)


def metodo(oggetto: VeicoloMotoreSuStrada):
    print("...")


# esempio d'uso
furgone = Furgone(234.2, 4, 3, 2000, "DFG23D", "GDSVHGSFD67t32")
macchina = Macchina(1231.3, 4, 5, 2200, "DHJ238", "GHJFSDGHFSDGHF23")
moto = Moto(400.56, 2, 2, 1000, "GFHSDGH23", "HJDFGJFHDGJHSG23", "casco bello")
barca = BarcaVela(456.32, 5, "ASHDJHJASD123", "JHSADGVGHJAG123")

print(furgone)
print(macchina)
print(moto)

# metodo(macchina)    # OK
# metodo(barca)       # ERRORE

macchina.accendi_spegni_aria_condizionata()
macchina.accendi_spegni_aria_condizionata()

print(Moto.mro())

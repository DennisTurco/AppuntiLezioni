# superclasse (classe base)
class Veicolo:
    def __init__(self, numero_ruote, numero_passeggeri, cilindrata, targa, matricola):
        self.numero_ruote = numero_ruote
        self.numero_passeggeri = numero_passeggeri
        self.cilindrata = cilindrata
        self.targa = targa
        self.matricola = matricola

    def __str__(self):
        return f"ruote: {self.numero_ruote}, targa: {self.targa}, matricola: {self.matricola}"


# classe figlia
class Macchina(Veicolo):
    def __init__(self, numero_ruote, numero_passeggeri, cilindrata, targa, matricola):
        super().__init__(numero_ruote, numero_passeggeri, cilindrata, targa, matricola)
        self.aria_condizionata = False  # inizialmente non è attiva

    def accendi_spegni_aria_condizionata(self):
        if self.aria_condizionata:
            self.aria_condizionata = False
        else:
            self.aria_condizionata = True
        print(f"Aria condizionata: {self.aria_condizionata}")
        # equivalente a -> self.aria_condizionata = not self.aria_condizionata


# classe figlia
class Moto(Veicolo):
    def __init__(self, numero_ruote, numero_passeggeri, cilindrata, targa, matricola, nome_casco):
        super().__init__(numero_ruote, numero_passeggeri, cilindrata, targa, matricola)
        self.nome_casco = nome_casco

    def __str__(self):
        # return f"ruote: {self.numero_ruote}, targa: {self.targa}, matricola: {self.matricola}, casco: {self.nome_casco}"
        return super().__str__() + f", casco: {self.nome_casco}"


# classe figlia
class Furgone(Veicolo):
    def __init__(self, numero_ruote, numero_passeggeri, cilindrata, targa, matricola):
        super().__init__(numero_ruote, numero_passeggeri, cilindrata, targa, matricola)


# esempio d'uso
furgone = Furgone(4, 3, 2000, "DFG23D", "GDSVHGSFD67t32")
macchina = Macchina(4, 5, 2200, "DHJ238", "GHJFSDGHFSDGHF23")
moto = Moto(2, 2, 1000, "GFHSDGH23", "HJDFGJFHDGJHSG23", "casco bello")

print(furgone)
print(macchina)
print(moto)

macchina.accendi_spegni_aria_condizionata()
macchina.accendi_spegni_aria_condizionata()

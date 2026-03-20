# Testo esercizio: https://appuntifacili.it/informatica/python/15_ereditarieta#102-esercizio--gestione-di-un-parco-veicoli-aziendale

from abc import ABC
from datetime import datetime


class Veicolo(ABC):
    def __init__(self, marca, modello, anno, targa):
        self.marca = marca
        self.modello = modello
        self.anno = anno
        self.targa = targa

    def descrizione(self):
        return (
            f"Descrizione veicolo: marca: {self.marca}, modello: {self.modello}, anno: {self.anno}, targa: {self.targa}"
        )

    def calcola_costo_manutenzione(self):
        return int(100)


class Moto(Veicolo):
    def __init__(self, marca, modello, anno, targa, cilindrata):
        super().__init__(marca, modello, anno, targa)
        self.cilindrata = cilindrata

    def calcola_costo_manutenzione(self):
        return 80 + 5 * datetime.now().year - self.anno

    def descrizione(self):
        return super().descrizione() + f", cilindrata: {self.cilindrata}"


class Camion(Veicolo):
    def __init__(self, marca, modello, anno, targa, portata_massima):
        super().__init__(marca, modello, anno, targa)
        self.portata_massima = portata_massima

    def calcola_costo_manutenzione(self):
        return 200 + 20 * datetime.now().year - self.anno

    def descrizione(self):
        return super().descrizione() + f", portata massima: {self.portata_massima}"


class Auto(Veicolo):
    def __init__(self, marca, modello, anno, targa, tipo_carburante, numero_porte):
        super().__init__(marca, modello, anno, targa)
        self.tipo_carburante = tipo_carburante
        self.numero_porte = numero_porte

    def calcola_costo_manutenzione(self):
        return 100 + 10 * datetime.now().year - self.anno

    def descrizione(self):
        return super().descrizione() + f", carburante: {self.tipo_carburante}, porte: {self.numero_porte}"


# PARCO VEICOLI ________________________
class ParcoVeicoli:
    def __init__(self):
        self.veicoli = []

    def aggiungi_veicolo(self, veicolo):
        self.veicoli.append(veicolo)

    def stampa_veicoli(self):
        for veicolo in self.veicoli:
            print(veicolo.descrizione())

    def costo_totale_manutenzione(self):
        somma = 0
        for veicolo in self.veicoli:
            somma += veicolo.calcola_costo_manutenzione()
        return somma


if __name__ == "__main__":
    parcheggio = ParcoVeicoli()

    macchina_rossa = Auto("Lancia", "Y", 2012, "BBBB", "diesel", 3)
    camion_blu = Camion("Iveco", "Leoncino", 1998, "CCCC", 3000)
    scooter_nero = Moto("Piaggio", "Liberty", 2010, "AAAAA", 50)

    parcheggio.aggiungi_veicolo(scooter_nero)
    parcheggio.aggiungi_veicolo(macchina_rossa)
    parcheggio.aggiungi_veicolo(camion_blu)

    # abbiamo parcheggiato le nostre macchine nel parcheggio. vediamo quante ce ne sono

    parcheggio.stampa_veicoli()

    """
    Anzichè stampare i costi singolarmente: non tanto bello -> se avessimo 1000 auto, ci mettiamo a mettere 1000 chiamate con 1000 print??
    Meglio usare un for...

        costo1 = macchina_rossa.calcola_costo_manutenzione()
        print(f"Costo manutenzione: {costo1}")

        costo2 = scooter_nero.calcola_costo_manutenzione()
        print(f"Costo manutenzione: {costo2}")

        costo3 = camion_blu.calcola_costo_manutenzione()
        print(f"Costo manutenzione: {costo3}")
    """

    for i in range(0, len(parcheggio.veicoli)):  # iterando sui veicoli
        costo = parcheggio.veicoli[i].calcola_costo_manutenzione()
        print(f"Costo manutenzione: {costo}")

    # per ottenere il costo totale di tutte le auto nel parcheggio
    costo_totale = parcheggio.costo_totale_manutenzione()
    print(f"Costo Totale: {costo_totale}")

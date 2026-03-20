from dipendente import Dipendente


class Azienda:
    def __init__(self) -> None:
        self.dipendenti: list[Dipendente] = []

    def aggiungi_dipendente(self, dipendente: Dipendente):
        self.dipendenti.append(dipendente)

    def calcolo_ral_media(self) -> float:
        ral_totale = 0
        for dip in self.dipendenti:
            ral_totale = ral_totale + dip.ral
        return ral_totale / len(self.dipendenti)

    def __str__(self) -> str:
        lines = ""
        for dip in self.dipendenti:
            lines = lines + str(dip) + "\n"
        return lines

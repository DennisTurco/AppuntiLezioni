from python.corso_enaip.scuola.persona import Persona


class Studente(Persona):
    def __init__(self, nome: str, cognome: str, sesso: str, matricola: str, classe: str):
        super(nome, cognome, sesso)
        self.matricola = matricola
        self.classe = classe
        self.voti: list[float] = []

    def __str__(self):
        return f"{super().__str__(self)}, matricola: {self.matricola}, classe: {self.matricola}"

    def aggiungi_voto(self, voto: float):
        self.voti.append(voto)

    def calcola_media(self):
        return sum(self.voti)/len(self.voti)
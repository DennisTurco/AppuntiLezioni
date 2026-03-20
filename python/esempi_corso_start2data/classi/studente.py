from datetime import datetime


class Studente:
    def __init__(self, nome: str, anno: int, matricola: str, maschio: bool = True):
        self.nome = nome
        self.anno = anno
        self.matricola = matricola
        self.maschio = maschio

    def calcola_eta(self) -> int:
        return datetime.now().year - self.anno

    def __str__(self) -> str:
        return f"nome: {self.nome}, anno: {self.anno}, matricola: {self.matricola}"

    # stiamo definendo la somma: non ha assulatamente senso logico, è solo per mostrare il meme
    def __add__(self, studente: "Studente") -> "Studente":
        return Studente(
            self.nome + studente.nome, (self.anno + studente.anno) // 2, self.matricola + studente.matricola
        )

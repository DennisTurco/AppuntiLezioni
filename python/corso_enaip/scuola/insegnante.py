class Insegnante:
    def __init__(self, nome: str, cognome: str, sesso: str, materie: list[str], classi: list[str]):
        super(nome, cognome, sesso)
        self.materie = materie
        self.classi = classi

    def __str__(self):
        return f"{super().__str__()}, materie: {self.materie}, classi: {self.classi}"
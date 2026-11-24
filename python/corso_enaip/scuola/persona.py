class Persona:
    def __init__(self, nome: str, cognome: str, sesso: str):
        self.nome = nome
        self.cognome = cognome
        self.sesso = sesso

    def __str__(self):
        return f"nome: {self.nome}, cognome: {self.cognome}, sesso: {self.sesso}"
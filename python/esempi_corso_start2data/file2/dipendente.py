class Dipendente:
    def __init__(self, nome: str, matricola: str, ral: int) -> None:
        self.nome = nome
        self.matricola = matricola
        self.ral = ral

    def __str__(self) -> str:
        return f"nome: {self.nome}, matricola: {self.matricola}, RAL: {self.ral}"

    def to_csv(self) -> str:
        return f"{self.nome},{self.matricola},{self.ral}"

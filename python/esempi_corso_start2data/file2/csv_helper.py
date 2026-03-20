from azienda import Azienda


class CsvHelper:
    def to_csv(self, filename: str, azienda: Azienda, header: bool = False):
        with open(filename, "w", encoding="UTF-8") as file:
            if header == True:
                file.write(self.header_csv() + "\n")

            for dip in azienda.dipendenti:
                file.write(dip.to_csv() + "\n")

    def header_csv(self) -> str:
        return "Nome,Matricola,RAL"

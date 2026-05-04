from datetime import date

class EsperienzaLavorativa:
    def __init__(self, nome_impiego: str, data_inizio: date):
        self.__nome_impiego = nome_impiego
        self.__data_inizio = data_inizio

    @property
    def nome_impiego(self):
        return self.__nome_impiego

    @property
    def data_inizio(self):
        return self.__data_inizio

    @property
    def stampa(self):
        print(self.nome_impiego)

    @nome_impiego.setter
    def nome_impiego(self, nome_impiego):
        self.__nome_impiego = nome_impiego

    def __str__(self) -> str:
        return f"{self.__nome_impiego=}, {self.__data_inizio=}"

    # overloading +
    def __add__(self, other):
        return EsperienzaLavorativa(self.__nome_impiego + other.nome_impiego, self.__data_inizio)

    # overloading <
    def __lt__(self, other) -> bool:
        return DateAndTime.precedente(self.__data_inizio, other.data_inizio)

    # overloading >
    def __gt__(self, other) -> bool:
        return DateAndTime.precedente(other.data_inizio, self.__data_inizio)

class DateAndTime:
    @staticmethod
    def precedente(d1: date, d2: date) -> bool:
        if (d1 < d2):
            return True
        return False

####################################################################

# main
esp1 = EsperienzaLavorativa("Insegnante", date(2020, 3, 12))
esp2 = EsperienzaLavorativa("Librario", date(2019, 3, 12))
esp3 = EsperienzaLavorativa("Ballerino", date(2023, 3, 12))

print(DateAndTime.precedente(esp1.data_inizio, esp2.data_inizio))

esp4 = esp2 + esp3
print(esp4)
print(esp4 > esp1)
print(esp2 < esp3)

esp1.stampa
esp1.nome_impiego = "Nuovo impiego"


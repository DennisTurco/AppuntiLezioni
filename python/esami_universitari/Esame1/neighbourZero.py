# public: visibile d'appertutto
# private: visibile solo all'interno della classe

import csv

##################################################################
class neighbourZero:
    # attributi
    _griglia = [[]] # griglia (matrice) privata

    # costruttore
    def __init__(self, griglia):
        self._griglia = griglia
    
    def stampa_griglia(self):
        for riga in self._griglia:
            print(riga)
    
    def zeroes_around(self, x, y):
        n_zeroes = 0

        # check elemento in alto
        if y > 0 and self._griglia[x][y-1] == 0:
            n_zeroes += 1

        # check elemento in basso
        if y < len(self._griglia[0]) and self._griglia[x][y+1] == 0:
            n_zeroes += 1

        # check elemento in destra
        if x < len(self._griglia) and self._griglia[x+1][y] == 0:
            n_zeroes += 1

        # check elemento in sinistra
        if x > 0 and self._griglia[x-1][y] == 0:
            n_zeroes += 1

        return n_zeroes

##################################################################

## Lettura del file csv e traduzione dei valori nella matrice  ##
def ottenimento_matrice_da_file():
    nome_file = input("Inserire nome file: ")
    with open(nome_file, 'r') as file:
        file_csv = csv.reader(file) # lettura del file csv
        griglia = [list(map(int, riga)) for riga in file_csv] # traduzione dei valori in matrice
        return griglia # ritorno della matrice

def main():
    # 1. lettura da file
    griglia = ottenimento_matrice_da_file()
    # 2. creazione oggetto neighbourZero
    neighbour = neighbourZero(griglia)
    neighbour.stampa_griglia()

    conteggio_zeri = neighbour.zeroes_around(1,3)
    print(f"Conteggio zeri: {conteggio_zeri}")

if __name__ == "__main__":
    main()
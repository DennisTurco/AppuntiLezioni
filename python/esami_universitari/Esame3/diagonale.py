import csv

## Lettura del file csv e traduzione dei valori nella matrice  ##
def ottenimento_matrice_da_file(nome_file) -> list[list[int]]:
    with open(nome_file, 'r') as file:
        file_csv = csv.reader(file) # lettura del file csv
        griglia = [list(map(int, riga)) for riga in file_csv] # traduzione dei valori in matrice
        return griglia # ritorno della matrice
    
def stampa_matrice(diagonale):
    for i in range(len(diagonale)):
        for j in range(len(diagonale[0])):
            print(f"{diagonale[i][j]:3} ", end=" ")
        print()

def elevamento_quadrato_diagonale(diagonale):
    # si parte dall'angolo a dx -> x = max, y = max
    # elevare al quadrato il valore di ogni cella sulla diagonale
    # si decrementa ogni volta entrambe
    # si finisce quando una delle 2 raggiunge il valore 0

    x = len(diagonale) - 1
    y = len(diagonale[0]) - 1

    while y >= 0 and x >= 0:
        diagonale[x][y] = diagonale[x][y]**2
        x -= 1
        y -= 1
    
    return diagonale

def scrittura_matrice_su_file(nome_file, diagonale):
    with open(nome_file, 'w', newline='') as file:
        writer = csv.writer(file) # scrittura sul file csv
        writer.writerows(diagonale)

############################################################

def main():
    diagonale = ottenimento_matrice_da_file("./python/Esame3/diagonale.csv")
    print(f"Numero righe = {len(diagonale)} \nNumero Colonne = {len(diagonale[0])}")
    stampa_matrice(diagonale)
    diagonale = elevamento_quadrato_diagonale(diagonale)
    print()
    stampa_matrice(diagonale)
    scrittura_matrice_su_file("./python/Esame3/diagonale_quadrata.csv", diagonale)

if __name__ == "__main__":
    main()
# compile time (a tempo di compilazione)
# es. x = 6

# run time (a tempo di esecuzione)
# es. x = int(input("inserire valore"))

def main():
    x = int(input("righe: "))
    y = int(input("colonne: "))

    spirale = [[0 for _ in range(y)] for _ in range(x)]

    max_x = x - 1
    min_x = 0
    max_y = y - 1
    min_y = 0

    cont = 1

    while cont < x * y:
        # spostamento verso l'alto
        for i in range(max_x, min_x - 1, -1):
            spirale[i][min_y] = cont
            cont += 1
        min_y += 1  # incrementa il limite sinistro

        # spostamento verso destra
        for j in range(min_y, max_y + 1):
            spirale[min_x][j] = cont
            cont += 1
        min_x += 1  # incrementa il limite superiore

        # spostamento verso il basso
        if min_x <= max_x:
            for i in range(min_x, max_x + 1):
                spirale[i][max_y] = cont
                cont += 1
            max_y -= 1  # decrementa il limite destro

        # spostamento verso sinistra
        if min_y <= max_y:
            for j in range(max_y, min_y - 1, -1):
                spirale[max_x][j] = cont
                cont += 1
            max_x -= 1  # decrementa il limite inferiore

    # stampa matrice
    for i in range(x):
        for j in range(y):
            print(f"{spirale[i][j]:2} ", end=" ") # end mi serve altrimenti ad ogni stampa va a capo. Mentre ':2' serve per renderlo piu bellino
        print()

if __name__ == "__main__":
    main()
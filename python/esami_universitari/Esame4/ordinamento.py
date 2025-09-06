
import csv


def ordinamento(lista1, lista2):

    cont_lista1 = 0
    cont_lista2 = 0

    lista_completa = []
    
    while cont_lista1 < len(lista1) and cont_lista2 < len(lista2):
        if lista1[cont_lista1] < lista2[cont_lista2]:
            lista_completa.append(lista1[cont_lista1])
            cont_lista1 += 1
        else:
            lista_completa.append(lista2[cont_lista2])
            cont_lista2 += 1
    
    # aggiungiamo i valori della lista1 che restano fuori (se presenti)
    for i in range(cont_lista1, len(lista1)) :
        lista_completa.append(lista1[i])
    
    # aggiungiamo i valori della lista2 che restano fuori (se presenti)
    for i in range(cont_lista2, len(lista2)) :
        lista_completa.append(lista2[i])
        
    return lista_completa
        

def lettura_lista_da_file(nome_file) -> list[int]:
    with open(nome_file, 'r') as file:
        file_csv = csv.reader(file, delimiter='\n') # lettura del file csv
        lista = [int(riga[0]) for riga in file_csv if riga] # traduzione dei valori in lista
        return lista # ritorno della lista

def stampa_lista(lista):
    for i in range(len(lista)):
        print(f"{lista[i]}", end=' ')
    print()
        
def main():
    lista1 = lettura_lista_da_file("./python/Esame4/lista1.csv")
    lista2 = lettura_lista_da_file("./python/Esame4/lista2.csv")
    
    print("Lista1: ", end='')
    stampa_lista(lista1)
    print("Lista2: ", end='')
    stampa_lista(lista2)
    print("Lista3: ", end='')
    lista3 = ordinamento(lista1, lista2)
    stampa_lista(lista3)

if __name__ == "__main__":
    main()

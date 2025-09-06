def fill(numeri: list[int], indice: int):
    if numeri[indice] != 0:
        return
    
    # modica valori da indice a dx
    for i in range(indice, len(numeri)):
        if numeri[i] == 0:
            numeri[i] = 1
        else:
            break
        
    # modica valori da indice a sx
    for i in range(indice, 0, -1):
        if i == indice or numeri[i] == 0:
            numeri[i] = 1
        else:
            break

## main
lista = [0,0,2,2,0,0,0,0,0,0,0,0,2,0,0,0]
indice = 9
fill(lista, indice)
print(lista)
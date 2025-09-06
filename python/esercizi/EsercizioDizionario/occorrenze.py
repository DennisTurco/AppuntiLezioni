def occorrenze(stringa: str) -> dict[str, int]:
    occorrenze = {}
    
    # "ciao mondo come ciao mondo"
    # ['ciao', 'mondo', 'come', 'ciao', 'mondo']
    parole = stringa.split()
    
    for parola in parole:
        parola = parola.replace('.', '')
        parola = parola.replace('?', '')
        parola = parola.lower()
        if parola in occorrenze:
            occorrenze[parola] += 1 # dict -> occorrenze, key -> parola, value -> += 1
        else:
            occorrenze[parola] = 1
            
    return occorrenze

## main
parole = input("Inserire una frase: ")
dizionario = occorrenze(parole)
print(dizionario)
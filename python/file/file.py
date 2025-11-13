righe_da_copiare_sul_file = '''Ciao come stai?
questa è una seconda riga.
Se abilitato UTF-8 puoi leggere quetso: è € ê̄ η'''

with open("./python/file/test.txt", "w", encoding="UTF-8") as file:
    contenuto = file.write(righe_da_copiare_sul_file)
    print(contenuto)

frase_finale_senza_sovrascrittura = "\nFrase finale in append"

with open("./python/file/test.txt", "a", encoding="UTF-8") as file:
    contenuto = file.write(frase_finale_senza_sovrascrittura)
    print(contenuto)

with open("./python/file/test.txt", "r", encoding="UTF-8") as file:
    contenuto = file.read()
    print(contenuto)

print("Programma Terminato!")
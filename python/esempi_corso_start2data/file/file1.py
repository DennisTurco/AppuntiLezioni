def leggi_da_file(filename: str):
    try:
        with open(filename, "r") as file:
            data = file.read()
            print(data)
    except FileNotFoundError as e:
        print(e)

def scrivi_su_file(filename: str, testo: str):
    with open(filename, "w") as file:
        file.write(testo)

def aggiundi_testo_su_file_senza_sovrascrivere(filename: str, testo: str):
    with open(filename, "a") as file:
        file.write(testo)

filename = "./python/esempi_corso_start2data/file/file1.txt"
scrivi_su_file(filename, "Hello World")
leggi_da_file(filename)
aggiundi_testo_su_file_senza_sovrascrivere(filename, "\nasdhjgadhjsgasdghj")

print()
print()

leggi_da_file(filename)
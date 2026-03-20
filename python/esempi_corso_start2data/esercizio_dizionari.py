# 1. rimuovere la chiave eta
# 2. aggiungere una nuova chiave telefono
# 3. associare un valore a telefono
# 4. stampare il risultato

info = {"nome": "Giovanni", "eta": 30, "città": "Torino"}

del info["eta"]

telefono = input("Numero di telefono: ")

info["telefono"] = telefono

print(info)

# i dizionari hanno la forma chiave-valore
# le chiavi non possono essere duplicate, i valori si

config = {
    "color": "green",
    "width": 42,
    "height": 100,
    "font": ["Courier", "Arial", "Comic Sans"],
}

print(config)

# accesso all'elemento
print(config["height"])
print(config.get("height"))
print(config.get("chiave_inesistente"))

# valori e chiavi

# lista dei valori
print(config.values())
# lista delle chiavi
print(config.keys())

# modifica
config["height"] = 300
print(config["height"])


# iterazione con ciclo
for chiave, valore in config.items():
    print(f"La chiave è: {chiave} e ha il valore di: {valore}")

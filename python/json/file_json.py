import json
from typing import Any

# json.dump come se fosse write
# json.load come se fosse read

with open("./python/json/user.json", "r", encoding="UTF-8") as file:
    contenuto = json.load(file)

# print(contenuto)
print(contenuto["email"])


################################################

persona: dict[str, Any] = {
    "nome": "Giulia",
    "età": 30,
    "linguaggi": ["Python", "Go"],
    "isAdmin": True
}

with open("./python/json/persona.json", "w", encoding="UTF-8") as file:
    json.dump(persona, file)

with open("./python/json/persona.json", "r", encoding="UTF-8") as file:
    data = json.load(file)

print(data["nome"])
persona["nome"] = "Francesca"

with open("./python/json/persona.json", "w", encoding="UTF-8") as file:
    json.dump(data, file)
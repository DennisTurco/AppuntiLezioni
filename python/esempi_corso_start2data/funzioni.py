from datetime import datetime


def calcolo_eta(anno: int) -> int:
    return datetime.now().year - anno


# la funzione nopn ha return -> che non ritorna nessun valore al chiamante
# prende 2 parametri e in entrambi i casi abbiamo spe ificato il tipo -> type hint
# in questo caso abbiamo impostato un parametro con un valore di default = 2000, se il chimante non lo passa viene usato il valore di default.
# Nota: i valori di default se presenti vanno in fondo ai parametri
# nelle funzioni, i valori di input della funzione prendono il nome di PARAMETRI della funzione
# linea guida: cercare di tenere le funzioni con meno parametri possibili.
def saluta(nome: str, anno: int = 2000) -> None:
    eta = calcolo_eta(
        anno
    )  # variabile locale alla funzione: viene creata in questa riga e distrutta alla terminazione della funzione
    print(f"Ciao da {nome}, ho {eta} anni!")


eta = calcolo_eta(2009)  # variabile globale

# nelle chimate di funzioni, i valori passati alla funzione prendono il nome di ARGOMENTI della funzione
saluta("Dennis", 2001)
saluta("Donatello", 2001)
saluta("Francesco")

print(eta)

# possibile anche passare gli argomenti per chiave
saluta(anno=2005, nome="Culettino")

from studente import Studente

studenti: list[Studente] = []

# istanze della classe
s1 = Studente("Dennis", 2001, "3784623")
s2 = Studente("Donatello", 2001, "3284234")
s3 = Studente("Carmela", 1999, "33784243", False)
studenti.append(s1)
studenti.append(s2)
studenti.append(s3)

for stud in studenti:
    print(stud)  # posso stampare l'oggetto studente perchè abbiamo definito il  metodo __str__

# proviamo il metodo __add__ della classe
s4 = s1 + s2
print(s4)

# proviamo il metodo calcola età
print(s4.calcola_eta())

# funzioni lambda: funzioni anonime -> non mettiamo la testata della funzione

somma = lambda a, b: a + b
print(somma(5, 6))

numbers = [-2, -1, -2]
numbers_absolute = list(map(lambda x: abs(x), numbers))
print(numbers_absolute)
numbers_ordered = sorted(numbers_absolute)
print(numbers_ordered)


student_tuples = [
    ("john", "A", 15),
    ("jane", "B", 12),
    ("dave", "B", 10),
]
lista_ordinata = sorted(student_tuples, key=lambda x: x[2])
print(lista_ordinata)

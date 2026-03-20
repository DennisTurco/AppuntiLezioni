import logging

logging.basicConfig(
    level=logging.DEBUG,
    filename="./python/logging/logs.log",
    format="%(asctime)s - [%(levelname)s] (%(filename)s:%(lineno)d) - %(message)s",
)

logging.info("Programma iniziato")

try:
    n = int(input("Numeratore: "))
    d = int(input("Denominatore: "))
    risultato = n / d
    print(f"Risultato = {risultato}")
except ZeroDivisionError:
    logging.error("impossibile eseguire la divisione")

logging.info("Programma terminato")

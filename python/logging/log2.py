import logging

# Creazione di un logger
logger = logging.getLogger("app_logger")
logger.setLevel(logging.DEBUG)

# Creazione di un handler per la console
console_handler = logging.StreamHandler()
console_handler.setLevel(logging.ERROR)

# Creazione di un handler per il file
file_handler = logging.FileHandler("./python/logging/logs2.log")
file_handler.setLevel(logging.DEBUG)

# Formattazione
formatter = logging.Formatter("%(asctime)s - %(levelname)s - %(message)s")
console_handler.setFormatter(formatter)
file_handler.setFormatter(formatter)

# Aggiunta degli handler al logger
logger.addHandler(console_handler)
logger.addHandler(file_handler)

# Esempio di log
logger.debug("Questo messaggio va solo nel file.")
logger.info("Questo messaggio appare su console e file.")
logger.error("Errore critico!")

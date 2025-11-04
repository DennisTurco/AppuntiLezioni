# Guida alla compilazione di file C++

## Info utili

Questa guida spiega come compilare ed eseguire un programma C++ dal terminale, utilizzando **g++** (incluso con MinGW o altre distribuzioni GCC).

---

## Compilazione di un singolo file

Se il tuo progetto ha un solo file sorgente, ad esempio `main.cpp`, puoi compilarlo così:

```bash
g++ main.cpp -o main
```

Questo comando:

- compila il file main.cpp;
- genera un eseguibile chiamato main (su Windows sarà main.exe);
- se non ci sono errori, potrai eseguirlo con:

```bash
./main
```

oppure su Windows:

```bash
main.exe
```

---

## Compilazione di più file

Se il tuo progetto è composto da più file (es.`main.cpp` e `UfficioPostale.cpp`), devi includerli tutti nel comando di compilazione:

```bash
g++ main.cpp UfficioPostale.cpp -o eseguibile
```

Questo comando crea un eseguibile chiamato `eseguibile` (o `eseguibile.exe` su Windows).

---

## Compilazione con più file in cartelle

Se i file sono organizzati in sottocartelle (es. `src/` e `include/`), puoi indicare i percorsi esplicitamente:

```bash
g++ src/main.cpp src/UfficioPostale.cpp -Iinclude -o eseguibile
```

- `Iinclude` aggiunge la cartella `include/` come percorso dove cercare i file `.h`.

---

## Suggerimenti utili

1. Usa `-Wall` per attivare tutti gli avvisi utili:

   ```bash
   g++ -Wall main.cpp UfficioPostale.cpp -o eseguibile
   ```

2. Usa `-std=c++17` o `-std=c++20 `per specificare lo standard del linguaggio:

   ```bash
   g++ -std=c++17 -Wall main.cpp UfficioPostale.cpp -o eseguibile
   ```

---

## Riassunto

| Caso                             | Comando                                     |
| -------------------------------- | ------------------------------------------- |
| Un solo file `.cpp`              | `g++ main.cpp -o main`                      |
| Più file `.cpp`                  | `g++ main.cpp UfficioPostale.cpp -o eseguibile` |
| Con cartelle `src/` e `include/` | `g++ src/*.cpp -Iinclude -o eseguibile`         |
| Aggiungere avvisi                | `g++ -Wall main.cpp ...`                    |
| Specificare standard C++         | `g++ -std=c++17 ...`                        |

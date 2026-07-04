# Esercizi Java

Raccolta di esercizi e lezioni di programmazione in Java, con particolare attenzione alla programmazione a oggetti (classi, ereditarietà, incapsulamento, interfacce) e alle strutture dati.

## Contenuti

| Cartella | Argomento |
| --- | --- |
| `classi/` | Concetti base di classi e oggetti |
| `Incapsulamento/` | Incapsulamento |
| `ereditarieta/`, `ereditarieta_esempio_completo/`, `EsercizioStudenteBase/`, `EsercizioStudenteBaseEreditarieta/` | Ereditarietà tra classi (es. `Persona` → `Studente`/`Insegnante`) |
| `DowncastUpcasting/` | Downcasting e upcasting |
| `Interfacce/` | Interfacce e polimorfismo (esempio nemici di un videogioco) |
| `Wrapper/` | Classi wrapper e boxing/unboxing |
| `Array/` | Array e implementazione di una lista basata su array |
| `Lista/` | Liste collegate, pile, code e vari esercizi applicativi (auto, corriere, docenti, moto, punti) |
| `binarytree/` | Alberi binari |
| `hashmap/` | `HashMap` |
| `Backtracking/` | Algoritmi di backtracking |
| `Matrici/` | Esercizi su matrici |
| `InputOutput/` | Lettura input/output da console |
| `Logging/` | Logging con formatter personalizzati |
| `JUnitExample/` | Test unitari con JUnit |
| `Binding/` | Esempio di gerarchia dispositivi (PC, Smartphone) |
| `Scuola/`, `Albergo/`, `EsercizioAereo/` | Esercizi applicativi più ampi che combinano i concetti precedenti |
| `CorsoMinecraft/` | Lezioni introduttive (classi, ereditarietà) con esempi a tema Minecraft |
| `EserciziRandom/`, `EquazioneSoluzioni/` | Esercizi vari |

## Come compilare ed eseguire

Ogni cartella sotto `src/` è un package Java a sé stante. Da terminale, posizionandosi in `Java/src`:

```bash
javac NomeCartella/*.java -d ../out
java -cp ../out NomeCartella.NomeClassePrincipale
```

In alternativa, apri la cartella in VS Code con l'estensione **Extension Pack for Java** e usa il pulsante *Run* sopra al metodo `main`.

class Speculatore:
    # versione con matrice
    def maxProfitVersion1(self, azioni, prezzi):
        # caso errore
        if len(prezzi) <= 0: raise Exception(f"il numero dello storico dei prezzi non puo' essere {len(prezzi)} (<= 0)")

        # https://www.geeksforgeeks.org/initialize-matrix-in-python/
        # matrix = [[0]*cols for _ in range(rows)]        
        # rows -> len(prezzi)
        # cols -> azioni
        matrix = [[0] * (azioni + 1) for _ in range(len(prezzi))]

        for i in range(1, azioni + 1):
            max_diff = -prezzi[0] # spesa iniziale
            for j in range(1, len(prezzi)):
                
                # matrix[j - 1][i]  -> utile totale fino adesso (calcolato all'iterazione precedente)
                # prezzi[j]         -> guadagno vendendo
                # max_diff          -> spesa
                print(f'matrix[{j}][{i}] = max({matrix[j - 1][i]}, {prezzi[j]} + {max_diff})')
                matrix[j][i] = max(matrix[j - 1][i], prezzi[j] + max_diff)
                
                # cerchiamo di capire se esiste un giorno in cui la spesa è minore di quello scelto
                print(f'max_diff = max({max_diff}, {matrix[j - 1][i - 1]} - {prezzi[j]})')
                max_diff = max(max_diff, matrix[j - 1][i - 1] - prezzi[j])

        return matrix[len(prezzi) - 1][azioni] # ritorniamo l'ultima posizione
    
    # versione senza matrice (NON FUNZIONA AL 100%)
    def maxProfitVersion2(self, azioni, prezzi):
        # caso errore
        if len(prezzi) <= 0: raise Exception(f"il numero dello storico dei prezzi non puo' essere {len(prezzi)} (<= 0)")
        
        azioni_temp = azioni
        profit = 0
        max_profit = 0
        
        i = 0   # -> tiene traccia del costo di quando acquisto  
        j = 0   # -> tiene traccia del valore di quando vendo
        for repeat in range(len(prezzi)):
            i = repeat
            azioni = azioni_temp
            profit = 0
            while i < len(prezzi):
                j = i + 1
                while j < len(prezzi):
                    
                    if azioni <= 0: break 
                    
                    if (prezzi[j] - min(prezzi[:j]) > 0) and (azioni > 0): 
                        profit += prezzi[j] - min(prezzi[:j])
                        i = j + 1
                        j += 1
                        azioni -= 1
                    
                    j += 1
                i += 1
                                
                if profit > max_profit:
                    max_profit = profit

        return max_profit
    
    # (NON FUNZIONA AL 100%)
    def maxProfitVersion3(self, k, P):
        n = len(P)
        if n < 2 or k == 0:
            return 0

        # Calcoliamo i profitti giornalieri come differenze positive tra giorni successivi
        lista_profitti = [max(P[i + 1] - P[i], 0) for i in range(n - 1)]

        # Ordiniamo la lista dei profitti in modo decrescente
        lista_profitti.sort(reverse=True)

        # Sommiamo i primi k profitti per ottenere il massimo profitto
        return sum(lista_profitti[:k])

    """
    Stiamo calcolando il massimo tra due opzioni in ciascun giorno i e per ogni valore di j da 1 a k.

    passo dopo passo:
    -> matrix[i][j] rappresenta il massimo profitto fino al giorno i effettuando esattamente j transazioni (acquisti e vendite) di azioni.
    -> matrix[i - 1][j] rappresenta il massimo profitto ottenuto fino al giorno i-1 con le stesse j transazioni. Quindi, rappresenta il profitto 
        ottenuto fino al giorno precedente senza effettuare alcuna transazione nell'attuale giorno i.
    -> P[i] + max(matrix[x][j - 1] - P[x] for x in range(i)) rappresenta il profitto ottenuto acquistando l'azione 
        il giorno i e vendendola in uno dei giorni precedenti x (da 0 a i-1) con una transazione rimanente. 
        La parte interna matrix[x][j - 1] - P[x] rappresenta il massimo profitto ottenuto fino al giorno x con j - 1 transazioni, 
        sottraendo il prezzo dell'azione nel giorno x (acquisto). Aggiungiamo quindi il prezzo dell'azione nel giorno i per calcolare 
        il profitto totale se acquistiamo nel giorno i e vendiamo in uno dei giorni precedenti.
    -> max(matrix[i - 1][j], P[i] + max(matrix[x][j - 1] - P[x] for x in range(i))) calcola il massimo tra le due opzioni sopra menzionate. 
        Quindi, decidiamo se è più vantaggioso non effettuare una transazione oggi (matrix[i - 1][j]) o effettuare una transazione oggi 
        (P[i] + max(matrix[x][j - 1] - P[x] for x in range(i))) in modo da massimizzare il profitto fino al giorno i con j transazioni.

    Questa logica viene applicata in un ciclo per tutti i giorni i e per tutti i possibili valori di j, in modo da determinare il massimo profitto possibile fino all'ultimo giorno, rispettando le regole specificate nel problema.
    """
    def maxProfitVersion4(self, k, P):
        # caso errore
        if len(P) <= 0: raise Exception(f"il numero dello storico dei prezzi non puo' essere {len(P)} (<= 0)")

        n = len(P)

        # Creiamo una lista per memorizzare i massimi profitti
        # https://www.geeksforgeeks.org/initialize-matrix-in-python/
        # matrix = [[0]*cols for _ in range(rows)]        
        # rows -> n
        # cols -> k + 1
        matrix = [[0] * (k + 1) for _ in range(n)]

        # i                 -> giorno
        # j da 1 a k+1      -> valori
        for i in range(1, n):
            for j in range(1, k + 1):
                # Calcoliamo il massimo tra il profitto ottenuto vendendo il titolo il giorno i
                # o il profitto ottenuto acquistando il titolo il giorno i dopo una vendita precedente
                matrix[i][j] = max(matrix[i - 1][j], P[i] + max(matrix[x][j - 1] - P[x] for x in range(i)))
                
                # for x in range(i):
                #     # P[x] rappresenta la spesa
                #     # P[i] rappresenta la vendita (test)
                #     print(f"matrix[{i}][{j}] = max(matrix[{i - 1}][{j}], {P[i]} + matrix[{x}][{j - 1}] - {P[x]})")
                #     matrix[i][j] = max(matrix[i - 1][j], P[i] + matrix[x][j - 1] - P[x])
                
        return matrix[n - 1][k]

# Esempio
############################ main
#P = [3, 2, 6, 5, 0, 3]
P = [3, 0, 3, 5, 2, 6]
k = 2
try: 
    speculator = Speculatore()
    print("massimo guadagno:", speculator.maxProfitVersion4(k, P))
except Exception as e:
    print(f"Exception: {e}")
############################
struct Valutazione {
    int location, servizio, menu, conto;
    bool inserita;
    bool bonusAggiunto;
    int totaleValutazione;
};

class NRistoranti {
    int N;
    int M;
    Valutazione** matrice;
    char* nomi;
    NRistoranti(int m, int n);
    int indiceRistorante(char nomeRistorante);

public:
    //PRIMA PARTE
    NRistoranti(int n);
    void aggiungiValutazione(char nomeRistorante, int giudice, int loc, int serv, int men, int cont);
    void aggiungiBonus(char nomeRistorante, int bonus);
    friend ostream& operator<<(ostream&, const NRistoranti&);

    //SECONDA PARTE
    NRistoranti(const NRistoranti&);
    ~NRistoranti();
    NRistoranti& operator~();
    NRistoranti operator!() const;
};
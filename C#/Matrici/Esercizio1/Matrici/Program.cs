using System;

class Program
{
    public static void EsercizioRigaColonnaPiuAlta()
    {
        int row = 4;
        int col = 4;

        int[,] matrice = GeneraMatriceRandomica(row, col);

        StampaMatrice(matrice, row, col);

        // riga di somma max
        int sommaRow, maxSommaRow = 0, indexMaxSommaRow = 0;
        for (int i = 0; i < row; i++)
        {
            sommaRow = 0; // resetto il valore a 0 ogni volta che mi sposto di una riga
            for (int j = 0; j < col; j++)
            {
                sommaRow += matrice[i, j];
            }

            if (sommaRow > maxSommaRow)
            {
                maxSommaRow = sommaRow;
                indexMaxSommaRow = i;
            }
        }

        // colonna di somma max
        int sommaCol, maxSommaCol = 0, indexMaxSommaCol = 0;
        for (int i = 0; i < row; i++)
        {
            sommaCol = 0;
            for (int j = 0; j < col; j++)
            {
                sommaCol += matrice[j, i];
            }

            if (sommaCol > maxSommaCol)
            {
                maxSommaCol = sommaCol;
                indexMaxSommaCol = i;
            }
        }

        if (maxSommaRow > maxSommaCol)
        {
            Console.WriteLine($"La somma maggiore è {maxSommaRow} e si trova nella riga {indexMaxSommaRow}");
        }
        else
        {
            Console.WriteLine($"La somma maggiore è {maxSommaCol} e si trova nella colonna {indexMaxSommaCol}");
        }
    }

    public static void EsercizioTabellinaPitagorica()
    {
        int row = 10;
        int col = 10;
        int[,] matrice = new int[row, col];

        // generazione valeori matrice
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrice[i, j] = (i+1) * (j+1);
            }
        }

        StampaMatrice(matrice, row, col);
    }

    public static void EsercizioTraduzioni()
    {
        // row -> parole, col -> lingue
        int row = 3, col = 2;
        string[,] traduzioni = PopolaMatriceTraduzioni();

        string testo = "Ciao, ho il gatto sulla tastiera";

        Console.WriteLine($"Testo originale: {testo}");

        for (int i = 0; i < row; i++)
        {
            if (testo.ToLower().Contains(traduzioni[i,0]))
            {
                testo = testo.ToLower().Replace(traduzioni[i, 0], traduzioni[i, 1]);
            }
        }

        Console.WriteLine($"Testo tradotto: {testo}");
    }

    public static void StampaMatrice(int[,] matrice, int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                Console.Write($"{matrice[i, j]}\t");
            }
            Console.WriteLine();
        }
    }

    public static int[,] GeneraMatriceRandomica(int row, int col)
    {
        int[,] matrice = new int[row, col];
        Random random = new Random();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrice[i, j] = random.Next(1, 10);
            }
        }

        return matrice;
    }

    public static string[,] PopolaMatriceTraduzioni()
    {
        string[,] traduzioni = new string[3, 2];
        traduzioni[0, 0] = "ciao";      traduzioni[0, 1] = "hello";
        traduzioni[1, 0] = "gatto";     traduzioni[1, 1] = "cat";
        traduzioni[2, 0] = "tastiera";  traduzioni[2, 1] = "keyboard";

        return traduzioni;
    }

    public static void Main()
    {
        //EsercizioRigaColonnaPiuAlta();
        //EsercizioTabellinaPitagorica();
        EsercizioTraduzioni();
    }
}

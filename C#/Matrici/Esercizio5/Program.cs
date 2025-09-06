using System.Data;

namespace Esercizio5
{
    public class Program
    {
        public static void Main()
        {
            int row = 3;
            int col = 5;

            int[,] biblioteca = PopolaBiblioteca(row, col);
            StampaBiblioteca(biblioteca, row, col);
            int somma = NumeroTotaleLibri(biblioteca, row, col);
            Console.WriteLine($"Somma totale libri = {somma}");
            int indicePiano = PianoConPiuLibri(biblioteca, row, col);
            Console.WriteLine($"Piano con più libri: {indicePiano}");
            Console.WriteLine($"Media libri per scaffale: {(float)somma / (row * col)}");
        }

        private static int[,] PopolaBiblioteca(int row, int col)
        {
            int[,] biblioteca = new int[row, col];

            Random random = new Random();
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    biblioteca[i, j] = random.Next(0, 21);
                }
            }
            return biblioteca;
        }

        private static void StampaBiblioteca(int[,] biblioteca, int row, int col)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    Console.Write($"{biblioteca[i, j]}\t");
                }
                Console.WriteLine();
            }
        }

        private static int NumeroTotaleLibri(int[,] biblioteca, int row, int col)
        {
            int somma = 0;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    somma += biblioteca[i, j];
                }
            }
            return somma;
        }

        private static int PianoConPiuLibri(int[,] biblioteca, int row, int col)
        {
            int sommaRiga;
            int sommaMaxRiga = 0;
            int indiceMaxRiga = 0;
            for (int i = 0; i < row; i++)
            {
                sommaRiga = 0;
                for (int j = 0; j < col; j++)
                {
                    sommaRiga += biblioteca[i, j];
                }
                if (sommaRiga > sommaMaxRiga)
                {
                    sommaMaxRiga = sommaRiga;
                    indiceMaxRiga = i;
                }
            }
            return indiceMaxRiga;
        }
    }
}
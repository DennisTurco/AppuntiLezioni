namespace Esercizio4
{
    public class Program
    {
        public static int[,] GeneraMatriceConValoriCasuali(int dim)
        {
            int[,] matrice = new int[dim,dim];
            Random random = new Random();
            for (int i = 0; i < dim; i++)
            {
                for (int j = 0; j < dim; j++)
                {
                    matrice[i,j] = random.Next(1, 101);
                }
            }
            return matrice;
        }

        public static void StampaMatrice(int[,] matrice, int dim)
        {
            for (int i = 0; i < dim; i++)
            {
                for (int j = 0; j < dim; j++)
                {
                    Console.Write($"{matrice[i, j]}\t");
                }
                Console.WriteLine();
            }
        }

        public static void SommaRigaEColonna(int[,] matrice, int dim)
        {
            int sommaRiga = 0;
            int sommaColonna = 0;
            for (int i = 0; i < dim; i++)
            {
                sommaRiga = 0;
                sommaColonna = 0;
                for (int j = 0; j < dim; j++)
                {
                    sommaRiga += matrice[i, j];
                    sommaColonna += matrice[j, i];
                }
                Console.WriteLine($"Somma riga {i + 1}: {sommaRiga}");
                Console.WriteLine($"Somma colonna {i + 1}: {sommaColonna}");
            }
        }

        public static void StampaMassimo(int[,] matrice, int dim)
        {
            int indiceRiga = 0, indiceColonna = 0;
            int max = matrice[indiceRiga, indiceColonna];
            for (int i = 0; i < dim; i++)
            {
                for (int j = 0; j < dim; j++)
                {
                    if (matrice[i,j] > max)
                    {
                        max = matrice[i, j];
                        indiceRiga = i;
                        indiceColonna = j;
                    }
                }
            }

            Console.WriteLine($"Il valore massimo è {max} e si trova in posizione ({indiceRiga}, {indiceColonna})");
        }

        /*
        3 2 1
        4 5 2
        1 4 5
        Diagonale principale = 3 5 5
        */
        public static void StampaDiagonalePrincipale(int[,] matrice, int dim)
        {
            Console.Write("Diagonale principale: ");
            for (int i = 0; i < dim; i++)
            {
                Console.Write($"{matrice[i, i]} ");
            }
        }

        /*
        - 2 1
        2 - 4
        1 4 -
        simmetrica
        */
        // 1,0 == 0,1 && 2,0 == 0,2 && 2,1 == 1,2
        public static bool isSimmetrica(int[,] matrice, int dim)
        {
            for (int i = 0; i < dim; i++)
            {
                for (int j = 0; j < dim; j++)
                {
                    if (matrice[i,j] != matrice[j,i])
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        public static void Main(string[] args)
        {
            Console.Write("Inserisci dimensione matrice: ");
            int dim = Convert.ToInt32(Console.ReadLine());
            int[,] matrice = GeneraMatriceConValoriCasuali(dim);
            StampaMatrice(matrice, dim);
            SommaRigaEColonna(matrice, dim);
            StampaMassimo(matrice, dim);
            StampaDiagonalePrincipale(matrice, dim);
            if (isSimmetrica(matrice, dim))
            {
                Console.WriteLine("\nLa matrice è simmetrica");
            }
            else
            {
                Console.WriteLine("\nLa matrice non è simmetrica");
            }
        }
    }
}
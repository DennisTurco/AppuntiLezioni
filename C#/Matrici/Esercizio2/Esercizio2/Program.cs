using System;
using System.Data;

class Program
{
    public static int GetNumeroSociByInteresse(string[,] iscritti, int row, string interesse)
    {
        int cont = 0;

        for (int i = 0; i < row; i++ )
        {
            if (iscritti[i,3].Equals(interesse))
            {
                cont++;
            }
        }

        return cont;
    }

    public static void StampaDatiIscrittiConAnniIscrizioneMaggiore(string[,] iscritti, int row, int anni)
    {
        for (int i = 0; i < row; i++)
        {
            if (Convert.ToInt32(iscritti[i,2]) >= anni)
            {
                Console.WriteLine($"Nome: {iscritti[i,0]}, Tessera: {iscritti[i, 1]}, Anni: {iscritti[i, 2]}, Interessi: {iscritti[i, 3]}, Età: {iscritti[i, 4]}");
            }
        }
    }

    public static float GetEtaMediaSociConAnniMaggiore5(string[,] iscritti, int row)
    {
        float somma = 0;
        int cont = 0;
        for (int i = 0; i < row; i++)
        {
            if (Convert.ToInt32(iscritti[i,2]) >= 5)
            {
                somma += Convert.ToInt32(iscritti[i, 4]);
                cont++;
            }
        }

        return somma / cont;
    }

    public static void Menu(string[,] iscritti, int row, int col)
    {
        bool continuare = true;
        char scelta;
        do
        {
            Console.Write("Scelgli l'opzione:\na. Numero di soci con un dato tipo di interesse. \nb. Dati relativi al socio con più anni di iscrizione. \nc. Età media dei soci iscritti da più di 5 anni.\n0. Per uscire. \nOpzione: ");
            scelta = Convert.ToChar(Console.ReadLine());
            switch (scelta)
            {
                case 'a':
                    Console.Write("Interesse: ");
                    string interesse = Console.ReadLine();
                    int quantita = GetNumeroSociByInteresse(iscritti, row, interesse);
                    Console.WriteLine($"Numero iscritti con interesse {interesse}: {quantita}");
                    break;
                case 'b':
                    Console.Write("Anni: ");
                    int anni = Convert.ToInt32(Console.ReadLine());
                    StampaDatiIscrittiConAnniIscrizioneMaggiore(iscritti, row, anni);
                    break;
                case 'c':
                    float media = GetEtaMediaSociConAnniMaggiore5(iscritti, row);
                    Console.WriteLine($"Età media: {media}");
                    break;
                case '0':
                    continuare = false;
                    break;
                default:
                    Console.WriteLine("Errore! Scelta non disponibile!");
                    break;
            }
        } while (continuare); 
    }

    public static string[,] PopolaIscritti(int row, int col)
    {
        string[,] iscritti = new string[row, col];

        for (int i = 0; i < row; i++)
        {
            Console.WriteLine($"Inserimento iscritto n^{i+1}: ");
            Console.Write("Nome e cognome: ");
            iscritti[i, 0] = Console.ReadLine();

            do
            {
                Console.Write("Numero tessera (16 char): ");
                iscritti[i, 1] = Console.ReadLine();

                if (iscritti[i, 1].Length != 16)
                {
                    Console.WriteLine("Errore!, si prega di fornire un valore valido.");
                }
            } while (iscritti[i, 1].Length != 16);

            bool valido = true;
            do
            {
                Console.Write("Interessi (numero da 1 a 10): ");
                iscritti[i, 3] = Console.ReadLine();

                valido = Convert.ToInt32(iscritti[i, 3]) >= 1 && Convert.ToInt32(iscritti[i, 3]) <= 10;

                if (!valido)
                {
                    Console.WriteLine("Errore!, si prega di fornire un valore valido.");
                }
            } while (!valido);

            valido = true;
            do
            {
                Console.Write("Anni di iscrizione: ");
                iscritti[i, 2] = Console.ReadLine();
                Console.Write("Età: ");
                iscritti[i, 4] = Console.ReadLine();

                valido = Convert.ToInt32(iscritti[i, 2]) < Convert.ToInt32(iscritti[i, 4]);

                if (!valido)
                {
                    Console.WriteLine("Errore!, si prega di fornire un valore valido.");
                }

            } while (!valido);
        }
        return iscritti;
    }

    public static void Main()
    {
        int row;
        do
        {
            Console.Write("Quante persone vuoi iscrivere al club? ");
            row = Convert.ToInt32(Console.ReadLine());

            if (row <= 0)
            {
                Console.WriteLine("Errore!, si prega di fornire un valore valido.");
            }
        } while (row <= 0);
        

        string[,] iscritti = PopolaIscritti(row, 5);

        Menu(iscritti, row, 5);
    }
}

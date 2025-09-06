namespace Matrici.Esercizio3
{
    public class Esercizio3
    {
        private const int DAYS = 31;
        private const int MONTHS = 12;

        public static void Main()
        {
            int[,] mesi = GeneraGiorniMesiPioggia();
            Menu(mesi);
        }

        private static void Menu(int[,] mesi)
        {
            int scelta;
            do
            {
                Console.Write("\n0. Termina;\n1. Giorno in cui ha piovuto di più;\n2. Mesi con precipitazioni minori della media.\nScelta: ");
                scelta = Convert.ToInt32(Console.ReadLine());
                switch (scelta)
                {
                    case 0:
                        break;
                    case 1:
                        Console.Write("Inserisci mese: ");
                        string mese = Console.ReadLine();
                        int giorno = GiornoConPiuPioggia(mesi, mese);
                        Console.WriteLine($"Il giorno che ha piovuto di più è il giorno: {giorno+1}");
                        break;
                    case 2:
                        StampaMesiConMediaMinDiPioggia(mesi);
                        break;
                    default:
                        Console.WriteLine("Errore! scelta non disponibile...");
                        break;
                }
            } while (scelta != 0);
            
        }

        private static int GiornoConPiuPioggia(int[,] mesi, string mese)
        {
            int indiceMese = GetIndexByMonth(mese);
            int[] giorni = GetRowFromMatrix(mesi, indiceMese);
            return MaxGiornoPioggia(giorni);
        }

        private static void StampaMesiConMediaMinDiPioggia(int[,] mesi)
        {
            // media complessiva
            float somma = 0;
            for (int i = 0; i < MONTHS; i++)
            {
                int[] giorni = GetRowFromMatrix(mesi, i);
                somma += SommaPrecipitazioniByDays(giorni);
            }
            float media = somma / MONTHS;

            // stampa dei mesi la cui somma è minore della media
            Console.WriteLine("Elenco mesi: ");
            for (int i = 0; i < MONTHS; i++)
            {
                int[] giorni = GetRowFromMatrix(mesi, i);
                if (SommaPrecipitazioniByDays(giorni) < media)
                {
                    Console.WriteLine(GetMonthByIndex(i));
                }
            }
        }

        private static float SommaPrecipitazioniByDays(int[] giorni)
        {
            float somma = 0;
            for (int i = 0; i < giorni.Length; i++)
            {
                somma += giorni[i];
            }
            return somma;
        }

        private static int MaxGiornoPioggia(int[] giorni)
        {
            int max = giorni[0];
            for (int i = 0; i < giorni.Length; i++)
            {
                if (giorni[i] > max)
                {
                    max = giorni[i];
                }
            }
            return max;
        }

        private static int[] GetRowFromMatrix(int[,] matrix, int rowIndex)
        {
            int[] row = new int[DAYS];
            for (int i = 0; i < DAYS; i++)
            {
                row[i] = matrix[rowIndex, i];
            }
            return row;
        }

        private static int GetIndexByMonth(string mese)
        {
            mese = mese.Trim();
            mese = mese.ToLower();
            switch (mese)
            {
                case "gennaio":
                    return 0;
                case "febbraio":
                    return 1;
                case "marzo":
                    return 2;
                case "aprile":
                    return 3;
                case "maggio":
                    return 4;
                case "giugno":
                    return 5;
                case "luglio":
                    return 6;
                case "agosto":
                    return 7;
                case "settembre":
                    return 8;
                case "ottobre":
                    return 9;
                case "novembre":
                    return 10;
                case "dicembre":
                    return 11;
                default:
                    return -1;
            }
        }

        private static string GetMonthByIndex(int mese)
        {
            switch (mese)
            {
                case 0:
                    return "gennaio";
                case 1:
                    return "febbraio";
                case 2:
                    return "marzo";
                case 3:
                    return "aprile";
                case 4:
                    return "maggio";
                case 5:
                    return "giugno";
                case 6:
                    return "luglio";
                case 7:
                    return "agosto";
                case 8:
                    return "settembre";
                case 9:
                    return "ottobre";
                case 10:
                    return "novembre";
                case 11:
                    return "dicembre";
                default:
                    return "error";
            }
        }
        
        private static int[,] GeneraGiorniMesiPioggia()
        {
            int[,] giorni = new int[MONTHS, DAYS];

            Random random = new Random();
            for (int i = 0; i < MONTHS; i++)
            {
                for (int j = 0; j < DAYS; j++)
                {
                    giorni[i,j] = random.Next(0, 10);
                }
            }

            return giorni;
        }
    }
}
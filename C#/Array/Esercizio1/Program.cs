namespace Esercizio1 {

    public class Program
    {
        const int partecipanti = 3;
        public static void Main()
        {
            string[] nomi = new string[partecipanti];
            double[] tempi = new double[partecipanti];
            PopolamentoDatiPartecipanti(nomi, tempi);
            Console.WriteLine($"Tempo medio = {TempoMedio(tempi)}");
            StampaPrimoEUltimo(nomi, tempi);
            Stampa(nomi, tempi);
            StampaTempiOrdinati(nomi, tempi);
        }

        private static void PopolamentoDatiPartecipanti(string[] nomi, double[] tempi)
        {
            for (int i = 0; i < partecipanti; i++)
            {
                Console.Write($"Nome partecipante {i + 1}: ");
                nomi[i] = Console.ReadLine();
                Console.Write($"Tempo partecipante {i + 1}: ");
                tempi[i] = Convert.ToDouble(Console.ReadLine());
            }
        }

        private static double TempoMedio(double[] tempi)
        {
            double somma = 0;
            for (int i = 0; i < partecipanti; i++) 
            {
                somma += tempi[i];
            }
            return somma/partecipanti;
        }

        private static void StampaPrimoEUltimo(string[] nomi, double[] tempi)
        {
            int indicePrimo = 0, indiceUltimo = 0;
            double max = tempi[indicePrimo];
            double min = tempi[indiceUltimo];

            for (int i = 0; i < partecipanti; i++)
            {
                if (tempi[i] > max)
                {
                    max = tempi[i];
                    indicePrimo = i;
                }
                if (tempi[i] < min)
                {
                    min = tempi[i];
                    indiceUltimo = i;
                }
            }

            Console.WriteLine($"Il vincitore è \"{nomi[indicePrimo]}\" con il tempo di {tempi[indicePrimo]}");
            Console.WriteLine($"L'ultimo è \"{nomi[indiceUltimo]}\" con il tempo di {tempi[indiceUltimo]}");
        }

        private static void StampaTempiOrdinati(string[] nomi, double[] tempi)
        {
            string[] nomiTemp = nomi;
            double[] tempiTemp = tempi;

            // bubble sort
            for (int i = 0; i < partecipanti; i++)
            {
                for (int j = 0; j < partecipanti - 1; j++)
                {
                    if (tempiTemp[j] > tempiTemp[j + 1])
                    {
                        double temp1 = tempiTemp[j];
                        tempiTemp[j] = tempiTemp[j + 1];
                        tempiTemp[j + 1] = temp1;

                        string temp2 = nomiTemp[j];
                        nomiTemp[j] = nomiTemp[j + 1];
                        nomiTemp[j + 1] = temp2;
                    }
                }
            }

            Stampa(nomiTemp, tempiTemp);
        }

        private static void Stampa(string[] nomi, double[] tempi)
        {
            for (int i = 0; i < partecipanti; i++)
            {
                Console.WriteLine($"Partecipante: {nomi[i]}, tempo: {tempi[i]}");
            }
        }
    }
}
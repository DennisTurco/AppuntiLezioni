namespace MagazzinoAbbigliamento
{
    public partial class Form1 : Form
    {
        private List<Articolo> Magazzino = new List<Articolo>();

        public Form1()
        {
            InitializeComponent();

            comboBoxTipo.Items.Add("Giacca");
            comboBoxTipo.Items.Add("Gonna");
            comboBoxTipo.Items.Add("Camicetta");
            comboBoxTaglia.Items.Add("42");
            comboBoxTaglia.Items.Add("44");
            comboBoxTaglia.Items.Add("46");
            comboBoxTaglia.Items.Add("48");
        }

        private void labelTaglia_Click(object sender, EventArgs e)
        {

        }

        private void buttonInserisci_Click(object sender, EventArgs e)
        {
            var tipo = comboBoxTipo.SelectedItem;
            var taglia = comboBoxTaglia.SelectedItem;
            if ((tipo == null || tipo.ToString() == "") && (taglia == null || taglia.ToString() == ""))
            {
                MessageBox.Show("Nessuna tipo/taglia è stato specificato!!!");
                return;
            }
            else if (tipo == null || tipo.ToString() == "")
            {
                MessageBox.Show("Impossibile Aggiungere: tipo mancante");
                return;
            }
            else if (taglia == null || taglia.ToString() == "")
            {
                MessageBox.Show("Impossibile Aggiungere: taglia mancante");
                return;
            }

            Articolo nuovoArticolo = new Articolo(tipo.ToString(), int.Parse(taglia.ToString()));
            Magazzino.Add(nuovoArticolo);
        }

        private void comboBoxTipo_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void comboBoxTaglia_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void buttonCancella_Click(object sender, EventArgs e)
        {
            comboBoxTipo.ResetText();
            comboBoxTaglia.ResetText();

        }

        private void buttonCerca_Click(object sender, EventArgs e)
        {
            textBoxElenco.Text = "";
            if (Magazzino.Count == 0)
            {
                MessageBox.Show("Nessun articolo corrispondente è in magazzino!!!");
                return;
            }

            foreach (var item in Magazzino)
            {
                textBoxElenco.Text += item.GetStampa();
                textBoxElenco.Text += Environment.NewLine;
            }
        }
    }

    public class Articolo
    {
        public string Tipo { get; }
        public int Taglia { get; }

        public Articolo(string tipo, int taglia)
        {
            Tipo = tipo;
            Taglia = taglia;
        }

        public string GetStampa()
        {
            return $"{Tipo} {Taglia}";
        }
    }
}

namespace Bar
{
    public partial class Form1 : Form
    {
        private List<Ordine> ordinazioni = new List<Ordine>();

        public Form1()
        {
            InitializeComponent();

            PopolamentoNomiClienti();
            buttonOrdina.Enabled = false;
            button1.Enabled = false;
        }

        private void PopolamentoNomiClienti()
        {
            comboBox1.Items.Clear();
            comboBox1.Items.Add("Marco");
            comboBox1.Items.Add("Massimiliano");
        }

        private void buttonOrdina_Click(object sender, EventArgs e)
        {
            string bevanda;
            if (radioButtonCaffe.Checked)
            {
                bevanda = "caffe";
            }
            else if (radioButtonCappuccino.Checked)
            {
                bevanda = "cappuccino";
            }
            else
            {
                bevanda = "aranciata";
            }

            Ordine ordine = new Ordine(CalcolaId(), comboBox1.Text, bevanda);
            ordinazioni.Add(ordine);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int idCliente = OttieniClienteIdDalNome();
            var ordini = ListaOrdiniDelCliente(idCliente);
            var totale = CalcolaConto(idCliente);

            textBox1.Text = $"---- Scontrino fiscale di: {comboBox1.Text} ----";
            textBox1.Text += Environment.NewLine;
            foreach (var o in ordini)
            {
                textBox1.Text += $"{o.Bevanda} {o.Prezzo}€";
                textBox1.Text += Environment.NewLine;
            }
            textBox1.Text += "--------------------";
            textBox1.Text += Environment.NewLine;
            textBox1.Text += $"Totale: {totale}€";
        }

        private int CalcolaConto(int cliente)
        {
            var ordini = ListaOrdiniDelCliente(cliente);

            int totale = 0;
            foreach (var o in ordini)
            {
                totale += o.Prezzo;
            }

            return totale;
        }

        private List<Ordine> ListaOrdiniDelCliente(int clienteId)
        {
            List<Ordine> ordini = new List<Ordine>();

            foreach (var o in ordinazioni)
            {
                if (o.IdCliente == clienteId)
                {
                    ordini.Add(o);
                }
            }

            return ordini;
        }

        private int OttieniClienteIdDalNome()
        {
            foreach (var o in ordinazioni)
            {
                if (comboBox1.Text.Equals(o.NomeCliente))
                {
                    return o.IdCliente;
                }
            }
            return -1;
        }

        private void radioButtonAranciata_CheckedChanged(object sender, EventArgs e)
        {
            AttivaPulsanti();
        }

        private void radioButtonCappuccino_CheckedChanged(object sender, EventArgs e)
        {
            AttivaPulsanti();
        }

        private void radioButtonCaffe_CheckedChanged(object sender, EventArgs e)
        {
            AttivaPulsanti();
        }

        private void AttivaPulsanti()
        {
            buttonOrdina.Enabled = true;
            button1.Enabled = true;
        }

        private int CalcolaId()
        {
            int id = OttieniClienteIdDalNome();
            if (id != -1)
            {
                return id;
            }

            int max = -1;
            foreach(var o in ordinazioni)
            {
                if (o.IdCliente > max)
                {
                    max = o.IdCliente;
                }
            }
            max++;
            return max;
        }
    }


    public class Ordine
    {
        public int IdCliente { get; }
        public string NomeCliente { get; }
        public string Bevanda { get; }
        public int Prezzo { get; }

        public Ordine(int id, string nomeCliente, string bevanda)
        {
            IdCliente = id;
            NomeCliente = nomeCliente;
            Bevanda = bevanda;

            if (bevanda.Equals("caffe"))
            {
                Prezzo = 1;
            }
            else if (bevanda.Equals("cappuccino"))
            {
                Prezzo = 2;
            }
            else
            {
                Prezzo = 3;
            }
        }
    }
}
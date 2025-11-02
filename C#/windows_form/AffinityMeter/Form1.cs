namespace AffinityMeter
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            InsertAges();
            InsertStudies();
        }

        private void InsertAges()
        {
            comboBoxLuiAge.Items.Clear();
            comboBoxLeiAge.Items.Clear();

            for (int i = 15; i <= 25; i++)
            {
                comboBoxLuiAge.Items.Add(i.ToString());
                comboBoxLeiAge.Items.Add(i.ToString());
            }
        }

        private void InsertStudies()
        {
            string[] strings = { "Media", "Diploma", "Laurea" };

            foreach (string s in strings)
            {
                listBoxLuiStudy.Items.Add(s);
                listBoxLeiStudy.Items.Add(s);
            }
        }

        private void comboBoxLuiAge_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void listBoxLuiStudy_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void buttonCalculateAffinity_Click(object sender, EventArgs e)
        {
            if (comboBoxLuiAge.Text == "" || comboBoxLeiAge.Text == "")
            {
                MessageBox.Show("Inserisci Età!", "Errore", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            int score = CalculateScoreByAge() + CalculateScoreByStudy() + CalculateScoreByInterests();            

            label1.Text = $"{score}%";
            progressBar.Value = score;
        }

        private int CalculateScoreByAge()
        {
            int luiAge = int.Parse(comboBoxLuiAge.Text);
            int leiAge = int.Parse(comboBoxLeiAge.Text);
            if (Math.Abs(luiAge - leiAge) < 5)
            {
                return 30;
            }
            return 0;
        }

        private int CalculateScoreByStudy()
        {
            if (listBoxLuiStudy.Text == "" && listBoxLeiStudy.Text == "")
            {
                MessageBox.Show("Non è stato selezionato il titolo di studio", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }

            if (listBoxLuiStudy.Text == listBoxLeiStudy.Text)
            {
                return 20;
            }
            return 0;
        }

        private int CalculateScoreByInterests()
        {
            int score = 0;
            if (checkBoxLuiSport.Checked == checkBoxLeiSport.Checked)
            {
                score += 25;
            }
            if (checkBoxLuiViaggi.Checked == checkBoxLeiViaggi.Checked)
            {
                score += 25;
            }
            return score;
        }
    }
}

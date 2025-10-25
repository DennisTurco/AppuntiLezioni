namespace Sveglia
{
    public partial class Form1 : Form
    {
        private TimeSpan time;

        public Form1()
        {
            InitializeComponent();

            timer.Enabled = false; // il timer deve essere fermo di default
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            TimeSpan timeElapsed = new TimeSpan(0, 0, 1);
            time -= timeElapsed;

            labelTimerOre.Text = time.Hours.ToString();
            labelTimerMinuti.Text = time.Minutes.ToString();
            labelTimerSecondi.Text = time.Seconds.ToString();

            if (time.TotalMilliseconds < 1000) // ==== labelTimerOre.Text == "0" && labelTimerMinuti.Text == "0" && labelTimerSecondi.Text == "0"
            {
                timer.Enabled = false;
                MessageBox.Show("Timer Concluso!!", "Timer", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            if (textBoxOre.Text == "" || textBoxMinuti.Text == "" || textBoxSecondi.Text == "")
            {
                MessageBox.Show("Campi mancanti, è necessario inserire ore, minuti e secondi per far partire il timer!", "Errore", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            int ore = int.Parse(textBoxOre.Text);
            int minuti = int.Parse(textBoxMinuti.Text);
            int secondi = int.Parse(textBoxSecondi.Text);

            time = new TimeSpan(ore, minuti, secondi);
            timer.Enabled = true;
        }
    }
}

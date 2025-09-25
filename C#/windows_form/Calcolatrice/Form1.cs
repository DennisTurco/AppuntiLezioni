namespace Calcolatrice
{
    public partial class Form1 : Form
    {
        private float left;
        private char op;
        private float right;

        public Form1()
        {
            InitializeComponent();
        }

        private void button0_Click(object sender, EventArgs e)
        {
            textBoxRisultato.Text += button0.Text;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBoxRisultato.Text += button1.Text;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBoxRisultato.Text += button2.Text;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBoxRisultato.Text += button3.Text;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            textBoxRisultato.Text += button4.Text;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBoxRisultato.Text += button5.Text;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            textBoxRisultato.Text += button6.Text;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            textBoxRisultato.Text += button7.Text;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            textBoxRisultato.Text += button8.Text;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            textBoxRisultato.Text += button9.Text;
        }

        private void buttonPlus_Click(object sender, EventArgs e)
        {
            left = float.Parse(textBoxRisultato.Text);
            op = '+';
            textBoxRisultato.Text += buttonPlus.Text;
        }

        private void buttonDiff_Click(object sender, EventArgs e)
        {
            left = float.Parse(textBoxRisultato.Text);
            op = '-';
            textBoxRisultato.Text += buttonPlus.Text;
        }

        private void buttonProd_Click(object sender, EventArgs e)
        {
            left = float.Parse(textBoxRisultato.Text);
            op = 'x';
            textBoxRisultato.Text += buttonPlus.Text;
        }

        private void buttonFract_Click(object sender, EventArgs e)
        {
            left = float.Parse(textBoxRisultato.Text);
            op = '/';
            textBoxRisultato.Text += buttonPlus.Text;
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            textBoxRisultato.Text = "";
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            if (textBoxRisultato.Text.Length > 0)
            {
                textBoxRisultato.Text = textBoxRisultato.Text.Substring(0, textBoxRisultato.Text.Length - 1);
            }
        }

        private void textBoxRisultato_TextChanged(object sender, EventArgs e)
        {

        }

        private void buttonEquals_Click(object sender, EventArgs e)
        {
            InputManagement input = new InputManagement();
            right = float.Parse(input.getRightValueFromOperation(textBoxRisultato.Text));
            float res = 0;
            switch (op)
            {
                case '+':
                    res = left + right;
                    break;
                case '-':
                    res = left - right;
                    break;
                case 'x':
                    res = left * right;
                    break;
                case '/':
                    res = left / right;
                    break;
            }

            textBoxRisultato.Text = res.ToString();
        }
    }
}

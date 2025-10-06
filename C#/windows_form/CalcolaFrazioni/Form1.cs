namespace CalcolaFrazioni
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void CalcolaBtn_Click(object sender, EventArgs e)
        {
            errorMessage.Text = "";

            int num1 = int.Parse(NumExp1TextBox.Text);
            int den1 = int.Parse(DenExp1TextBox.Text);
            int num2 = int.Parse(NumExp2TextBox.Text);
            int den2 = int.Parse(DenExp2TextBox.Text);
            char op = char.Parse(OpTextBox.Text);

            if (den1 == 0 || den2 == 0)
            {
                errorMessage.Text = "Impossibile inserire denominatore nullo!";
                return;
            }

            switch (op)
            {
                case '+':
                    NumeratorSum(num1, den1, num2, den2, op);
                    break;
                case '-':
                    NumeratorSum(num1, den1, num2, den2, op);
                    break;
                case '*':
                    NumResTextBox.Text = (num1 * num2).ToString();
                    DenResTextBox.Text = (den1 * den2).ToString();
                    break;
                case '/':
                    NumResTextBox.Text = (num1 * den2).ToString();
                    DenResTextBox.Text = (den1 * num2).ToString();
                    break;
                default:
                    errorMessage.Text = "Operando non valido!";
                    break;
            }
        }

        private void SemplificaBtn_Click(object sender, EventArgs e)
        {
            int num = int.Parse(NumResTextBox.Text);
            int den = int.Parse(DenResTextBox.Text);
            
            // caso non primi
            while (num % 2 == 0 && den % 2 == 0)
            {
                num = num / 2;
                den = den / 2;
            }
            while (num % 3 == 0 && den % 3 == 0)
            {
                num = num / 3;
                den = den / 3;
            }
            while (num % 5 == 0 && den % 5 == 0)
            {
                num = num / 5;
                den = den / 5;
            }
            while (num % 7 == 0 && den % 7 == 0)
            {
                num = num / 7;
                den = den / 7;
            }

            // caso uno dei due primi
            // ...

            NumResTextBox.Text = num.ToString();
            DenResTextBox.Text = den.ToString();
        }

        private void NumeratorSum(int num1, int den1, int num2, int den2, char op)
        {
            Calculate calculate = new Calculate();
            int denRes = calculate.CommonDenominator(den1, den2);
            int numRes;
            if (op == '+')
            {
                numRes = (denRes / den1 * num1) + (denRes / den2 * num2);
            }
            else
            {
                numRes = (denRes / den1 * num1) - (denRes / den2 * num2);
            }
            NumResTextBox.Text = numRes.ToString();
            DenResTextBox.Text = denRes.ToString();
        }
    }
}

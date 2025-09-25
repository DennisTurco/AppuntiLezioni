namespace Calcolatrice
{
    public class InputManagement
    {
        public string getRightValueFromOperation(string operation)
        {
            string value = "";
            for (int i = operation.Length-1; i >= 0; i--)
            {
                if (!isOperation(operation[i]))
                {
                    value += operation[i];
                }
                else
                {
                    break;
                }
            }

            return getReversedString(value);
        }

        private bool isOperation(char symbol)
        {
            return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
        }

        private string getReversedString(string phrase)
        {
            string result = "";
            for (int i = phrase.Length-1; i >= 0; i--)
            {
                result += phrase[i];
            }
            return result;
        }
    }
}

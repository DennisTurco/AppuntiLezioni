namespace CalcolaFrazioni
{
    public class Calculate
    { 
        public int CommonDenominator(int den1, int den2)
        {
            int denRes;
            if (den1 % den2 == 0)
            {
                denRes = den1;
            }
            else if (den2 % den1 == 0)
            {
                denRes = den2;
            }
            else
            {
                denRes = den1 * den2;
            }
            return denRes;
        }
    }
}

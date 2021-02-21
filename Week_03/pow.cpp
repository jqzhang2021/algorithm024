class Solution {
public:
    double pow(double x, long long n)
    {
        if(n == 0)
        {
            return 1;
        }
        double temp = x;
        double result = 1.0;
        while(n > 0)
        {
            if((n % 2) == 1)
            {
                result *= temp;
            }
            temp *= temp;
            n = n / 2;
        }
        return result;
    }
    double myPow(double x, int n) 
    {
        long long temp = n;
        if(n >= 0)
        {
            return pow(x, temp);
        }
        return 1.0 / pow(x, -temp);
    }
};

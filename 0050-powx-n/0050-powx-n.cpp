class Solution
{
public:
    double myPow(double x, int n)
    {

        // 1ST APPROACH (TIME COMPLEXITY IS O(N))
        // if(n<0){
        //     n=abs(n);
        //     x=1.0/x;

        // }
        // if(n==0){
        //    return 1.0;
        // }
        // if(n<0){
        //     x=1/x;
        // }

        // double half_power=myPow(x,n/2);

        // double ans;
        // if(n%2==0){
        //    ans= half_power*half_power;
        // }

        //   if(n%2!=0){
        //    ans= x*half_power*half_power;
        // }
        // return ans;

        // 2ND APPROACH (TIME COMPLEXITY : O(log(n)))
        // Nice approach
        if (n == 0)
            return 1;

        long long exp=n;
        if (n < 0)
        {
            exp = -exp;
            x = 1.0 / x;
        }

        double temp = myPow(x, exp / 2);
        if (exp % 2 == 1)
        {
            return temp * temp * x;
        }
            return temp * temp;
    }
};
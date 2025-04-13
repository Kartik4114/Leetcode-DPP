class Solution {
public:
    const int mod=1e9+7;
    int findPower(long long x,long long power){
        if(power==0) return 1;

        long long halfPower=findPower(x,power/2);
        long long result=(halfPower*halfPower)%mod;

        if(power&1){
            return (x*result)%mod;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        return (long long) findPower(5,(n+1)/2)*findPower(4,n/2) %mod;
    }
};
class Solution {
public:
    int mod = 1e9+7;

    long long modPow(long long x, long long power) {
        if (power == 0) return 1;

        long long halfPower = modPow(x, power / 2);
        halfPower = (halfPower * halfPower) % mod;

        if (power % 2 == 1) {
            return (halfPower * x) % mod;
        }
        return halfPower;
    }

    int countGoodNumbers(long long n) {
        long long pairs = n / 2;
        long long ans = modPow(20, pairs);

        if (n % 2 == 1) {
            ans = (ans * 5) % mod;
        }
        return ans;
    }
};

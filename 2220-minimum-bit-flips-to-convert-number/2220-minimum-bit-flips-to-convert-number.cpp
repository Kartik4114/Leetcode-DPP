class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult=start^goal;

        int ans=__builtin_popcount(xorResult);
        return ans;
    }
};
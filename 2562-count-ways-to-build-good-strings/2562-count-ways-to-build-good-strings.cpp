class Solution {
public:
    int MOD=1e9+7;
    
    vector<int> memo;
    int solve(int length,int low,int high,int zero,int one){

        if(length>high) return 0;

        int ans=0;
        if(length>=low && length<=high) ans=1;

        if(memo[length]!=-1) return memo[length];

        int appendZero= solve(length+zero,low,high,zero,one);
        int appendOne= solve(length+one,low,high,zero,one);

        return memo[length]=(ans+appendZero+appendOne)%MOD;

    }
    int countGoodStrings(int low, int high, int zero, int one) {
        
        memo.resize(high+1,-1);
        return solve(0,low,high,zero,one);
    }
};
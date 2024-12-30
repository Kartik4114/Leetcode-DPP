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
    int a2(int low, int high, int zero, int one){

        vector<int> t(high+1,0);
        t[0]=1; // "" empty string

        for(int i=1;i<=high;i++){

            if(i-zero>=0){
                t[i]= (t[i]+t[i-zero]) %MOD;
            }

            if(i-one>=0){
                t[i]= (t[i]%MOD+t[i-one]) %MOD;
            }
        }

        int ans=0;

        for(int l=low;l<=high;l++){
            ans=(ans%MOD+t[l])%MOD;
        }
        return ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        
        // APPROACH 1:- USING RECURSION + MEMOIZATION
        // memo.resize(high+1,-1);
        // return solve(0,low,high,zero,one);

        // APPROACH 2:- USING DP
        return a2(low,high,zero,one);
    }
};
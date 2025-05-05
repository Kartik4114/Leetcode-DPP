class Solution {
public:
    int MOD=1e9+7;

    int t[1001];
    long long solve(int n){

        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;

        if(t[n]!=-1) return t[n];

        long long ans=((2*solve(n-1)%MOD)+solve(n-3))%MOD;
        return t[n]=ans;

    }

    int a1(int n){

        memset(t,-1,sizeof(t));
        return solve(n);
    }

    int a2(int n){

        vector<int> dp(n+1);

        if(n==1) return 1;
        if(n==2) return 2;

        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;

        for(int i=4;i<=n;i++){

            dp[i]=((2*dp[i-1])%MOD+dp[i-3])%MOD;
        }

        return dp[n];
    }
    int numTilings(int n) {
        
        // APPROACH 1:- USING RECURSION + MEMOIZATION
        // return a1(n);
        // APPROACH 2:- USING DP
        return a2(n);

    }
};
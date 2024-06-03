class Solution {
public:
    int memo[46];
    int a1(int n){
        
        if(n<=2) return n;

        if(memo[n]!=-1) return memo[n];

        int ans=0;
        ans+=a1(n-1);
        ans+=a1(n-2);

        return memo[n]=ans;
    }

    int a2(int n){
        
        if(n<=2) return n;
        vector<int> dp(n+1);
        
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;

        for(int i=3;i<n+1;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];

    }
    int climbStairs(int n) {
        
        // APPROACH 1 :- USING RECURSION + MEMOIZATION
        // memset(memo,-1,sizeof(memo));
        // return a1(n);

        // APPROACH 2 :- USING DYNAMIC PROGRAMMING
        return a2(n);
    }
};
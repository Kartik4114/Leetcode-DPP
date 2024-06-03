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
    int climbStairs(int n) {
        
        // APPROACH 1 :- USING RECURSION + MEMOIZATION
        memset(memo,-1,sizeof(memo));
        return a1(n);
    }
};
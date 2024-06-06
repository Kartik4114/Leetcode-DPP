class Solution {
public:
    int memo[46];
    int solve(int n){

        if(n<=2) return n;

        if(memo[n]!=-1) return memo[n];

        int a=solve(n-1);
        int b=solve(n-2);

        return memo[n]=a+b;

    }
    int climbStairs(int n) {   
        
        memset(memo,-1,sizeof(memo));
        return solve(n);

    }
};
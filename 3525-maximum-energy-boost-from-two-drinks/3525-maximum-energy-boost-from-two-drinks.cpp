class Solution {
public:
    long long solve(vector<int> &a, vector<int> &b, int curr, int i, vector<vector<long long>> &dp) {
        int n = a.size();
        
        if (i >= n) return 0;
        
        if (dp[curr][i] != -1) return dp[curr][i];
        
        long long take = 0;
        if (curr == 0) {
            take = a[i] + solve(a, b, 0, i + 1, dp);
        } else {
            take = b[i] + solve(a, b, 1, i + 1, dp);
        }
        
        long long skip = solve(a, b, 1 - curr, i + 1, dp);
        
        return dp[curr][i] = max(take, skip);
    }

    long long a1(vector<int> &a,vector<int> &b){
         int n = a.size();
        vector<vector<long long>> dp(2, vector<long long>(n, -1)); // 2D memoization array
        
        long long ans1 = solve(a, b, 0, 0, dp);
        long long ans2 = solve(a, b, 1, 0, dp);
        
        return max(ans1, ans2);
    }

    long long a2(vector<int> &a,vector<int> &b){

        int n=a.size();
        vector<vector<long long>> dp(n+1,vector<long long> (2,0));

        for(int i=1;i<=n;i++){
            // take energy A
            dp[i][0]=dp[i-1][0]+(long long)a[i-1];
            // not take energy A
            dp[i][0]=max(dp[i][0],dp[i-1][1]);
            // take energy B
            dp[i][1]=dp[i-1][1]+ (long long)b[i-1];
            //  not take energy A
            dp[i][1]=max(dp[i][1],dp[i-1][0]);
        }
        return max(dp[n][0],dp[n][1]);

    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
       
        // APPROACH 1:- USING RECURSION + MEMOIZATION
        // return a1(energyDrinkA,energyDrinkB);

        // APPROACH 2:- USING DYNAMIC PROGRAMMING
        return a2(energyDrinkA,energyDrinkB);
    }
};

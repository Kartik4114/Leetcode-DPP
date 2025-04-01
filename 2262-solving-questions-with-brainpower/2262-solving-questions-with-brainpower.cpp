class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n=questions.size();

        vector<long long> dp(n,0);
        dp[n-1]=questions[n-1][0];

        // cout<<dp[n-1]<<endl;
        long long maxVal=dp[n-1];
        for(int i=n-2;i>=0;i--){
            
            int skip=questions[i][1];
            if(skip+i+1<n){
                dp[i]=max(questions[i][0]+dp[i+1+skip],maxVal);
            } else {
                dp[i]=max(maxVal,(long long)questions[i][0]);
            }

            // cout<<dp[i]<<" ";
            maxVal=max(maxVal,dp[i]);
        }

        return maxVal;
    }
};
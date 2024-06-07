class Solution {
public:
    int memo[1001][1001];
    int a1(vector<vector<int>>& pairs,int idx,int prev_idx){
        int n=pairs.size();
        if(idx>=n) return 0;

        if(prev_idx!=-1 && memo[idx][prev_idx]!=-1) return memo[idx][prev_idx];

        int skip=a1(pairs,idx+1,prev_idx);

        int take=0;
        if(prev_idx==-1 || pairs[idx][0]>pairs[prev_idx][1]){
            take=1+a1(pairs,idx+1,idx);
        }

        if(prev_idx==-1) return max(skip,take);
        return memo[idx][prev_idx]=max(skip,take);
    }

    int a2(vector<vector<int>>& pairs){
        int n=pairs.size();

        if(n==1) return 1;

        vector<int> dp(n+1,1);
        int maxLIS=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],dp[j]+1);
                    maxLIS=max(maxLIS,dp[i]);
                }
            }
        }

        return maxLIS;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        
        // APPROACH 1 :- USING RECURSION + MEMOIZATION 
        sort(pairs.begin(),pairs.end());
        memset(memo,-1,sizeof(memo));
        // return a1(pairs,0,-1);

        // APPROACH 2:- USING DYNAMIC PROGRAMMING
        return a2(pairs);
    }
};
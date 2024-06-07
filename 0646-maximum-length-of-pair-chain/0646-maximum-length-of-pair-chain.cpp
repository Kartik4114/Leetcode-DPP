class Solution {
public:
    int memo[1001][1001];

    int solve(vector<vector<int>>& pairs,int idx,int prev_idx){
        int n=pairs.size();
        if(idx>=n) return 0;

        if(prev_idx!=-1 && memo[idx][prev_idx]!=-1) return memo[idx][prev_idx];

        int skip=solve(pairs,idx+1,prev_idx);

        int take=0;
        if(prev_idx==-1 || pairs[idx][0]>pairs[prev_idx][1]){
            take=1+solve(pairs,idx+1,idx);
        }

        if(prev_idx==-1) return max(skip,take);
        return memo[idx][prev_idx]=max(skip,take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end());
        memset(memo,-1,sizeof(memo));
        return solve(pairs,0,-1);
    }
};
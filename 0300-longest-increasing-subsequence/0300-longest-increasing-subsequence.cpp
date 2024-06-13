class Solution {
public:
    int memo[2501][2501];
    int solve(vector<int> &nums,int idx ,int prev_idx){
        
        int n=nums.size();
        if(idx>=n){
            return 0;
        }

        if( prev_idx!=-1 && memo[idx][prev_idx]!=-1) return memo[idx][prev_idx];

        int skip=solve(nums,idx+1,prev_idx);

        int take=0;
        if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
            take =1+solve(nums,idx+1,idx);
        }

        if(prev_idx!=-1)
        return memo[idx][prev_idx]=max(skip,take);

        return max(skip,take);

    }
    int lengthOfLIS(vector<int>& nums) {
        
        memset(memo,-1,sizeof(memo));
        return solve(nums,0,-1);
    }
};
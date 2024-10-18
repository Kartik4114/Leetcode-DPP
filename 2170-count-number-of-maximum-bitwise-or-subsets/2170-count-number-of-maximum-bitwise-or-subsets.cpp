class Solution {
public:
    int countSubsets(vector<int> &nums,int currOr,int maxOr,int idx,vector<vector<int>> &dp){
        
        int n=nums.size();
        if(idx>=n){
            if(currOr==maxOr) return 1;
            return 0; // else
        }

        if(dp[idx][currOr]!=-1) return dp[idx][currOr];
        // Take
        int takeCount = countSubsets(nums,currOr | nums[idx],maxOr , idx+1,dp);

        // Skip
        int notTakeCount = countSubsets(nums,currOr , maxOr , idx+1,dp);

        return dp[idx][currOr] = takeCount + notTakeCount;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        
        // Here this problem has less constraint so need of as such memoization 
        // But still repeated sub problem is coming so memoizing the problem

        // T.C :- O(2^n) (Recursion)
        // After memoization 

        // T.C :- O(n*maxOr) (memoization)
        // S.C :- O(n*maxOr) // 2-d array space

        int n=nums.size();
        int maxOr=0;
        for(auto &num:nums){
            maxOr |=num;
        }

        int currOr=0;
        
        vector<vector<int>> dp(n+1,vector<int> (maxOr+1,-1));
        int count=countSubsets(nums,currOr,maxOr,0,dp);
        return count;
    }
};
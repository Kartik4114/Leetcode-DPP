class Solution {
public:
    int memo[2501][2501];
    
    int a1(vector<int> &nums, int idx, int prev_idx) {
        int n = nums.size();
        if (idx == n) return 0;

        if (prev_idx != -1 && memo[idx][prev_idx] != -1) 
            return memo[idx][prev_idx];

        // Skip the current element
        int skip = a1(nums, idx + 1, prev_idx);

        // Take the current element if it is larger than the previous one
        int take = 0;
        if (prev_idx == -1 || nums[idx] > nums[prev_idx]) {
            take = 1 + a1(nums, idx + 1, idx);
        }

        if (prev_idx != -1)
            memo[idx][prev_idx] = max(skip, take);

        return max(skip, take);
    }

    int a2(vector<int> &nums){
        int n=nums.size();

        vector<int> dp(n,1);
        int maxLIS=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){

                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                    maxLIS=max(maxLIS,dp[i]);
                }
            }
        }
        return maxLIS;

    }
    int lengthOfLIS(vector<int>& nums) {

        // APPROACH 1:- USING RECURSION+MEMOISATION
        // FOR RECURSION :- T.C:- O(2^N)
        // FOR MEMOIZATION T.C :- O(N^2) , S.C :- O(N^2);
        memset(memo, -1, sizeof(memo));

        // return a1(nums, 0, -1);

        // // APPROACH 2:- USING DYNAMIC PROGRAMMING
        // FOR DYNAMIC PROGRAMMING T.C :- O(N^2) , S.C :- O(N^2);

        return a2(nums);

    }
};

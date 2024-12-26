class Solution {
public:
    int solve(vector<int> &nums,int target,int idx,int sum){
        int n=nums.size();

        if(idx==n){
            return (sum==target) ? 1 : 0;
        }

        int add=solve(nums,target,idx+1,sum+nums[idx]);
        int subtract=solve(nums,target,idx+1,sum-nums[idx]);

        return add+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();

        return solve(nums,target,0,0);
    }
};
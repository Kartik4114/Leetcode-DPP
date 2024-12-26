class Solution {
public:
    int solve(vector<int> &nums,int target,int idx,int sum,unordered_map<string,int> &memo){
        int n=nums.size();

        if(idx==n){
            return sum==target ? 1 : 0;
        }
        string key = to_string(idx) + "," + to_string(sum);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        int add=solve(nums,target,idx+1,sum+nums[idx],memo);
        int subtract=solve(nums,target,idx+1,sum-nums[idx],memo);

        return memo[key]=add+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        // APPROACH 1:- Using recursion , O(2^n) (Working fine)
        // Using Memoization O(n^2)

        int n=nums.size();
        unordered_map<string,int> memo;
        return solve(nums,target,0,0,memo);
    }
};
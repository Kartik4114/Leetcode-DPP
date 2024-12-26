class Solution {
public:
    int solve1(vector<int> &nums,int target,int idx,int sum,unordered_map<string,int> &memo){
        int n=nums.size();

        if(idx==n){
            return sum==target ? 1 : 0;
        }
        string key = to_string(idx) + "," + to_string(sum);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        int add=solve1(nums,target,idx+1,sum+nums[idx],memo);
        int subtract=solve1(nums,target,idx+1,sum-nums[idx],memo);

        return memo[key]=add+subtract;
    }

    int a1(vector<int>& nums, int target){

        int n=nums.size();
        unordered_map<string,int> memo;
        return solve1(nums,target,0,0,memo);
    }
    int S;

    int solve2(vector<int> &nums,int target,int idx,int sum,vector<vector<int>> &memo){
        int n=nums.size();

        if(idx==n){
            return sum==target ? 1 : 0;
        }
        
        if(memo[idx][sum+S]!=-1) return memo[idx][sum+S];

        int add=solve2(nums,target,idx+1,sum+nums[idx],memo);
        int subtract=solve2(nums,target,idx+1,sum-nums[idx],memo);

        return memo[idx][sum+S]=add+subtract;
    }
    int a2(vector<int>& nums, int target){

        int n=nums.size();
        S=accumulate(nums.begin(),nums.end(),0);

        vector<vector<int>> memo(n+1,vector<int>(2*S+1,-1));
        return solve2(nums,target,0,0,memo);
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        // APPROACH 1:- Using recursion , O(2^n) (Working fine)
        // Using Memoization (Using unordered map as memoization)
        // T.C :- O(n^2) , S.C :- O(n^2)

        // return a1(nums,target);


        // APPROACH 2:-
        // Using Memoization (Using 2-D array as memoization)
         // T.C :- O(n^2) , S.C :- O(n^2)

        return a2(nums,target);
    }
};
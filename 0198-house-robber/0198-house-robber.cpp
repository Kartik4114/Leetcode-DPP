class Solution {
public:
    int memo[101];
    int a1(vector<int> &nums,int i){
        if(i>=nums.size()) return 0;

        if(memo[i]!=-1) return memo[i];
        
        int ans1=a1(nums,i+2)+nums[i];
        int ans2=a1(nums,i+1);

        return memo[i]=max(ans1,ans2);

    }
    int rob(vector<int>& nums) {
        
        // APPROACH 1:- USING RECURSION +MEMOIZATION
        memset(memo,-1,sizeof(memo));
        return a1(nums,0);
        
    }
};
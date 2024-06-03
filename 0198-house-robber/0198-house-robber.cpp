class Solution {
public:
    int memo[101];
    int a1(vector<int> &nums,int i){
        if(i>=nums.size()) return 0;

        if(memo[i]!=-1) return memo[i];
        
        int steal=a1(nums,i+2)+nums[i];
        int skip=a1(nums,i+1);

        return memo[i]=max(steal,skip);

    }

    int a2(vector<int> &nums){
        
        
        int n=nums.size();

        if(n==1) return nums[0];
        vector<int> dp(n+1,0);
        dp[0]=0; // it means 0 houses
        dp[1]=nums[0]; // it means 1 house is present

        for(int i=2;i<n+1;i++){
            
            int steal=dp[i-2]+nums[i-1];
            int skip=dp[i-1];

            dp[i]=max(steal,skip);

        }

        return dp[n];

    }
    int rob(vector<int>& nums) {
        
        // APPROACH 1:- USING RECURSION +MEMOIZATION
        memset(memo,-1,sizeof(memo));
        // return a1(nums,0);

        // APPROACH 2:- USING DYNAMIC PROGRAMMING 
        return a2(nums);
        
    }
};
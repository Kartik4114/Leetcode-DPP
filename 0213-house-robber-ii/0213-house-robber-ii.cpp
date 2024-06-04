class Solution {
public:
    int memo[101];
    int helper(vector<int> &nums,int i,int n){
        
        if(i>n) return 0;

        if(memo[i]!=-1) return memo[i];

        int steal=helper(nums,i+2,n)+nums[i];
        int skip=helper(nums,i+1,n);

        return memo[i]=max(steal,skip);
    }

    int a1(vector<int> &nums){
         int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        memset(memo,-1,sizeof(memo));
        int take_0th_house=helper(nums,0,n-2);

        memset(memo,-1,sizeof(memo));
        int take_1th_house=helper(nums,1,n-1);

        return max(take_0th_house,take_1th_house);
    }

    int a2(vector<int> &nums){

        int n=nums.size();
        if(n==1) return nums[0];

        vector<int> dp(n+1,0);
        dp[1]=nums[0];
        // take 0th house and skip last house

        for(int i=2;i<=n-1;i++){
            int steal=dp[i-2]+nums[i-1];
            int skip=dp[i-1];

            dp[i]=max(steal,skip);
        }

        int result1=dp[n-1];

        dp.clear();

        dp[0]=0;
        dp[1]=0; // skip 1st house

        for(int i=2;i<=n;i++){
            int steal=dp[i-2]+nums[i-1];
            int skip=dp[i-1];

            dp[i]=max(steal,skip);
        }

        int result2=dp[n];

        return max(result1,result2);

    }

    int rob(vector<int>& nums) {
    
    // APPROACH 1:- USING RECURSION + MEMOIZATION APPROACH
        // return a1(nums);
    
    // APPROACH 1:- USING DYNAMIC PROGRAMMING APPROACH
        return a2(nums);
       


        
    }
};
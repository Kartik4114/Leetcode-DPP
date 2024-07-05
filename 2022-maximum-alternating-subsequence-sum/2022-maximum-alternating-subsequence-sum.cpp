class Solution {
public:
   typedef long long ll;

     ll memo[100001][2]; 
    ll a1(vector<int> &nums,int idx,bool flag){
        int n=nums.size();
        if(idx>=n){
            return 0;
        }

        if(memo[idx][flag]!=-1) return memo[idx][flag];

        ll skip=a1(nums,idx+1,flag);

        int val=nums[idx];
        if(flag==false){
            val=-val;
        }

        ll take=a1(nums,idx+1,!flag)+val;
        return memo[idx][flag]=max(skip,take);
    }

    long long a2(vector<int> &nums){

        int n=nums.size();
        vector<vector<long long>> dp(n+1,vector<long long>(2,0));

        for(int i=1;i<n+1;i++){

            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-nums[i]);
            
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+nums[i]);
        }

        return max(dp[n][0],dp[n][1]);
    }


    long long maxAlternatingSum(vector<int>& nums) {
        
        // memset(memo,-1,sizeof(memo));
        return a2(nums);


    }
};
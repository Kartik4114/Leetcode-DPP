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

    ll a2(vector<int> &nums){
        int n=nums.size();
        vector<vector<ll>> dp(n+1,vector<ll> (2,0));

        for(int i=1;i<=n;i++){

            // Even (0 is for even)
            dp[i][0]= max(dp[i-1][1]-nums[i-1],dp[i-1][0]);

            // Odd (0 is for Odd)
            dp[i][1]= max(dp[i-1][0]+nums[i-1],dp[i-1][1]);
        }

        return max(dp[n][0],dp[n][1]);

    }
    long long maxAlternatingSum(vector<int>& nums) {
        
        // APPROACH 1: -USING RECURSION +MEMOIZATION
        // FOR RECURSION T.C :- O(2^N)
        // FOR MEMOIZATION T.C:- O(2N) OR O(N)
        // IN MEMOIZATION WE WILL TAKE 2-D ARRAY 1 FOR IDX AND 2ND FOR FLAG(TRUE OR FALSE)

        memset(memo,-1,sizeof(memo));
        // return a1(nums,0,true);

        // APPROACH 2: -USING DYNAMIC PROGRAMMING
            return a2(nums);


    }
};
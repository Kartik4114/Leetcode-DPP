class Solution {
public:
    int memo[2001][51][51];
    int mod=1e9+7;
    int solve(vector<int> &nums,int idx,int prevI,int prevD){
        int n=nums.size();
        if(idx>=n) return 1;

        if(memo[idx][prevI][prevD]!=-1) return memo[idx][prevI][prevD];
        int ans=0;

        for(int i=prevI;i<=nums[idx];i++){
            for(int j=prevD;j>=0;j--){
                
               if(i==nums[idx]-j){
                    ans=(ans+solve(nums,idx+1,i,j))%mod;
                    // ans=ans%mod;
               }
            }
        }
        return memo[idx][prevI][prevD]=ans%mod;

    }
    int countOfPairs(vector<int>& nums) {
        
        memset(memo,-1,sizeof(memo));
        return solve(nums,0,0,nums[0]);
    }
};
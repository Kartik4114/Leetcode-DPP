class Solution {
public:
    int mod=1e9+7;
    int memo[2001][51][51];
    int solve(vector<int> &nums,int idx,int prevI,int prevD){
        int n=nums.size();
        if(idx>=n) return 1;

        if(memo[idx][prevI][prevD]!=-1) return memo[idx][prevI][prevD];
        
        int ans=0;
        for(int i=prevI;i<=nums[idx];i++){

            int x1=i;
            int x2=nums[idx]-i;

            if(x1>=prevI && x2<=prevD){
                ans=(ans+solve(nums,idx+1,x1,x2))%mod;
            }
        }
        
        return memo[idx][prevI][prevD]=ans;
    }   
    int a1(vector<int> &nums){

        int n=nums.size();
        memset(memo,-1,sizeof(memo));
        return solve(nums,0,0,nums[0]);

    }
    int countOfPairs(vector<int>& nums) {
        
        // APPROACH 1:- USING RECURSION + MEMO
        return a1(nums);
    }
};
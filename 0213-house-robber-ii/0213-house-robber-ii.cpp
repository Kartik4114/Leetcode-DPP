class Solution {
public:
    int memo[101];
    int a1(vector<int> &nums,int i,int n){
        
        if(i>n) return 0;

        if(memo[i]!=-1) return memo[i];

        int steal=a1(nums,i+2,n)+nums[i];
        int skip=a1(nums,i+1,n);

        return memo[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        
        int n=nums.size();

        if(n==0) return 0;
        if(n==1) return nums[0];

        memset(memo,-1,sizeof(memo));
        int take_0th_house=a1(nums,0,n-2);

        memset(memo,-1,sizeof(memo));
        int take_1th_house=a1(nums,1,n-1);

        return max(take_0th_house,take_1th_house);
        
    }
};
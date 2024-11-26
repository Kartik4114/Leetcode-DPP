class Solution {
public:
    int kadaneMin(vector<int>& nums){
        int n=nums.size();

        int minSum=nums[0];
        int currSum=nums[0];

        for(int i=1;i<n;i++){
            currSum=min(currSum+nums[i],nums[i]);
            minSum=min(minSum,currSum);
        }

        return minSum;
    }
    int kadaneMax(vector<int>& nums){
        int n=nums.size();

        int maxSum=nums[0];
        int currSum=nums[0];

        for(int i=1;i<n;i++){
            currSum=max(currSum+nums[i],nums[i]);
            maxSum=max(maxSum,currSum);
        }

        return maxSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n=nums.size();

        int sum=0;
        for(auto &num:nums){
            sum+=num;
        }

        int minSum=kadaneMin(nums);

        int maxSum=kadaneMax(nums);

        int circularSum=sum-minSum;

        if(maxSum>0){
            return max(circularSum,maxSum);
        }

        return maxSum;
    }
};
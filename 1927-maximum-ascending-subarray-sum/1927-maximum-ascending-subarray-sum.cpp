class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> prefixSum(n,0);
        prefixSum[0]=nums[0];

        int maxSum=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                prefixSum[i]=nums[i]+prefixSum[i-1];
            } else {
                prefixSum[i]=nums[i];
            }

            maxSum=max(maxSum,prefixSum[i]);
        }

        return max(maxSum,prefixSum[0]);
    }
};
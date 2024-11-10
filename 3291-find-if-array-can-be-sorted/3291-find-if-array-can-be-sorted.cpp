class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        
        int n=nums.size();

        for(int i=0;i<n;i++){

            for(int j=0;j<n-i-1;j++){
                
                int setBit1=__builtin_popcount(nums[j]);
                int setBit2=__builtin_popcount(nums[j+1]);

                if(setBit1==setBit2 && nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]);
                }
            }
        }

        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
};
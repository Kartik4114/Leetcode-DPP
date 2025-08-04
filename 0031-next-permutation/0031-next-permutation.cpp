class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n=nums.size();

        int golaIndex=-1;
        
        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                golaIndex=i-1;
                break;
            }
        }

        if(golaIndex!=-1){

            for(int j=n-1;j>golaIndex;j--){

                if(nums[j]>nums[golaIndex]) {
                    swap(nums[j],nums[golaIndex]);
                    break;
                }
            }
        }

        reverse(nums.begin()+golaIndex+1,nums.end());

    }
};
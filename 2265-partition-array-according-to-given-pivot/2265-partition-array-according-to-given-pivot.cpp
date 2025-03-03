class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       
       int n=nums.size();
       vector<int> arr(n,pivot);

        int k=0;
        int l=n-1;
       for(int i=0;i<n;i++){

            if(pivot>nums[i]){
                arr[k]=nums[i];
                k++;
            }
            if(pivot<nums[n-i-1]){
                arr[l]=nums[n-i-1];
                l--;
            }
       }

       return arr;
    }
};
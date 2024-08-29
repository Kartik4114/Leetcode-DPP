class Solution {
public:
    long long a1(vector<int> &nums,int minK,int maxK){ 
        int n=nums.size();

        int minKPos=-1;
        int maxKPos=-1;
        int culpritIdx=-1;

        long long result=0;
        for(int i=0;i<n;i++){

            if(nums[i]<minK || nums[i]>maxK){
                culpritIdx=i;
            } 
            if(nums[i]==minK){
                minKPos=i;
            } 
            if(nums[i]==maxK) maxKPos=i;

            int smaller=min(minKPos,maxKPos);
            int temp=smaller-culpritIdx;

            result+=(temp<=0) ? 0 : temp;
        }
        return result;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        // APPROACH 1:- USING SLIDING WINDOW APPROACH

        return a1(nums,minK,maxK);

    }
};
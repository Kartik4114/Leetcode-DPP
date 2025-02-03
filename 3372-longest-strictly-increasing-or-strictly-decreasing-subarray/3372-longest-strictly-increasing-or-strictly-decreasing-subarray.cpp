class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int n=nums.size();

        int maxCnt=0;
        int cntInc=0;
        int cntDec=0;

        for(int i=0;i<n-1;i++){

            if(nums[i]<nums[i+1]){
                cntInc++;
                cntDec=0;
            } 
            else if(nums[i]>nums[i+1]){
                cntDec++;
                cntInc=0;
            } else{
                cntInc=0;
                cntDec=0;
            }
            maxCnt=max({maxCnt,cntDec,cntInc});
        }

        return maxCnt+1;
    }
};
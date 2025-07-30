class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n=nums.size();

        int maxEl=*max_element(nums.begin(),nums.end());

        int i=0;
        int maxLen=0;
        while(i<n){

            int currLen=0;
            while(i<n && nums[i]==maxEl){
                currLen++;
                i++;
            }

            maxLen=max(maxLen,currLen);
            i++;
        }

        return maxLen;
    }
};
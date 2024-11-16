class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        int n=nums.size();

        vector<int> result;

        int i=0;

        while(i<=n-k){

            bool isInc=true;
            int maxEl=nums[i];
            int j=i+1;

            while(j-i<k){

                if(nums[j-1]+1!=nums[j]){
                    isInc=false;
                    break;
                }
                maxEl=nums[j];
                j++;
            }

            if(isInc) result.push_back(maxEl);
            else result.push_back(-1);
            i++;
        }
        return result;
    }
};
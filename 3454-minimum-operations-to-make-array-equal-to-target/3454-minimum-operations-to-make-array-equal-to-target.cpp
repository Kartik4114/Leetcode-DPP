class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        
        long long result=0;
        int n=nums.size();
        int prev=0;

        for(int i=0;i<n;i++){
            int curr=nums[i]-target[i];

            if((prev<0 && curr>0) || (prev>0 && curr<0)){
                result+=abs(curr);
            }
            else if(abs(curr)-abs(prev)>0){
                result+=abs(curr-prev);
            }

            prev=curr;
        }
        return result;
    }
};
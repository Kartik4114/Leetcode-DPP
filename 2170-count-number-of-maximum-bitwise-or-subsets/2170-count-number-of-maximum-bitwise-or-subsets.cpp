class Solution {
public:
    vector<vector<int>> vec;

    void getSubset(vector<int> &nums,vector<int> &temp,int i){
        int n=nums.size();

        if(i>=n){
            vec.push_back(temp);
            return;
        }

        // take
        temp.push_back(nums[i]);
        getSubset(nums,temp,i+1);

        // skip
        temp.pop_back();
        getSubset(nums,temp,i+1);

    }
    int countMaxOrSubsets(vector<int>& nums) {
        
        vector<int> temp;
        getSubset(nums,temp,0);

        int maxPossVal=0;
        for(auto &num:nums){
            maxPossVal |=num;
        }

        int count=0;
        for(auto &v:vec){
            
            int val=0;
            for(auto &num:v){
                val |=num;
            }

            if(val==maxPossVal) count++;
        }

        return count;
    }
};
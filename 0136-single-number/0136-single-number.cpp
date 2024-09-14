class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int xorResult=0;

        for(auto &num:nums){
            xorResult^=num;
        }
        return xorResult;

    }
};
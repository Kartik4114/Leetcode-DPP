class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n=nums.size();
        auto idx=lower_bound(nums.begin(),nums.end(),target);

        // if(idx-nums.begin()!=n) return idx-nums.begin();
       return idx-nums.begin();
    }
};
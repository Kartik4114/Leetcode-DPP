class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n=nums.size();

        if(!binary_search(nums.begin(),nums.end(),target)){
            return {-1,-1};
        }

        auto startIt=lower_bound(nums.begin(),nums.end(),target);
        auto lastIt=upper_bound(nums.begin(),nums.end(),target);

        int startIdx=startIt-nums.begin();
        int lasttIdx=lastIt-nums.begin()-1;

        return {startIdx,lasttIdx};
    }
};
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        vector<int> diff(2,0);
        vector<int> same(2,0);

        for(auto num:nums){
            int currRem=num%2;
            same[currRem]=same[currRem]+1;

            diff[currRem]=max(diff[currRem],1+diff[1^currRem]);

        }
        return max({same[0],same[1],diff[0],diff[1]});
    }
};
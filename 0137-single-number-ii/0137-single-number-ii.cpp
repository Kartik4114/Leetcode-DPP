class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ones=0;
        int twos=0;

        for(auto &num:nums){

            ones=ones^num & ~twos;
            twos=twos^num & ~ones;

            cout<<ones<<" "<<twos<<endl;
        }
        return ones;
    }
};
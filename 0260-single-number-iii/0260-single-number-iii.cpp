class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        // T.C:- O(2*n) , S.C :- O(1)

        // here we are taking long long in xorResult bec. we are doing xorResult-1
        // and int can't store that.
        long long xorResult=0;
        for(auto num:nums){
            xorResult^=num;
        }
        
        // here we are finding rightmost set bit
        int rightmost_bit=(xorResult & xorResult-1) ^ xorResult;

        int bucket1=0;
        int bucket2=0;
        for(auto num:nums){
            
            if(rightmost_bit & num){
                bucket1 ^=num;
            } else {
                bucket2 ^=num;
            }
        }
        return {bucket1,bucket2};

    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // Approach 1:- using unordered map
        // Approach 2:- using sorting
        
        // Approach 3 :- BIT MANIPULATION (BEST APPROACH)
//        T.C:- O(n) , S.C:- O(1)
        
        int result=0;

        for(int k=0;k<=31;k++){
            int countOne=0;
            for(auto num:nums){
                if(num &(1<<k)) countOne++;
            }

            if(countOne%3==1) {
                result =(result | (1<<k));
            }
        }
        return result;
    }
};
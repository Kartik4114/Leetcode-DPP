class Solution {
public:
    int a3(vector<int> &nums){
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

    int a4(vector<int> &nums){
        int ones=0;
        int twos=0;

        for(auto num:nums){
            ones=(ones^num) & ~twos;
            twos=(twos^num) & ~ones;
        }

        return ones;
    }
    int singleNumber(vector<int>& nums) {

        // Approach 1:- using unordered map
        // Approach 2:- using sorting
        
        //  Time complexity :- O(nlogn) 
        // Although bit manipulation has O(32*n) but sorting is the best
        // solution bec. n= 2^32 then nlogn will be 2^32 which is not possible bec.
        //  n= 2^31-1 
        
        // Approach 3 :- BIT MANIPULATION
//        T.C:- O(32*n) , S.C:- O(1)
        
        // return a3(nums);

        // APPROACH 3:- BEST APPROACH USING BUT MANIPULATION
        // USING CONCEPT OF BUCKETS
        // T.C:- O(N) , S.C. :- O(1);

            return a4(nums);
    }
};
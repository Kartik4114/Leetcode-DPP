class Solution {
public:
    int singleNumber(vector<int>& nums) {
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
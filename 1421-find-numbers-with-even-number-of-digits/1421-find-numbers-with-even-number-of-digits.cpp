class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int n=nums.size();

        int cnt=0;

        for(auto &num:nums){

            int digCnt=floor(log10(num)+1);

            if((digCnt&1)==0){
                cnt++;
            }
        }

        return cnt;
    }
};
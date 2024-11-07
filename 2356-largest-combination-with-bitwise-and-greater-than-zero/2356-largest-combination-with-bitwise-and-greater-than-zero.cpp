class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        
        // No. of bits = floor(log(base2)n) + 1
        // so remember here we need 24 bits

        int result=0;
        for(int i=0;i<24;i++){
            
            int count=0;
            for(int &num:candidates){

                if(num&(1<<i)) count++;
            }
            result=max(result,count);
        }
        return result;
    }
};
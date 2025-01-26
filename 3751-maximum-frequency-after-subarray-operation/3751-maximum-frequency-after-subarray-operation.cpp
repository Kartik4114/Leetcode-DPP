class Solution {
public:
    int calculateMaxGain(vector<int> &nums,int value,int k){

        int maxGain=0;
        int currGain=0;

        for(auto &num:nums){

            if(num==k) currGain--;
            if(num==value) currGain++;
            if(currGain<0) currGain=0;

            maxGain=max(maxGain,currGain);
        }

        return maxGain;
    }
    int maxFrequency(vector<int>& nums, int k) {
    
    // T.C :- O(m*n) i.e (50*n) ~ O(n)
    // S.C :- O(n)
    
        map<int,int> mp;
        for(auto &num:nums){
            mp[num]++;
        }

        int maxFreq=0;
        for(auto &it:mp){

            int value=it.first;
            maxFreq=max(maxFreq,calculateMaxGain(nums,value,k));
        } 

        return maxFreq+mp[k];      
    }
};
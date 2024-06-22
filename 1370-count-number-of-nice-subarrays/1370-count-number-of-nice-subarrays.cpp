class Solution {
public:
    int a1(vector<int> &nums,int k){
        unordered_map<int,int> mp;

        int result=0;
        int oddCount=0;
        mp[oddCount]++;
        
        for(auto num:nums){

            if(num%2==1){
                oddCount++;
            }

            if(mp.count(oddCount-k)){
                result+=mp[oddCount-k];
            }
            mp[oddCount]++;

        }
        return result;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        // APPROACH 1:- 
        return a1(nums,k);
    }
};
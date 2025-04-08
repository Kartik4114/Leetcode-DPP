class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        map<int,int> mp;
        
        for(auto &num:nums){
            mp[num]++;
        }
        
        
        int n=nums.size();
        int count=0;
        int i=0;
        for(auto &it:mp){
            
            while(it.second>1){
                
                mp[nums[i]]--;
                i++;
            }
        }
        
        if(i>0) return (i-1)/3+1;
        
        return 0;
        
    }
};
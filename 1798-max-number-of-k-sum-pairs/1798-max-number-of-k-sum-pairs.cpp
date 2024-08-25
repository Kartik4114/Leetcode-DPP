class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int n=nums.size();

        int maxOp=0;
        unordered_map<int,int> mp;
        for(auto &num:nums){
            mp[num]++;
        }

        for(int i=0;i<n;i++){
            
            int left=k-nums[i];

            if(mp[nums[i]]>0 && mp[left]>0){
                mp[nums[i]]--;
                mp[left]--;

                if(mp[nums[i]]>=0 && mp[left]>=0) maxOp++;
            }
        }

        return maxOp;
    }
};
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        // using count sort

        // T.C :- O(n+k)
        int minElement=*min_element(nums.begin(),nums.end());
        int maxElement=*max_element(nums.begin(),nums.end());

        unordered_map<int,int> mp;
        for(auto &num:nums){
            mp[num]++;
        }

        vector<int> result;
        for(int i=minElement;i<=maxElement;i++){

            while(mp[i]>0){
                result.push_back(i);
                mp[i]--;
            }
        }

        return result;
    }
};
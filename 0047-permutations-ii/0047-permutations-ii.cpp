class Solution {
public:
    unordered_map<int,int> mp;
    vector<vector<int>> result;

    void a1(vector<int> &nums,vector<int> &temp){
        int n=nums.size();
        if(temp.size()==n){
            result.push_back(temp);
            return;
        }

        for(auto &[num,count]:mp){

            if(count==0) continue;

            temp.push_back(num);
            count--;

            a1(nums,temp);
            temp.pop_back();
            count++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        // APPROACH 1:- USING UNORDERED MAP 

            vector<int> temp;
            for(auto num:nums){
                mp[num]++;
            }
            a1(nums,temp);

            return result;

    }
};
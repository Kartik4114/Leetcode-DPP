class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums,int idx,vector<int> &temp){
        int n=nums.size();
        if(idx>=n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums,idx+1,temp);
        temp.pop_back();
        solve(nums,idx+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> temp;
        solve(nums,0,temp);
        return ans;
    }
};
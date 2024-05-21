class Solution {
public:
    vector<vector<int>> ans;
    void a1(vector<int> &nums,int i,vector<int> temp){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        a1(nums,i+1,temp);
        temp.pop_back();

        a1(nums,i+1,temp);

        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // APPROACH 1:- USING RECURSION 
            vector<int> temp;
            a1(nums,0,temp);

            return ans;
    }
};
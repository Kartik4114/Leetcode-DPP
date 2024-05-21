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

    vector<vector<int>> a2(vector<int> &nums){
        // counting size of subsets
        int sub_size=pow(2,nums.size());
        vector<vector<int>> result;

        for(int i=0;i<sub_size;i++){
            vector<int> temp;

            for(int j=0;j<nums.size();j++){
                if(i & (1<<j)) temp.push_back(nums[j]);
            }
            result.push_back(temp);
        }

        return result;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // APPROACH 1:- USING RECURSION 
        // T.C :- O(2^n) , S.C:- O(2^n)
            // vector<int> temp;
            // a1(nums,0,temp);

            // return ans;
        
        // APPROACH 2:- USING BIT MANIPULATION
        // T.C :- O(n*(2^n)) , S.C:- O(n*(2^n))
            return a2(nums);
    }
};
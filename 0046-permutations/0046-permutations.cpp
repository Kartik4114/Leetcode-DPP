class Solution {
public:
    vector<vector<int>> result;
    unordered_set<int> st;

    void a1(vector<int> &nums,vector<int> &temp){
        int n=nums.size();
        if(temp.size()==n){
            result.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(st.find(nums[i])==st.end()){

                st.insert(nums[i]);
                temp.push_back(nums[i]);

                a1(nums,temp);

                st.erase(nums[i]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        // APPROACH 1:- 
        // T.C:- (n*n!) 

        vector<int> temp;
        a1(nums,temp);

        return result;
    }
};
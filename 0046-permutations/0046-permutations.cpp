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

    void a2(vector<int> &nums,int idx){
        int n=nums.size();

        if(idx==nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i=idx;i<n;i++){
            swap(nums[i],nums[idx]);
            a2(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        // APPROACH 1:- USING UNORDERED SET IN RECURSION
        // T.C:- (n*n!) 

        vector<int> temp;
        // a1(nums,temp);

        // APPROACH 2:- USING SWAPPING IN RECURSION
         a2(nums,0);

        return result;
    }
};
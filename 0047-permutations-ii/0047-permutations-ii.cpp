class Solution {
public:
    unordered_map<int,int> mp;
    vector<vector<int>> result;

    void a1(vector<int> &nums,vector<int> &temp){
        int n=nums.size();
        if(temp.size()==n){
            result.push_back(temp); // O(n)
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

    void a2(vector<int> &nums,int idx){
        int n=nums.size();
        if(idx==n){
            result.push_back(nums);
            return;
        }

        unordered_set<int> st;
        for(int i=idx;i<n;i++){
            if(st.find(nums[i])!=st.end())  continue;

            st.insert(nums[i]);
            swap(nums[i],nums[idx]);

            a2(nums,idx+1);

            swap(nums[i],nums[idx]);

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        // APPROACH 1:- USING UNORDERED MAP 
        // T.C :- O(n*n!) , S.C:- O(n) Auxillary space

            vector<int> temp;
            for(auto num:nums){
                mp[num]++;
            }
            // a1(nums,temp);
        
        // APPROACH 2 :- USING SWAPPING METHOD IN RECURSION

            a2(nums,0);
            return result;
    }
};
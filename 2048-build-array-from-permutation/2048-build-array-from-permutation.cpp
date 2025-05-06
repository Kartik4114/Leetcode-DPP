class Solution {
public:

    vector<int> a1(vector<int>& nums){

        int n=nums.size();
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            ans[i]=nums[nums[i]];
        }

        return ans;
    }

    vector<int> a2(vector<int> &nums){

        int n=nums.size();

        for(int i=0;i<n;i++){

            nums[i]=nums[i]+n*(nums[nums[i]]%n);
        }

        for(int i=0;i<n;i++){
            nums[i]=nums[i]/n;
        }

        return nums;
    }
    vector<int> buildArray(vector<int>& nums) {
        
        // Approach 1:- simple approach
        // T.C :- O(n) , S.C :- O(n)

        // return a1(nums);

        // Approach 2:- Optimised Approach (Nice Follow Up Question)
        // T.C :- O(n) , S.C :- O(1)

        return a2(nums);
    }
};
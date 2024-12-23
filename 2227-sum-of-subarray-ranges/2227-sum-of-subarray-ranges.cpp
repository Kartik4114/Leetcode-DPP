class Solution {
public:
    long long a1(vector<int> &nums){

        int n=nums.size();
        long long ans=0;

        for(int i=0;i<n;i++){

            int largest=nums[i];
            int smallest=nums[i];
            for(int j=i+1;j<n;j++){

                largest=max(nums[j],largest);
                smallest=min(nums[j],smallest);

                ans+=(largest-smallest);
            }
        }

        return ans;

    }
    long long subArrayRanges(vector<int>& nums) {
        
        // APPROACH 1:- BRUTE FORCE APPROACH 
        // T.C :- O(n^2) , S.C :- O(1)
        return a1(nums);
    }
};
class Solution {
public:
    int a1(vector<int> &nums){
        int n=nums.size();
        if(n<=4) return 0;

        sort(nums.begin(),nums.end());

        int result=INT_MAX;

        result=min(result,nums[n-4]-nums[0]);
        result=min(result,nums[n-1]-nums[3]);
        result=min(result,nums[n-2]-nums[2]);
        result=min(result,nums[n-3]-nums[1]);

        return result;

    }

    int a2(vector<int> &nums){
        
        int n=nums.size();
        if(n<=4) return 0;
        // We have to remember the syntax of partial sort and nth element
        partial_sort(nums.begin(),nums.begin()+4,nums.end()); // O(nlog(4)) =O(n)

        nth_element(nums.begin()+4,nums.begin()+n-4,nums.end()); // O(n)

        sort(nums.begin()+n-4,nums.end()); // O(4log4) ==O(1)

        int result=INT_MAX;
         result=min(result,nums[n-4]-nums[0]);
        result=min(result,nums[n-1]-nums[3]);
        result=min(result,nums[n-2]-nums[2]);
        result=min(result,nums[n-3]-nums[1]);

        return result;
    }
    int minDifference(vector<int>& nums) {
        
        // APPROACH 1:- USING SORTING
        // T.C :- O(nlogn) , S.C :- O(1)
        // return a1(nums);

        // APPROACH 2:- USING PARTIAL SORT AND NTH ELEMENT (MORE OPTIMISED APPROACH)
        // T.C :- O(n) , S.C :- O(1)
        return a2(nums);

    }
};
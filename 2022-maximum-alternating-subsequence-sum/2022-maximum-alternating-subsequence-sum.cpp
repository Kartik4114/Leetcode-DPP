class Solution {
public:
    typedef long long ll;

     ll memo[100001][2]; 
    ll a1(vector<int> &nums,int idx,bool flag){
        int n=nums.size();
        if(idx>=n){
            return 0;
        }

        if(memo[idx][flag]!=-1) return memo[idx][flag];

        ll skip=a1(nums,idx+1,flag);

        int val=nums[idx];
        if(flag==false){
            val=-val;
        }

        ll take=a1(nums,idx+1,!flag)+val;
        return memo[idx][flag]=max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        
        // APPROACH 1: -USING RECURSION +MEMOIZATION
        // FOR RECURSION T.C :- O(2^N)
        // FOR MEMOIZATION T.C:- O(2N) OR O(N)
        // IN MEMOIZATION WE WILL TAKE 2-D ARRAY 1 FOR IDX AND 2ND FOR FLAG(TRUE OR FALSE)

        memset(memo,-1,sizeof(memo));
        return a1(nums,0,true);
    }
};
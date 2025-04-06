#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:

// APPROACH 1: RECURSIVE APPROACH (TLE)
// REMEMBER HERE MEMOIZATION WON'T WORK BEC. TEMP IS CHANGIN EVERYTIME
    void solve(vector<int> &nums,int i,vector<int> &temp, vector<int> &ans ,int prev){
        if(i>=nums.size()){
            if(temp.size() > ans.size()){
                ans=temp;
            }
            return;
        }

        if(prev ==-1 || nums[i] % prev ==0){
            temp.push_back(nums[i]);
            solve(nums,i+1,temp,ans,nums[i]);
            temp.pop_back();
        }

        solve(nums,i+1,temp,ans,prev);

    }
   
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    
    // APPROACH 1:- USING RECURSION

        // vector<int> temp;
        // // unordered_map<int, int> mp;
        // vector<int> ans;
        // int prev=-1;
        // sort(nums.begin(), nums.end());
        // solve(nums, 0, temp, ans,prev);
        // return ans;

    // APPROACH :- USING DYNAMIC PROGRAMMING

    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<int> dp(n,1);

    vector<int> prev_idx(n,-1);
    int last_chosen_index=0;

        int maxL=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){

                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev_idx[i]=j;
                    }
                }

                if(dp[i] > maxL){
                    maxL=dp[i];
                    last_chosen_index=i;
                }
            }
        }

        vector<int>result;
        while(last_chosen_index!=-1){
            result.push_back(nums[last_chosen_index]);
            last_chosen_index=prev_idx[last_chosen_index];
        }
        return result;
    }
};


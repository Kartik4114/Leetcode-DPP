class Solution {
public:
    
    int result;
    void solve(vector<int> &nums,int k,int i,unordered_map<int,int> &mp){
        if(i>=nums.size()){
            result++;
            return;
        }

        // not take;
        solve(nums,k,i+1,mp);

        // take
        if(!mp[nums[i]-k] && !mp[nums[i]+k]){
            mp[nums[i]]++;
            solve(nums,k,i+1,mp);
            mp[nums[i]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
       
        result=0;
        unordered_map<int,int> mp;

        solve(nums,k,0,mp);

        // here we have to do -1 also bec. it is counting empty subset also.
        return result-1;
    }
};
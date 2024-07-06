class Solution {
public: 
    unordered_map<string,long long> mp;
    long long a1(vector<int> &nums,int idx,int prevIdx){
        int n=nums.size();
        if(idx>=n) return 0;

        string key=to_string(prevIdx)+"_" +to_string(idx);
        if(mp.find(key)!=mp.end()) return mp[key];
        long long take=0;
        if(prevIdx==-1 || nums[idx]-idx>=nums[prevIdx]-prevIdx){
            take= nums[idx]+a1(nums,idx+1,idx);
        }

        long long skip=a1(nums,idx+1,prevIdx);
        return mp[key]= max(take,skip);
    }

    long long a2(vector<int> &nums){

        int n = nums.size();

        vector<long long> t(n);
        for(int i = 0; i<n; i++) {
            t[i] = nums[i];
        }

        long long maxSum = nums[0];
        for(int i = 0; i<n; i++) {

            for(int j = 0; j<i; j++) {

                if(nums[i] - i >= nums[j] - j) {
                    t[i] = max<long long>(t[i], t[j] + nums[i]);
                    maxSum = max<long long>(maxSum, t[i]);
                }

            }
        }
        return maxSum;
    }

    long long a3(vector<int> &nums){
        long long result=INT_MIN;
        int n=nums.size();

        map<int,long long> mp;
        for(int i=0;i<n;i++){

            auto it=mp.upper_bound(nums[i]-i);

            long long sum=nums[i];
            if(it !=mp.begin()){
                it--;
                sum+=it->second;
            }

            mp[nums[i]-i]=max(sum,mp[nums[i]-i]);

            it=mp.upper_bound(nums[i]-i);
            while(it!=mp.end() && it->second<=sum){
                mp.erase(it++);
            }

            result=max(result,sum);
        }
        return result;
    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        
        // APPROACH 1:- USING RECURSION + MEMOIZATION
        // IT WILL GIVE TLE...
        int maxElement=*max_element(nums.begin(),nums.end());
        if(maxElement<=0) return maxElement;
        // return a1(nums,0,-1);

        // APPROACH 2:- USING DYNAMIC PROGRAMMING
        // IT WILL GIVE TLE...
        // return a2(nums);

        // APPROACH 3:- MOST OPTIMISED APPROACH 
        return a3(nums);


    }
};
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long n=nums.size();
        unordered_map<int,set<int>> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]-i].insert(i);
        }

        long long goodPairs=0;

        for(auto &it:mp){

            long long stSize=it.second.size();

            if(stSize>1){

                goodPairs+=((stSize)*(stSize-1))/2;
            }
        }
        // cout<<goodPairs<<endl;

        long long totalPairs=(n*(n-1))/2;

        return totalPairs-goodPairs;
    }
};
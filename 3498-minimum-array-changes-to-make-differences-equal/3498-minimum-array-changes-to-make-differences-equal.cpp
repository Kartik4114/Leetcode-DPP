class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        
        int n=nums.size();
        unordered_map<int,int> currDiffCount;
        vector<int> oneOp(k+1,0);

        for(int i=0;i<n/2;i++){
            int diff=abs(nums[i]-nums[n-i-1]);
            currDiffCount[diff]++;

            int minEl=min(nums[i],nums[n-i-1]);
            int maxEl=max(nums[i],nums[n-i-1]);

            int maxAchievableDiff=max(maxEl-0,k-minEl);
            oneOp[maxAchievableDiff]++;
        }

        // suffix sum

        for(int i=k-1;i>=0;i--){
            oneOp[i]+=oneOp[i+1];
        }

        int ans=INT_MAX;

        for(auto &it:currDiffCount){
            int diff=it.first;
            int count=it.second;

            int zeroOp=count;
            int oneOpExtra=oneOp[diff]-zeroOp;
            int twoOp=n/2-zeroOp-oneOpExtra;

            ans=min(ans,oneOpExtra+2*twoOp);
        }
        return ans;
    }
};
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n=nums.size();

        vector<int> temp(n+1,0);

        for(auto &q:queries) {

            int l=q[0];
            int r=q[1];

            temp[l]++;

            if(r<n-1) temp[r+1]--;
        }

        for(int i=1;i<temp.size();i++){

            temp[i]+=temp[i-1];
        }

        for(int i=0;i<n;i++){

            nums[i]-=temp[i];

            if(nums[i]>0) return false;
        }

        return true;
    }
};
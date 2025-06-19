class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        // 1 2 3 5 6
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int i=0;
        int j=0;
        int cnt=0;
        
        while(i<n){

            while(j<n && nums[j]-nums[i]<=k){
                j++;
            }
            i=j;
            cnt++;
        }

        return cnt;
    }
};
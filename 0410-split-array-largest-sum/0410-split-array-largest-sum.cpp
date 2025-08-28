class Solution {
public:
    int cntPartitions(vector<int> &nums,int mid){

        int n=nums.size();

        int partitions=1;
        long long subArray=0;

        for(int i=0;i<n;i++){

            if(subArray+nums[i]<=mid){
                subArray+=nums[i];
            } else {
                partitions++;
                subArray=nums[i];
            }
        }

        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int n=nums.size();

        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);

        while(low<=high){

            int mid=low+(high-low)/2;

            int partition=cntPartitions(nums,mid);

            if(partition>k) low=mid+1;
            else high=mid-1;
        }

        return low;
    }
};
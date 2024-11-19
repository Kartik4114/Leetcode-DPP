class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();

        set<int> st;
        int i=0;
        int j=0;
        long long sum=0;

        long long maxSum=0;
        while(j<n){

            while(j<n && j-i<k){

                if(st.find(nums[j])!=st.end()){
                    // st.clear();
                    // sum=0;
                    // i=j;
                    break;
                }
                st.insert(nums[j]);
                sum+=nums[j];
                j++;
            }
            if(j-i>=k) maxSum=max(maxSum,sum);
            cout<<j<<" "<<i<<" "<<sum<<" "<<maxSum<<endl;

            sum-=nums[i];
            st.erase(nums[i]);
            i++;
        }

        return maxSum;
    }
};
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());

        double ans = static_cast<double>(INT_MAX);
        for (int i = 0; i <= n / 2; i++) {
                
                double avg = (nums[i] + nums[n - i - 1]) / 2.0;
                ans = min(ans, avg);
        }
        return ans;
    }
};
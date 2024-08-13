class Solution {
public:
    int M = 1e9+7;
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(55,0));

        // dp[i][j] = number of pairs till ith index when last number is j
        // ans = sum of dp[n-1][j] where j is from 0 to 50

        // dp[0][j] = selecting till 0th index, taking last number as 0 to nums[0]
        for(int curr_num = 0; curr_num <= nums[0]; curr_num++)
            dp[0][curr_num] = 1;

        for(int ind=1; ind<n; ind++) // n
        {
            for(int curr_num = 0; curr_num <= nums[ind]; curr_num++) // 50
            {
                int ways = 0;
                for(int prev_num = 0; prev_num <= 50; prev_num++) // 50
                {
                    if(prev_num <= curr_num && (nums[ind] - curr_num <= nums[ind-1] - prev_num))
                    {
                        ways = ( ways%M + dp[ind-1][prev_num]%M ) %M;
                    }
                }
                dp[ind][curr_num] = ways;
            }
        } // n * 50 * 50
        
        int total_count_of_pairs = 0;
        for(int curr_num = 0; curr_num <= 50; curr_num++)
            total_count_of_pairs = ( total_count_of_pairs%M + dp[n-1][curr_num]%M ) %M;

        return total_count_of_pairs;
    }
    // tc - 250*2000 = 500000 = O(5*10^5)
    // sc - 2000*50 = 100000 = O(10^5)
};
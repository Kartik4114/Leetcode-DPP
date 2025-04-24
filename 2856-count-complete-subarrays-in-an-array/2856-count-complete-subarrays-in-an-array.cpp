class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int totalDistinct = st.size();

        int result = 0;
        unordered_map<int, int> mp;

        int i = 0, j = 0;

        while (i < n) {
            while (j < n && mp.size() < totalDistinct) {
                mp[nums[j]]++;
                j++;
            }

            if (mp.size() == totalDistinct) {
                result += n - j + 1;
            }

            mp[nums[i]]--;
            if (mp[nums[i]] == 0) mp.erase(nums[i]);
            i++;
        }

        return result;
    }
};

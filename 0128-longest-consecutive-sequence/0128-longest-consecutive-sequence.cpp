class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int maxLength = 0;

        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int currentNum = num;
                int currLength = 0;

                while (st.find(currentNum) != st.end()) {
                    currentNum++;
                    currLength++;
                }

                maxLength = max(maxLength, currLength);
            }
        }

        return maxLength;
    }
};

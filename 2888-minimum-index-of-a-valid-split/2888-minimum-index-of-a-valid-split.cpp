class Solution {
public:
    int findDominantEl(vector<int> &nums) {

        unordered_map<int, int> mp;
        for (auto &num : nums) {
            mp[num]++;
        }

        for (auto &it : mp) {
            if (it.second > nums.size() / 2) {
                return it.first;
            }
        }

        return -1;
    }

    int minimumIndex(vector<int> &nums) {
        int n = nums.size();

        int el = findDominantEl(nums);
        if (el == -1) return -1;

        int majElCnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el)
                majElCnt++;
        }

        int majElCurrCnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el)
                majElCurrCnt++;

            if (majElCurrCnt > (i + 1)/2 && (majElCnt - majElCurrCnt) > (n - i - 1)/2) {
                return i;
            }
        }

        return -1;
    }
};

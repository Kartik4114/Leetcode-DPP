class Solution {
public:
    vector<vector<int>> result;
    unordered_map<int,int> mp;

    void helper(vector<int> &c, vector<int> &temp, int target, int sum, int idx){
        int n = c.size();
        if (sum > target) return;

        if (sum == target) {
            result.push_back(temp);
            return;
        }

        for (int i = idx; i < n; ++i) {
            if (i > idx && c[i] == c[i - 1]) continue; // Skip duplicates

            if (mp[c[i]] > 0) {
                sum += c[i];
                mp[c[i]]--;
                temp.push_back(c[i]);

                helper(c, temp, target, sum, i); // not i+1 because we can reuse the same element

                sum -= c[i];
                mp[c[i]]++;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end()); // Sort candidates to handle duplicates
        for (auto c : candidates) {
            mp[c]++;
        }
        helper(candidates, temp, target, 0, 0);
        return result;
    }
};

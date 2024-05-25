class Solution {
public:
    // RECURSIVE APPROACH
    int dp[301];
    bool helper(string s, int i, unordered_set<string> &wordDict) {
        if (i == s.size()) return true;
        string temp;

        if (dp[i] != -1) return dp[i];

        for (int j = i; j < s.size(); j++) {
            temp += s[j];

            if (wordDict.find(temp) != wordDict.end()) {
                if (helper(s, j + 1, wordDict)) {
                   return dp[i] = 1;
                    // return true;
                }
            }
        }

        return dp[i] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;

        for (int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }

        memset(dp, -1, sizeof(dp));
        return helper(s, 0, st);
    }
};
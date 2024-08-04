class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        vector<int> temp(n + 2);

        // Filling the temp array with colors, wrapping around
        for (int i = 0; i < n + 2; i++) {
            temp[i] = colors[i % n];
        }

        int cnt = 0;
        // Correct loop range to check within the bounds of temp
        for (int i = 0; i < n; i++) {
            if (temp[i] != temp[i + 1] && temp[i + 1] != temp[i + 2]) {
                cnt++;
            }
        }
        return cnt;
    }
};

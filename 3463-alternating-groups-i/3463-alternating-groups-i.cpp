class Solution {
public:
    int a1(vector<int> &colors){
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

    int a2(vector<int> &colors){
        int n = colors.size();

        int cnt = 0;
        // Correct loop range to check within the bounds of temp
        for (int i = 0; i < n; i++) {
            if (colors[i%n] != colors[(i + 1)%n] && colors[(i + 1)%n] != colors[(i + 2)%n]) {
                cnt++;
            }
        }
        return cnt;
    }
    int numberOfAlternatingGroups(vector<int>& colors) {
        
        // approach 1:-
        // T.C :- O(n), S.C :O(n) || O(1)
        // return a1(colors);

        // approach 2:-
        // T.C :- O(n), S.C :O(1)
        return a2(colors);
    }
};

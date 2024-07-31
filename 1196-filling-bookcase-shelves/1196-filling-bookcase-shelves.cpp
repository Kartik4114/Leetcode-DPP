class Solution {
public:

    int memo[1001][1001];
    int solve(vector<vector<int>>& books, int shelfW, int i, int remainW, int currHt) {
        int n = books.size();

        if (i >= n) {
            return currHt;
        }

        if(memo[i][remainW]!=-1) return memo[i][remainW];
        int bookW = books[i][0];
        int bookH = books[i][1];

        // Place the book on the current shelf if it fits
        int keep = INT_MAX;
        if (bookW <= remainW) {
            keep = solve(books, shelfW, i + 1, remainW - bookW,max(currHt, bookH));
        }

        // Place the book on the next shelf
        int skip = currHt + solve(books, shelfW, i + 1, shelfW - bookW, bookH);

        return memo[i][remainW] = min(keep, skip);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

        memset(memo,-1,sizeof(memo));
        return solve(books, shelfWidth, 0, shelfWidth, 0);
    }
};

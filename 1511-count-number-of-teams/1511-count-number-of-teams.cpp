class Solution {
public:
    int memo[1001][1001][3][2];
    int solve(vector<int> &rating,int idx,int prev,int cnt,bool isIncr){
        
        int n=rating.size();
        if(cnt==3){
            return 1;
        }
        if(idx>=n) return 0;

        if(prev!=-1 && memo[idx][prev][cnt][isIncr]!=-1) return memo[idx][prev][cnt][isIncr];

        int result = 0;
        if (isIncr) {
            if (prev == -1 || rating[prev] < rating[idx]) {
                result += solve(rating, idx + 1, idx, cnt + 1, isIncr);
            }
        } else {
            if (prev == -1 || rating[prev] > rating[idx]) {
                result += solve(rating, idx + 1, idx, cnt + 1, isIncr);
            }
        }
        result += solve(rating, idx + 1, prev, cnt, isIncr);

        if (prev != -1) memo[idx][prev][cnt][isIncr] = result;
        return result;
    }
    int a1(vector<int>& rating) {
        
        int totalTeams=0;

        memset(memo,-1,sizeof(memo));
        totalTeams+=solve(rating,0,-1,0,true);
        totalTeams+=solve(rating,0,-1,0,false);

        return totalTeams;
    }
    int numTeams(vector<int>& rating) {
        
        // APPROACH 1:- USING RECURSION +MEMOIZATION
        return a1(rating);
    }
};
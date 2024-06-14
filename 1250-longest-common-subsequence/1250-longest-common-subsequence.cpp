class Solution {
public:
    int memo[1001][1001];
    int a1(string &text1,string &text2,int i,int j){
        int m=text1.size();
        int n=text2.size();

        if(i>=m || j>=n) return 0;
        if(memo[i][j]!=-1) return memo[i][j];

        // int take=0;
        // int skip=0;
        if(text1[i]==text2[j]){
            return memo[i][j]= 1+a1(text1,text2,i+1,j+1);
        } 
            return memo[i][j]=max(a1(text1,text2,i,j+1),a1(text1,text2,i+1,j));
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        // APPROACH 1:- USING RECURSION +MEMOIZATION
        memset(memo,-1,sizeof(memo));
        return a1(text1,text2,0,0);

        // approach 2:- using S

    }
};
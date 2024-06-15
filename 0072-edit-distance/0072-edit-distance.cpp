class Solution {
public:
    int memo[501][501];
    int a1(string word1,string word2,int i,int j){
        int m=word1.size();
        int n=word2.size();

        if(i>=m) return n-j;
        if(j>=n) return m-i;

        if(memo[i][j]!=-1) return memo[i][j];

        if(word1[i]==word2[j]) return memo[i][j]= a1(word1,word2,i+1,j+1);

        else {
            int insertC=a1(word1,word2,i,j+1);
            int deleteC = a1(word1,word2,i+1,j);
            int replaceC =a1(word1,word2,i+1,j+1);

            return memo[i][j]=1+min({insertC,deleteC,replaceC});
        }

    }

    int a2(string word1,string word2,int m,int n){
        if(m==0 || n==0) return m+n;

        if(memo[m][n]!=-1) return memo[m][n];

        if(word1[m-1]==word2[n-1]) return memo[m][n]= a2(word1,word2,m-1,n-1);

        else {
            int insertC=a2(word1,word2,m,n-1);
            int deleteC = a2(word1,word2,m-1,n);
            int replaceC =a2(word1,word2,m-1,n-1);

            return memo[m][n]=1+min({insertC,deleteC,replaceC});
        }

    }

    int a3(string s1,string s2){
        int m=s1.size();
        int n=s2.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0) dp[i][j]=i+j;

                else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else {
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        memset(memo,-1,sizeof(memo));

        // APPROACH 1:- RECURSION + MEMOIZATION (1ST)
        // return a1(word1,word2,0,0);

        // APPROACH 2:- RECURSION + MEMOIZATION (2ND)
        // return a2(word1,word2,m,n);

        // APPROACH 3:- USING DYNAMIC PROGRAMMING
        return a3(word1,word2);
    }
};
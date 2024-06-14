class Solution {
public:
    int memo[1001][1001];
    int a1(string &text1,string &text2,int i,int j){
        int m=text1.size();
        int n=text2.size();

        if(i>=m || j>=n) return 0;
        if(memo[i][j]!=-1) return memo[i][j];

        int take=0;
        // int skip=0;
        if(text1[i]==text2[j]){
            take= 1+a1(text1,text2,i+1,j+1);
        } 
            int skip=max(a1(text1,text2,i,j+1),a1(text1,text2,i+1,j));
        
        return memo[i][j]=max(take,skip);

    }

    int a2(string s1,string s2){
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));

        for(int row=0;row<=m;row++){
            dp[row][0]=0;
        }
        for(int col=0;col<=n;col++){
            dp[0][col]=0;
        }

        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                } else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[m][n];

        // Just printing the LCS for revision
        string lcs="";

        int i=m,j=n;
        while(i>0 && j>0){
            if(dp[i-1]==dp[j-1]){
                lcs+=s1[i-1];
                i--;
                j--;
            } else {

                if(dp[i-1][j]>dp[i][j-1]) i--;
                else j--;
            }
        }

        reverse(lcs.begin(),lcs.end());
        cout<<lcs<<endl;

    }
    int longestCommonSubsequence(string text1, string text2) {
        
        // APPROACH 1:- USING RECURSION +MEMOIZATION
        memset(memo,-1,sizeof(memo));
        // return a1(text1,text2,0,0);

        // approach 2:- using dp
        // here we will also do the printing of the LCS
        return a2(text1,text2);

    }
};
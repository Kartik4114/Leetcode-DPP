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
    int minDistance(string word1, string word2) {
        memset(memo,-1,sizeof(memo));

        // APPROACH 1:- RECURSION + MEMOIZATION(1ST)
        return a1(word1,word2,0,0);
    }
};
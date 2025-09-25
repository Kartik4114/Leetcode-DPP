class Solution {
public:
    int memo[201][201];
    int a1(vector<vector<int>>& triangle,int i,int j){
        int m=triangle.size();
        int n=triangle[0].size();

        if(memo[i][j]!=-1) return memo[i][j];

        if(i==m-1) return triangle[m-1][j];

        int x=triangle[i][j]+a1(triangle,i+1,j);
        int y=triangle[i][j]+a1(triangle,i+1,j+1);

        return memo[i][j]=min(x,y);
    }

    int a2(vector<vector<int>>& triangle){
        
        int m=triangle.size();
        int n=triangle[0].size();

        // here see this both dp size is m*m not m*n
        vector<vector<int>> dp(m,vector<int>(m,0));

        for(int j=0;j<m;j++){
            dp[m-1][j]=triangle[m-1][j];
        }

        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){

                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }

    int a3(vector<vector<int>>& triangle){
        
        int m=triangle.size();
        int n=triangle[0].size();

        vector<int> next(m,0);
        for(int j=0;j<m;j++){
            next[j]=triangle[m-1][j];
        }

        for(int i=m-2;i>=0;i--){
            vector<int> curr(m,0);
            for(int j=i;j>=0;j--){

                curr[j]=triangle[i][j]+min(next[j],next[j+1]);
            }

            next=curr;
        }
        return next[0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        // APPROACH 1:- USING RECURSION +MEMO
        // T.C :- O(N*N) ,S.C :- O(n) + O(n*n) (recursion stack space)
        // memset(memo,-1,sizeof(memo));
        // return a1(triangle,0,0); 

        // APPROACH 2:- USING DP
        // T.C :- O(N*N) ,S.C :- O(n*n) 
        return a2(triangle);  

        // APPROACH 3:- USING SPACE OPTIMIZATION
        // T.C :- O(N*N) ,S.C :- O(n) 
        return a3(triangle); 
    }
};
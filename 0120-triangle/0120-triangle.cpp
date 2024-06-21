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
    int minimumTotal(vector<vector<int>>& triangle) {
        
        // APPROACH 1:- USING RECURSION +MEMO
        memset(memo,-1,sizeof(memo));
        return a1(triangle,0,0);    
    }
};
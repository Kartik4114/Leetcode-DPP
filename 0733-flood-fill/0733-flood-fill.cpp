class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};

    void solve(vector<vector<int>> &image,int x,int y,int origColor,int newColor,vector<vector<int>> &ans){

        int m=image.size();
        int n=image[0].size();

        ans[x][y]=newColor;

        for(auto &dir:directions){
            int new_x=x+dir[0];
            int new_y=y+dir[1];

            if(new_x>=0 && new_x<m && new_y>=0 && new_y<n &&
             image[new_x][new_y]==origColor && ans[new_x][new_y]!=newColor){
                solve(image,new_x,new_y,origColor,newColor,ans);
            }
        } 
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int origColor=image[sr][sc];

        vector<vector<int>> ans=image;
        solve(image,sr,sc,origColor,color,ans);
        return ans;
    }
};
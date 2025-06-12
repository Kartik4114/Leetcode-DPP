class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>> que;

        int freshOrgs=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                } else if(grid[i][j]==1){
                    freshOrgs++;
                }
            }
        }

        if(freshOrgs==0) return 0;

        int minutes=0;
        while(!que.empty()){

            int N=que.size();
            while(N--){
                
                auto front=que.front();
                que.pop();

                int x=front.first;
                int y=front.second;                    
                for(auto &dir:directions){

                    int new_x=x+dir[0];
                    int new_y=y+dir[1];

                    if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && grid[new_x][new_y]==1){
                        grid[new_x][new_y]=2;
                        que.push({new_x,new_y});
                        freshOrgs--;
                    }
                }
            }

            minutes++;
        }

        return (freshOrgs==0) ? minutes-1 : -1;
    }
};
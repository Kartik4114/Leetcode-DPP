class Solution {
public:
    vector<vector<int>> directions{{-1,0},{1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        if(n==0 || grid[0][0]==1) return -1;

        queue<pair<int,int>> que;
        que.push({0,0});
        grid[0][0]=1;

        int cnt=0;
        while(!que.empty()){

            int N=que.size();

            while(N--){
                int x=que.front().first;
                int y=que.front().second;
                que.pop();

                if(x==n-1 && y==n-1) return cnt+1;
                for(auto &dir:directions){

                    int new_x=x+dir[0];
                    int new_y=y+dir[1];

                    if(new_x>=0 && new_x<n && new_y>=0 && new_y<n && grid[new_x][new_y]==0){
                        que.push({new_x,new_y});
                        grid[new_x][new_y]=1;
                    }
                }

            }
            cnt++;
        }
        return -1;
    }
};
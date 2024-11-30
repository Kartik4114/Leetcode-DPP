class Solution {
public:
    typedef pair<int,pair<int,int>> P;

    vector<vector<int>> directions = {{0,-1},{0,1},{1,0},{-1,0}};
    int minimumTime(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        // Base Case
        if(grid[0][1]>1 && grid[1][0]>1) return -1;

        vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        result[0][0]=0;

        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,{0,0}});

        vector<vector<int>> visited(m,vector<int>(n,false));

        while(!pq.empty()){

            auto curr=pq.top();
            pq.pop();

            int time=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;

            if(i==m-1 && j==n-1) return result[m-1][n-1];

            if(visited[i][j]==true) continue;
            visited[i][j]=true;

            for(auto &dir:directions){

                int new_i=i+dir[0];
                int new_j=j+dir[1];

                if(new_i<0 || new_i>=m || new_j<0 || new_j>=n) continue;

                if(grid[new_i][new_j] <= time+1){

                    result[new_i][new_j]=time+1;
                    pq.push({time+1,{new_i,new_j}});

                } else if((grid[new_i][new_j]-time)%2==0){
                    pq.push({grid[new_i][new_j]+1,{new_i,new_j}});
                    result[new_i][new_j]=grid[new_i][new_j]+1;

                } else {
                    pq.push({grid[new_i][new_j],{new_i,new_j}});
                    result[new_i][new_j]=grid[new_i][new_j];
                }
            }
        }

        return result[m-1][n-1];
    }
};
class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions={{0,-1},{0,1},{1,0},{-1,0}};

    int minimumObstacles(vector<vector<int>>& grid) {
        
        int m=grid.size(); 
        int n=grid[0].size();

        vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        result[0][0]=0;

        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,{0,0}});

        while(!pq.empty()){

            auto curr=pq.top();
            pq.pop();

            int d=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;

            for(auto &dir:directions){
                int new_i=i+dir[0];
                int new_j=j+dir[1];

                if(new_i<0 || new_j<0 || new_i>=m || new_j>=n) continue;

                int wt=grid[new_i][new_j]==1 ? 1:0;
                if(d+wt<result[new_i][new_j]){
                    result[new_i][new_j]=d+wt;
                    pq.push({d+wt,{new_i,new_j}});
                }
            }

        }
        return result[m-1][n-1];
    }
};
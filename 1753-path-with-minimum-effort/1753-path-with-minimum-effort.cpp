class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions ={{-1,0},{1,0},{0,1},{0,-1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m=heights.size();
        int n=heights[0].size();

        priority_queue<P,vector<P>,greater<P>> pq;  
        vector<vector<int>> result(m,vector<int>(n,INT_MAX));

        pq.push({0,{0,0}});
        result[0][0]=0;

        while(!pq.empty()){

            int diff=pq.top().first;
            auto node=pq.top().second;
            int x=node.first;
            int y=node.second;
            pq.pop();

            for(auto &dir:directions){

                int new_x=x+dir[0];
                int new_y=y+dir[1];

                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n){

                    int absDiff=abs(heights[x][y]-heights[new_x][new_y]);
                    int maxDiff=max(diff,absDiff);

                    if(result[new_x][new_y]>maxDiff){
                        result[new_x][new_y]=maxDiff;
                        pq.push({maxDiff,{new_x,new_y}});
                    }
                }
            }
        }

        return result[m-1][n-1];
    }
};
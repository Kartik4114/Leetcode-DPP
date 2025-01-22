class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    
    // T.C :- O(m*n)
    // S.C :- O(m*n) // for storing queue

    // Applying multi-source BFS
        int m=isWater.size();
        int n=isWater[0].size();

        vector<vector<int>> heights(m,vector<int>(n,-1));
        queue<pair<int,int>> que;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(isWater[i][j]==1){
                    heights[i][j]=0;
                    que.push({i,j});
                }
            }
        }

        while(!que.empty()){

            int levelSize=que.size();

            while(levelSize--){

                auto P=que.front();
                que.pop();

                int i=P.first;
                int j=P.second;

                for(auto &dir:directions){

                    int new_i=dir[0]+i;
                    int new_j=dir[1]+j;

                    if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && heights[new_i][new_j]==-1){
                        heights[new_i][new_j]=heights[i][j]+1;
                        que.push({new_i,new_j});
                    }
                }
            }
        }

        return heights;
    }
};
class Solution {
public:
    void dfs(vector<vector<int>> &stones,vector<bool> &visited,int u){
        int n=stones.size();
        visited[u]=true;

        for(int i=0;i<n;i++){

            int row=stones[i][0];
            int col=stones[i][1];

            if(!visited[i] && (stones[u][0]==row || stones[u][1]==col)){
                dfs(stones,visited,i);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        
        int n=stones.size();

        int groups=0;
        vector<bool> visited(n,false);

        for(int i=0;i<n;i++){

            if(!visited[i]){
                dfs(stones,visited,i);
                groups++;
            }
        }
        return n-groups;
    }
};
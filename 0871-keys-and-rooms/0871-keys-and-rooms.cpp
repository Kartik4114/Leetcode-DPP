class Solution {
public:

    void dfs(unordered_map<int,vector<int>> &adj,vector<bool> &visited,int u){
        visited[u]=true;

        for(auto &v:adj[u]){

            if(!visited[v]){
                dfs(adj,visited,v);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++)
            adj[i].push_back(rooms[i][j]);
        }

        vector<bool> visited(n,false);

        dfs(adj,visited,0);

        for(int i=0;i<n;i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};
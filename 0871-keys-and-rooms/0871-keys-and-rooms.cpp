class Solution {
public:

    void dfs(vector<vector<int>> &adj,vector<bool> &visited,int u){
        visited[u]=true;

        for(auto &v:adj[u]){

            if(!visited[v]){
                dfs(adj,visited,v);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n=rooms.size();
        vector<bool> visited(n,false);

        dfs(rooms,visited,0);

        for(int i=0;i<n;i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};
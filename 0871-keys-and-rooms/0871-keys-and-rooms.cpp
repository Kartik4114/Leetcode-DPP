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

    void bfs(vector<vector<int>> &rooms,vector<bool> &visited){

        queue<int> que;
        visited[0]=true;
        que.push(0);

        while(!que.empty()){
            auto front=que.front();
            que.pop();

            for(auto &v: rooms[front]){
                if(!visited[v]){
                    visited[v]=true;
                    que.push(v);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n=rooms.size();
        vector<bool> visited(n,false);

        // dfs(rooms,visited,0);
        bfs(rooms,visited);

        for(int i=0;i<n;i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};
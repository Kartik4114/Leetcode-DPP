class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &adj,vector<bool> &visited,int s,int d){
        visited[s]=true;

        if(s==d) return true;

        for(auto &v:adj[s]){
            if(!visited[v]){
                if(dfs(adj,visited,v,d)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int,vector<int>> adj;

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);
        bool ans=dfs(adj,visited,source,destination);
        return ans;
    }
};
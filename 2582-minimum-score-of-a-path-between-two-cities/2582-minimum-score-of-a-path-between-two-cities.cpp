class Solution {
public:
    typedef pair<int,int> p;

    int dfs(unordered_map<int,vector<p>> &adj,vector<bool> &visited,int u){
        visited[u]=true;

        int mini=INT_MAX;
        for(auto &node:adj[u]){
            
            int adjNode=node.first;
            int dist=node.second;
            
            mini=min(mini,dist);
            if(!visited[adjNode]){
                int ans=dfs(adj,visited,adjNode);
                mini=min(mini,ans);
            }
        }

        return mini;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,vector<p>> adj;

        for(auto &road:roads){
            int u=road[0];
            int v=road[1];
            int w=road[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            
        }

        vector<bool> visited(n+1,false);
        return dfs(adj,visited,1);
    }
};
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& adj,vector<bool>& visited, int s, int d) {
        if(s==d) return true;

        if(visited[s]) return false;
        visited[s] = true;

        for (auto &v : adj[s]) {
            if (dfs(adj, visited, v, d)==true) {
                return true;
            }
        }
        return false;

    }

    bool validPath(int n,vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> adj;

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        return dfs(adj, visited, source, destination);
    }
};
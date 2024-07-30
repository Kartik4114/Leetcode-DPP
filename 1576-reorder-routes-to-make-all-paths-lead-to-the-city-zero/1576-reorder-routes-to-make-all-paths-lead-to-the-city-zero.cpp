class Solution {
public:
    typedef pair<int, int> p;

    int dfs(unordered_map<int, vector<p>>& adj, vector<bool>& visited, int u) {
        visited[u] = true;

        int cnt = 0;
        for (auto& edge : adj[u]) {
            int node = edge.first;
            int dir = edge.second; // original path or not


            if (!visited[node]) {
                cnt+=dir;
                cnt += dfs(adj, visited, node);
            }
        }
        return cnt;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<p>> adj;
        for (auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        vector<bool> visited(n, false);
        return dfs(adj, visited, 0);
    }
};

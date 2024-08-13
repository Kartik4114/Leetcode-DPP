class Solution {
public:
    int countOfGoodNodes=0;
    int dfs(int u,int parent,vector<vector<int>> &adj){

        int subtreeSizes=1;
        unordered_set<int> uniqueSizes;
        for(auto v:adj[u]){
            if(v==parent) continue;

            int currentSubtreeSizes=dfs(v,u,adj);
            subtreeSizes+=currentSubtreeSizes;
            uniqueSizes.insert(currentSubtreeSizes);
        }
        if(uniqueSizes.size()<=1) countOfGoodNodes++;
        return subtreeSizes;

    }
    int countGoodNodes(vector<vector<int>>& edges) {
        
        int n=edges.size();
        vector<vector<int>> adj(n+1);

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0,-1,adj);
        return countOfGoodNodes;
    }
};
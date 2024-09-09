class Solution {
public:
    int dfs(unordered_map<int,vector<int>> &adj,vector<bool> &hasApple,int currNode,int parentNode){

        int time=0;
        for(auto &child:adj[currNode]){
            if(child==parentNode) continue;

            int timeFromChild=dfs(adj,hasApple,child,currNode);
            if(timeFromChild>0 || hasApple[child]>0){
                time+=timeFromChild+2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        unordered_map<int,vector<int>> adj;

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans=dfs(adj,hasApple,0,-1);
        return ans;
    }
};
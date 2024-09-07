class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &adj,vector<int> &color,int u,int currColor){
        color[u]=currColor;

        for(auto &v:adj[u]){

            if(color[v]==color[u]) return false;

            if(color[v]==-1){
                int colorOfV=1-color[u];

                if(dfs(adj,color,v,colorOfV)==false) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> color(n+1,-1);
        unordered_map<int,vector<int>> adj;

        for(auto &dislike:dislikes){

            int u=dislike[0];
            int v=dislike[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=1;i<n+1;i++){

            if(color[i]==-1){
                if(dfs(adj,color,i,0)==false) return false;
            }
        }
        return true;
    }
};
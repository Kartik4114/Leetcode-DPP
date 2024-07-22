class Solution {
public:
    void dfs(vector<int> &visited,unordered_map<int,vector<int>> &adj,stack<int> &st,int u,bool &cycle){

        visited[u]=1;
        for(auto v:adj[u]){

            if(visited[v]==0){
                dfs(visited,adj,st,v,cycle);
            } else if(visited[v]==1){
                cycle=true;
                return;
            }
        }

        visited[u]=2;
        st.push(u);
    }
    vector<int> topoSort(vector<vector<int>> &edges,int k){

        unordered_map<int,vector<int>> adj;

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            // u->v
            adj[u].push_back(v);
        }
        vector<int> visited(k+1,0);
        // 0 -> not visited
        // 1 -> in recursion or in process
        // 2 -> already visited
        
        stack<int> st;
        bool cycle=false;
        for(int i=1;i<=k;i++){
            
            if(!visited[i]){
                dfs(visited,adj,st,i,cycle);
                if(cycle){
                    return {};
                }
            }
        }

        vector<int> order; // final topological sorted array

        while(!st.empty()){
            order.push_back(st.top());
            st.pop();
        }
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int> topoRow=topoSort(rowConditions,k);
        vector<int> topoCol=topoSort(colConditions,k);

        if(topoRow.empty() || topoCol.empty()) return {};

        vector<vector<int>> matrix(k,vector<int>(k,0));

        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){

                if(topoRow[i]==topoCol[j]){
                    matrix[i][j]=topoRow[i];
                }
            }
        }

        return matrix;

    }
};
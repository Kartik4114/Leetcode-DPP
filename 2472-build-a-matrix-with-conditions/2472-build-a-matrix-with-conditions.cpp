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
    vector<int> topoSortDFS(vector<vector<int>> &edges,int k){

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

    vector<int> topoSortBFS(vector<vector<int>> &edges,int k){

        unordered_map<int,vector<int>> adj;

        vector<int> inDegree(k+1,0);

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> que;
        for(int i=1;i<=k;i++){
            if(inDegree[i]==0){
                que.push(i);
            }
        }

        vector<int> order;
        int count=0;
        while(!que.empty()){

            int front=que.front();
            que.pop();
            count++;
            order.push_back(front);

            for(auto &v:adj[front]){

                inDegree[v]--;
                if(inDegree[v]==0){
                    que.push(v);
                }
            }

        }

        if(count!=k) return {};
        return order;

    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        // T.C :- O(k*k +n)  // k*k bec. of matrix array
        // S.C :- O(k*k +n)

        // USING TOPOLOGICAL SORT DFS
        // vector<int> topoRow=topoSortDFS(rowConditions,k); // O(n)
        // vector<int> topoCol=topoSortDFS(colConditions,k); // O(n)

        // USING TOPOLOGICAL SORT DFS
        vector<int> topoRow=topoSortBFS(rowConditions,k); // O(n)
        vector<int> topoCol=topoSortBFS(colConditions,k); // O(n)

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
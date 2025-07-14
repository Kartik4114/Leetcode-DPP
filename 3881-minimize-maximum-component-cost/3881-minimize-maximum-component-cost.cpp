class Solution {
public:
    typedef pair<int,int> P;

    int BFS(unordered_map<int,vector<P>> &adj,vector<bool> &visited,int node){

        queue<int> que;
        que.push(node);
        
        visited[node]=true;
        
        int maxCost=-1;
        while(!que.empty()){

            int N=que.size();

            while(N--){

                int top=que.front();
                que.pop();

                for(auto &adjNode:adj[top]){
                    
                    int v=adjNode.first;
                    int w=adjNode.second;
                    if(!visited[v]){
                        maxCost=max(maxCost,w);
                        visited[v]=true;
                        que.push(v);
                    }   
                }
            }
        }

        return maxCost;
    }

vector<vector<int>> primAlgo(int n, vector<vector<int>> &edges) {
        vector<vector<P>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0}); // {weight, node}

        vector<bool> inMST(n, false);
        vector<vector<int>> result;
        vector<int> parent(n, -1);

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (inMST[node]) continue;

            inMST[node] = true;

            if (parent[node] != -1) {
                result.push_back({parent[node], node, wt});
            }

            for (auto &tmp : adj[node]) {
                int neigh = tmp.first;
                int neighWt = tmp.second;

                if (!inMST[neigh]) {
                    pq.push({neighWt, neigh});
                    parent[neigh] = node;
                }
            }
        }

        return result;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
        
        if(k>edges.size()) return 0;

        auto result=primAlgo(n,edges);
        priority_queue<vector<int>> pq;

        for(auto &edge:result){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];

            pq.push({w,u,v});
            // cout<<w<<" ";

        }

        cout<<endl;

        while(!pq.empty() && k-1>0){
            // cout<<pq.top()[0]<<" ";
            pq.pop();
            k--;
        }

        if(!pq.empty()){
            return pq.top()[0];
        }
        return 0;

        // unordered_map<int,vector<P>> adj;
        // while(!pq.empty()){

        //     auto edge=pq.top();
        //     pq.pop();

        //     int u=edge[1];
        //     int v=edge[2];
        //     int w=edge[0];

        //     adj[u].push_back({v,w});
        //     adj[v].push_back({u,w});
        // } 

        // vector<bool> visited(n,false);

        // int maxCost=0;
        // for(int i=0;i<n;i++){

        //     if(!visited[i]){
        //         int currCost=BFS(adj,visited,i);
        //         maxCost=max(maxCost,currCost);
        //     }
        // }

        // return maxCost;
    }
};
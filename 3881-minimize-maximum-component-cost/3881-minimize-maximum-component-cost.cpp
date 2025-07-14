class Solution {
public:
    typedef pair<int,int> P;

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
        }

        cout<<endl;

        while(!pq.empty() && k-1>0){
            pq.pop();
            k--;
        }

        if(!pq.empty()){
            return pq.top()[0];
        }
        return 0;
    }
};
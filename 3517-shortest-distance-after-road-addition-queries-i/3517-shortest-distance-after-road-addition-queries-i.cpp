class Solution {
public:
    typedef pair<int,int> p;
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        unordered_map<int,vector<p>> adj;
        
        
        for(int i=0;i<n-1;i++){
            
            int u=i;
            int v=i+1;
            
            adj[u].push_back({v,1});
        }
        
        vector<int> ans;
        for(auto &query:queries){
            
            int u=query[0];
            int v=query[1];
            
            adj[u].push_back({v,1});
            
            priority_queue<p,vector<p>,greater<p>> pq;
            vector<int> result(n,INT_MAX);
            pq.push({0,0});
            
            while(!pq.empty()) {

                int d  = pq.top().first;
                int node = pq.top().second;
                pq.pop();

                for(auto &vec : adj[node]) {

                    int adjNode = vec.first;
                    int dist    = vec.second;

                    if(d + dist < result[adjNode]) {

                        result[adjNode] = d + dist;
                        pq.push({d+dist, adjNode});

                    }

                }

		    }
            
            int shortDist=result[n-1];
            ans.push_back(shortDist == INT_MAX ? -1 : shortDist);
            
            
        }
        
        
        return ans;
        
    }
};
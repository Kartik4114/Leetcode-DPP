class Solution {
public:
    typedef pair<int,int> p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int,vector<p>> adj;

        for(auto &vec:times){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];

            adj[u].push_back({v,w});
        }

        priority_queue<p,vector<p>,greater<p>> pq;
        vector<int> result(n+1,INT_MAX);

        result[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto &it: adj[node]){
                int adjNode=it.first;
                int wt=it.second;

                if(dist+wt< result[adjNode]){
                    result[adjNode]=dist+wt;
                    pq.push({dist+wt,adjNode});
                }
            }
        }

        int maxTime=-1;
        for(int i=1;i<=n;i++){
            maxTime=max(maxTime,result[i]);
        }

        if(maxTime==INT_MAX) return -1;
        else return maxTime;
    }
};
class Solution {
public:
    typedef pair<int,int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int,vector<P>> adj;
        for(auto &time:times){
            
            int u=time[0];
            int v=time[1];
            int w=time[2];
            adj[u].push_back({v,w});
        }

        vector<int> result(n+1,INT_MAX);
        priority_queue<P,vector<P>,greater<P>> pq;

        pq.push({0,k});
        result[k]=0;

        while(!pq.empty()){

            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto &it:adj[node]){
                int dist=it.second;
                int adjNode=it.first;

                if(d+dist<result[adjNode]){
                    result[adjNode]=d+dist;
                    pq.push({d+dist,adjNode});
                }
            }
        }


        int maxTime=-1;
        for(int i=1;i<n+1;i++){
            maxTime=max(maxTime,result[i]);
        }

        return maxTime==INT_MAX ? -1 : maxTime;
    }
};
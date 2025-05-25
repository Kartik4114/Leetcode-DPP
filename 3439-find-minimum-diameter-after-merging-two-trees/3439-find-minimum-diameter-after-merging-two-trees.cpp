class Solution {
public:

    pair<int,int> BFS(unordered_map<int,vector<int>> &adj,int src){
        
        int n=adj.size();

        queue<int> que;
        que.push(src);

        unordered_map<int,bool> visited; 
        visited[src]=true;

        int farthestNode=src;
        int distance=0;

        while(!que.empty()){

            int n=que.size();
            // distance++;
            while(n--){

                int curr=que.front();
                que.pop();

                farthestNode=curr;

                for(auto &v:adj[curr]){

                    if(visited[v]==false){
                        visited[v]=true;
                        que.push(v);
                    }
                }
            }

            if(!que.empty()) {
                distance++;
            }
        }

        return {farthestNode,distance};
    }
    int findDiameter(unordered_map<int,vector<int>> &adj){

        auto [farthestNode,dist] = BFS(adj,0);
        auto [otherEnd,diameter] = BFS(adj,farthestNode);

        return diameter;
    }
    unordered_map<int,vector<int>> buildAdj(vector<vector<int>>& edges){

        unordered_map<int,vector<int>> adj;

        for(auto &edge:edges){

            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
        auto adj1=buildAdj(edges1);
        auto adj2=buildAdj(edges2);


        int d1=findDiameter(adj1);
        int d2=findDiameter(adj2);

        int combined=(d1+1)/2 + (d2+1)/2 +1;

        int ans= max({d1,d2,combined});
        return ans;
        

    }
};
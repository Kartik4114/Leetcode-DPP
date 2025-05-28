class Solution {
public:
    
    unordered_map<int,vector<int>> buildAdj(vector<vector<int>> &edges){

        unordered_map<int,vector<int>> adj;

        for(auto &edge:edges){
            
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    int BFS(unordered_map<int,vector<int>> &adj,int u,int k){

        int n=adj.size();

        vector<bool> visited(n,false);
        queue<int> que;

        que.push(u);
        visited[u]=true;

        int result=1;
        int cnt=0;
        while(!que.empty()){

            int n=que.size();

            while(n--){

                int node=que.front();
                que.pop();

                for(auto &v:adj[node]){

                    if(!visited[v]){
                        visited[v]=true;
                        que.push(v);
                    }
                }
            }

            cnt++;
            if(cnt>k) break;
            result+=que.size();

        }

        return result;
    }
    vector<int> calTargetnode( unordered_map<int,vector<int>> &adj,int k){

        int n=adj.size();

        vector<int> result(n,0);
        for(int u=0;u<n;u++){

            result[u]=BFS(adj,u,k);
        }

        return result;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        

        auto adj1=buildAdj(edges1);
        auto adj2=buildAdj(edges2);

        int cntNodes=adj1.size();


        vector<int> v1=calTargetnode(adj1,k);
        vector<int> v2=calTargetnode(adj2,k-1);

        int maxDist=*max_element(v2.begin(),v2.end());

        if(k==0) return v1;

        vector<int> result(cntNodes,0);

        for(auto &v:v2){
            cout<<v<<" ";
        }

        for(int i=0;i<cntNodes;i++){
            result[i]=v1[i]+maxDist;
        }

        return result;

    }
};
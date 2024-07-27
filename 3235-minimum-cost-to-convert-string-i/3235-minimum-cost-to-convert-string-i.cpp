class Solution {
public:
    void floydWarshall(vector<vector<long long>> &adj,vector<char> &original,vector<char> &changed,vector<int> &cost){
        
        for(int i=0;i<original.size();i++){

            int s=original[i]-'a';
            int t=changed[i]-'a';

            adj[s][t]=min(adj[s][t],(long long)cost[i]);
        }

        for(int via=0;via<26;via++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){

                    adj[i][j]=min(adj[i][j],adj[i][via]+adj[via][j]);
                }
            }
        }
    }
    long long a1(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost){

        vector<vector<long long>> adj(26,vector<long long>(26,INT_MAX));

        floydWarshall(adj,original,changed,cost);

        long long ans=0;
        for(int i=0;i<source.length();i++){
            if(source[i]==target[i]) continue;

            if(adj[source[i]-'a'][target[i]-'a']==INT_MAX) return -1;

            ans+=adj[source[i]-'a'][target[i]-'a'];
        }

        return ans;
    }

    void dijkstra(vector<vector<long long>> &costMatrix,unordered_map<char,vector<pair<char,int>>> &adj,int source){

        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;

        pq.push({0,source});

        while(!pq.empty()){

            int d=pq.top().first;
            char adjNode=pq.top().second;
            pq.pop();

            for(auto &it: adj[adjNode]){

                char neighbor=it.first;
                int cost = it.second;

                if(costMatrix[source-'a'][neighbor-'a']>d+cost){
                    costMatrix[source-'a'][neighbor-'a']=d+cost;
                    pq.push({d+cost,neighbor});
                }
            }
        }
    }
    long long a2(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost){
        
        int n=original.size();
        unordered_map<char,vector<pair<char,int>>> adj;

        for(int i=0;i<n;i++){
            adj[original[i]].push_back({changed[i],cost[i]});
        }

        vector<vector<long long>> costMatrix(26,vector<long long>(26,INT_MAX));

        for(int i=0;i<source.size();i++){
            char ch=source[i];
            dijkstra(costMatrix,adj,ch);
        }

        long long ans=0;
        for(int i=0;i<source.length();i++){
            if(source[i]==target[i]) continue;

            if(costMatrix[source[i]-'a'][target[i]-'a']==INT_MAX) return -1;

            ans+=costMatrix[source[i]-'a'][target[i]-'a'];
        }

        return ans;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        // APPROACH 1:- USING FLOYD WARSHALL ALGORITHM
        //T.C : O(n)  -> Because other for loops run only for constant time 26*26*26
        //S.C : O(1) -> We take distances matrix of 26*26 which is constant 
        return a1(source,target,original,changed,cost);

        //Approach-2 (Using Simple Dijkstra's Algorithm)
        //T.C : n * (time complexity of Dijkstra) = O(n * (V+E)logV) ,
        //  where V = number of vertices and E = number of edges
        //S.C : O(V+E) -> We create a graph, where V = number of vertices and E = number of edges
        return a2(source,target,original,changed,cost);


    }
};
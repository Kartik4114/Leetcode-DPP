class Solution {
public:
    long rootResult;
    vector<int> count;
    int N;

    int dfsBase(unordered_map<int,vector<int>> &adj,int currNode,int prevNode,int currDepth){
        int totalCount=1; // count of node below count

        rootResult+=currDepth;
        for(auto &v:adj[currNode]){

            if(v==prevNode) continue;

            totalCount+=dfsBase(adj,v,currNode,currDepth+1);

        }
        count[currNode]=totalCount;
        return totalCount;
    }

    void dfs(unordered_map<int,vector<int>> &adj,int parentNode,int prevNode,vector<int> &result){

        for(auto &child:adj[parentNode]){

            if(child==prevNode) continue;

            result[child]=result[parentNode] - count[child] + N-count[child];
            dfs(adj,child,parentNode,result);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>> adj;
        N=n;
        count.resize(n,0);

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        rootResult=0;
        
       vector<int> result(n,0);
       count[0]=dfsBase(adj,0,-1,0);
       
       result[0]=rootResult;

       dfs(adj,0,-1,result);
       return result;
        
    }
};
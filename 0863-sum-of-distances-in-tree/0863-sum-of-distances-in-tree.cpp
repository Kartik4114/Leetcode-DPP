class Solution {
public:
    vector<int> count;
    int rootResult;
    int N;

    int dfsBase(unordered_map<int,vector<int>> &adj,int currNode,int prevNode,int currDepth){
        int totalCount=1;
        rootResult+=currDepth;

        for(auto &child:adj[currNode]){
            
            if(child==prevNode) continue;
            totalCount+=dfsBase(adj,child,currNode,currDepth+1);
        }

        count[currNode]=totalCount;
        return totalCount;

    }
    void dfs(unordered_map<int,vector<int>> &adj,int parentNode,int prevNode,vector<int> &result){

        for(auto &child:adj[parentNode]){
            if(child==prevNode) continue;

            result[child]=result[parentNode]-count[child] +(N-count[child]);
            dfs(adj,child,parentNode,result);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        count.resize(n,0);
        rootResult=0;
        N=n;

        unordered_map<int,vector<int>> adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(n,0);
        dfsBase(adj,0,-1,0);

        result[0]=rootResult;

        dfs(adj,0,-1,result);
        return result;

    }
};
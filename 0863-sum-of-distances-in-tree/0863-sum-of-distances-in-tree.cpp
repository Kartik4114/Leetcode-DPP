class Solution {
public:
    vector<int> count;
    int N;
    int rootResult;
    int dfsBase(unordered_map<int,vector<int>> &adj,int currNode,int parentNode,int currDepth){

        int totalCount=1;
        rootResult+=currDepth;

        for(auto &child:adj[currNode]){
            if(child==parentNode) continue;
            totalCount+=dfsBase(adj,child,currNode,currDepth+1);
        }

        count[currNode]=totalCount;
        return totalCount;
    }

    void dfs(unordered_map<int,vector<int>> &adj,int parentNode,int prevNode,vector<int> &result){

        for(auto &child:adj[parentNode]){

            if(child==prevNode) continue;

            result[child]=result[parentNode] - count[child] +(N-count[child]);
            dfs(adj,child,parentNode,result);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        N=n;
        rootResult=0;
        count.resize(n,0);

        unordered_map<int,vector<int>> adj;

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfsBase(adj,0,-1,0);

        vector<int> result(n,0);
        result[0]=rootResult;

        dfs(adj,0,-1,result);
        return result;
    }
};
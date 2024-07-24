class Solution {
public:
    vector<int> dfs(unordered_map<int,vector<int>> &adj,int currNode,int parent,vector<int> &result,string &labels){

        vector<int> myCount(26,0);
        char myLabel=labels[currNode];
        myCount[myLabel-'a']=1;

        for(auto &child: adj[currNode]){
            
            if(child==parent) continue;
            vector<int> childCount(26,0);
            childCount=dfs(adj,child,currNode,result,labels);

            for(int i=0;i<26;i++){
                myCount[i]+=childCount[i];
            }
        }
        result[currNode]=myCount[myLabel-'a'];
        return myCount;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

        unordered_map<int,vector<int>> adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(n,0);

        dfs(adj,0,-1,result,labels);
        return result;
    }
};
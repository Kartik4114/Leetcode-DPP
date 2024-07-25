class Solution {
public:
    vector<int> dfs_a1(unordered_map<int,vector<int>> &adj,int currNode,int parent,vector<int> &result,string &labels){

        vector<int> myCount(26,0);
        char myLabel=labels[currNode];
        myCount[myLabel-'a']=1;

        for(auto &child: adj[currNode]){
            
            if(child==parent) continue;
            vector<int> childCount(26,0);
            childCount=dfs_a1(adj,child,currNode,result,labels);

            for(int i=0;i<26;i++){
                myCount[i]+=childCount[i];
            }
        }
        result[currNode]=myCount[myLabel-'a'];
        return myCount;
    }

    void dfs_a2(unordered_map<int,vector<int>> &adj,int curr,int parent,vector<int> &result,string &labels,
                    vector<int> &count){
        
        char myLabel=labels[curr];
        int cntBeforeVisit=count[myLabel-'a'];

        count[myLabel-'a']++;
        for(auto &v:adj[curr]){
            if(v==parent) continue;

            dfs_a2(adj,v,curr,result,labels,count);

        }

        int cntAfterVisit=count[myLabel-'a'];
        result[curr]=cntAfterVisit-cntBeforeVisit;

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

        // APPROACH 1:- 
        // dfs_a1(adj,0,-1,result,labels);

        // APPROACH 2:- MORE OPTIMISED APPROACH
        vector<int> count(26,0);
        dfs_a2(adj,0,-1,result,labels,count);
        return result;
    }
};
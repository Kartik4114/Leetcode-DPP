class Solution {
public:
    void dfs(vector<vector<int>> &graph,int source,int dest,vector<int> temp,vector<vector<int>> &store){

        temp.push_back(source);

        if(source==dest){
            store.push_back(temp);
        } else {
            for(auto &child:graph[source]){
                dfs(graph,child,dest,temp,store);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> temp;
        vector<vector<int>> store;
        dfs(graph,0,n-1,temp,store);

        return store;
    }
};
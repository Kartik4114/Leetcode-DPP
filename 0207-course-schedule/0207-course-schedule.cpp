class Solution {
public:
    bool isCycle(unordered_map<int,vector<int>> &adj,vector<bool> &visited,vector<bool> &inRecursion,int u){
        visited[u]=true;
        inRecursion[u]=true;

        for(auto &v: adj[u]){

            if(!visited[v] && isCycle(adj,visited,inRecursion,v)) return true;

            else if(inRecursion[v]) return true;
        }
        inRecursion[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adj;

        vector<bool> visited(numCourses,false);
        vector<bool> inRecursion(numCourses,false);

        for(auto &p:prerequisites){
            int u=p[0];
            int v=p[1];

            adj[v].push_back(u);
        }
        
        for(int i=0;i<numCourses;i++){

            if(!visited[i] && isCycle(adj,visited,inRecursion,i)){
                return false;
            }
        }
        return true;
    }
};
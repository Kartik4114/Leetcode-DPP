class Solution {
public: 
    int result=-1;
    void dfs(vector<int> &edges,vector<bool> &visited,vector<bool> &inRecursion,vector<int>&count,int u){

        if(u!=-1){
            visited[u]=true;
            inRecursion[u]=true;

            int v=edges[u];
            if(v!=-1 && !visited[v]){
                count[v]=count[u]+1;
                dfs(edges,visited,inRecursion,count,v);
            } else if(v!=-1 && inRecursion[v]==true){

                result=max(result,count[u]-count[v]+1);
            }
            inRecursion[u]=false;
        }
    }
    int longestCycle(vector<int>& edges) {
        
        int n=edges.size();
        vector<bool> visited(n,false);
        vector<bool> inRecursion(n,false);

        vector<int> count(n,1);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(edges,visited,inRecursion,count,i);
            }
        }
        return result;
    }
};
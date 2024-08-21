class Solution {
public:
    void DFS(vector<vector<int>> &isConnected,vector<bool> &visited,int u){
        int n=isConnected.size();
        visited[u]=true;

        for(int v=0;v<n;v++){
            if(!visited[v] && isConnected[u][v]==1){
                DFS(isConnected,visited,v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int cnt=0;
        int n=isConnected.size();

        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                DFS(isConnected,visited,i);
                cnt++;
            }
        }
        return cnt;
    }
};
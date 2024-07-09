class Solution {
public:
    int cnt;

    void DFS(vector<vector<int>> &isConnected,int u,vector<bool> &visited){
        
        int n=isConnected.size();
        visited[u]=true;

        for(int v=0;v<n;v++){
            
            if(!visited[v] && isConnected[u][v]==1){
                visited[v]=true;
                DFS(isConnected,v,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        cnt=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                DFS(isConnected,i,visited);
                
            }
        }

        return cnt;
    }
};
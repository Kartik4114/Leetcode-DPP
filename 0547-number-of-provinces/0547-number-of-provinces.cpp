class Solution {
public:
    void solve(vector<vector<int>>& isConnected,vector<bool> &visited,int u){
        int n=isConnected.size();

        visited[u]=true;

        for(int v=0;v<isConnected[u].size();v++){

            if(!visited[v] && isConnected[u][v]==1){
                // visited[v]=true;
                solve(isConnected,visited,v);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        vector<bool> visited(n,0);

        int cnt=0;
        for(int i=0;i<n;i++){

            if(!visited[i]){
                solve(isConnected,visited,i);
                cnt++;
            }
        }

        return cnt;
    }
};
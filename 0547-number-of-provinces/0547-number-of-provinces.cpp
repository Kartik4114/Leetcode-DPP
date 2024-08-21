class Solution {
public:
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
    int a1(vector<vector<int>>& isConnected){
        int n=isConnected.size();
        int cnt=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                DFS(isConnected,i,visited);
                
            }
        }
        return cnt;
    }

    void BFS(vector<vector<int>>& adj,int u,vector<bool> &visited){

        int n=adj.size();
        queue<int> que;

        que.push(u);
        visited[u]=true;

        while(!que.empty()){
            int front=que.front();
            que.pop();

            for(int v=0;v<n;v++){
                if(!visited[v] && adj[front][v]==1){
                    que.push(v);
                    visited[v]=true;
                }
            }
        }

    }
    int a2(vector<vector<int>>& isConnected){
        int n=isConnected.size();
        int cnt=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                BFS(isConnected,i,visited);
            }
        }
        return cnt;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        // APPROACH 1:- USING DFS
        return a1(isConnected);

        // APPROACH 2:- USING BFS
        return a2(isConnected);
    }
};
class Solution {
public:
    void BFS(vector<vector<int>> &isConnected,vector<bool> &visited,int u){
        
        int n=isConnected.size();

        queue<int> que;
        que.push(u);
        visited[u]=true;

        while(!que.empty()){

            int front=que.front();
            que.pop();
            for(int v=0;v<n;v++){
                if(!visited[v] && isConnected[front][v]==1){
                    que.push(v);
                    visited[v]=true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int cnt=0;
        int n=isConnected.size();

        vector<bool> visited(n,false);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                BFS(isConnected,visited,i);
                cnt++;
            }
        }
        return cnt;
    }
};
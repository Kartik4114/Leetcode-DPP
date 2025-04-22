class Solution {
public:
    void BFS(vector<vector<int>>& isConnected,vector<int> &visited,int u){
        
        int n=isConnected.size();

        queue<int> que;
        visited[u]=true;

        que.push(u);

        while(!que.empty()){

            int node=que.front();
            que.pop();

            for(int i=0;i<n;i++){

                if(!visited[i] && isConnected[node][i]==1){
                    visited[i]=true;
                    que.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();

        vector<int> visited(n,0);

        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                BFS(isConnected,visited,i);
            }
        }

        return cnt;
    }
};
class Solution {
public:
    int cnt;

    void DFS(unordered_map<int,vector<int>> &mp,int u,vector<bool> &visited){

        visited[u]=true;

        for(auto &v:mp[u]){
            
            if(!visited[v]){
                visited[v]=true;
                DFS(mp,v,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        cnt=0;
        unordered_map<int,vector<int>> mp;
        vector<bool> visited(n,false);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(isConnected[i][j]==1){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }

        for(int i=0;i<mp.size();i++){
            if(!visited[i]){
                cnt++;
                DFS(mp,i,visited);
                
            }
        }

        return cnt;
    }
};
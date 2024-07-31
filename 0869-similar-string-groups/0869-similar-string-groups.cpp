class Solution {
public:
    void DFS(unordered_map<int,vector<int>> &adj,vector<bool> &visited,int u){
        visited[u]=true;

        for(auto &v:adj[u]){
            if(!visited[v]){
                DFS(adj,visited,v);
            }
        }
    }
    int a1(vector<string> &strs){

        unordered_map<int,vector<int>> adj;

        int m=strs.size();
        int n=strs[0].size();
        for(int i=0;i<m;i++){

            for(int j=i+1;j<m;j++){

                int diffCnt=0;
                for(int k=0;k<n;k++){
                    if(strs[i][k]!=strs[j][k]) diffCnt++;
                }

                if(diffCnt<=2){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(m,false);

        int cnt=0;
        for(int i=0;i<m;i++){
            if(!visited[i]){
                DFS(adj,visited,i);
                cnt++;
            }
        }
        return cnt;
    }
    int numSimilarGroups(vector<string>& strs) {
        
        // APPROACH 1:- USING DFS AND BFS
        return a1(strs);
    }
};
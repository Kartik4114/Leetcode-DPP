class Solution {
public:
    bool isSimilar(string str1,string str2){
        int diffCnt=0;
        int n=str1.size();
        for(int k=0;k<n;k++){
            if(str1[k]!=str2[k]) diffCnt++;
        }

        return diffCnt<=2;
    }
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

                if(isSimilar(strs[i],strs[j])){
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
        // SIMILARLY WE CAN CHECK FOR BFS
        return a1(strs);
    }
};
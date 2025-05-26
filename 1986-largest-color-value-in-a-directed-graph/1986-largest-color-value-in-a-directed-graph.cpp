class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n=colors.size();

        unordered_map<int,vector<int>> adj;
        vector<int> inDegree()

        for(auto &edge:edges){

            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> que;
        vector<vector<int>> t(n,vector<int>(26,0));

        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                que.push(d);
                t[colors[i]-'a']=1;
            }
        }

        int result=0;
        int countNodes=0;

        while(!que.empty()){

            int u=que.front();
            que.pop();

            result=max(result,t[u][colors[u]-'a']);
            countNodes++;

            for(auto &v:adj[u]){

                for(int i=0;i<26;i++){
                    
                }
            }
        }
    }
};
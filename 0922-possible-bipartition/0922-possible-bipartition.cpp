class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &adj,vector<int> &color,int u,int currColor){
        color[u]=currColor;

        for(auto &v:adj[u]){
            if(color[v]==color[u]) return false;

            if(color[v]==-1){
                int colorOfV=1-currColor;
                if(!dfs(adj,color,v,colorOfV)) return false;
            }
        }
        return true;

    }

    bool a1(int n,unordered_map<int,vector<int>> &adj,vector<int> &color){
        // 0 for red
        // 1 for green

        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(dfs(adj,color,i,0)==false) return false;
            }
        }
        return true;
    }

    bool bfs(unordered_map<int,vector<int>> &adj,vector<int> &color,int u){

        queue<int> que;
        que.push(u);
        color[u]=0;

        while(!que.empty()){
            int front=que.front();
            que.pop();

            for(auto &v:adj[front]){

                if(color[v]==color[front]) return false;

                if(color[v]==-1){
                    int colorOfV=1-color[front];
                    que.push(v);
                    color[v]=colorOfV;
                }
            }
        }
        return true;
    }
    bool a2(int n,unordered_map<int,vector<int>> &adj,vector<int> &color){
        // 0 for red
        // 1 for green

        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(bfs(adj,color,i)==false) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<dislikes.size();i++){
            int per1=dislikes[i][0];
            int per2=dislikes[i][1];

            adj[per1].push_back(per2);
            adj[per2].push_back(per1);
        }
        vector<int> color(n+1,-1);

        // APPROACH 1:- USING DFS
        // return a1(n,adj,color);

        // APPROACH 2:- USING BFS
        return a2(n,adj,color);

    }
};
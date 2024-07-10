class Solution {
public:
    bool checkBiparateDFS(vector<vector<int>>& graph,int curr,vector<int> &color,int currColor){
        color[curr]=currColor;

        for(auto &v:graph[curr]){
            if(color[v]==color[curr]) return false;

            if(color[v]==-1){
                int colorOfV=1-currColor;
                if(checkBiparateDFS(graph,v,color,colorOfV)==false) return false;
            }
        }
        return true;
    }

    bool a1(vector<vector<int>>& graph){
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(checkBiparateDFS(graph,i,color,1)==false) return false;
            }
        }
        return true;
    }

    bool checkBipartiteBFS(vector<vector<int>>& graph,int curr,vector<int> &color,int currColor){
        color[curr]=currColor;

        queue<int> que;
        que.push(curr);

        while(!que.empty()){
            int front=que.front();
            que.pop();

            for(auto &v:graph[front]){
                if(color[v]==color[front]) return false;

                else if(color[v]==-1){
                    color[v]=1-color[front];
                    que.push(v);
                }
            }
        }
        return true;

    }
    bool a2(vector<vector<int>>& graph){

        int n=graph.size();
        vector<int> color(n,-1);

        // RED 1
        // GREEn 0
        for(int i=0;i<n;i++){
            
            if(color[i]==-1)
            if(checkBipartiteBFS(graph,i,color,1)==false) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        // APPROACH 1:- USING DFS
        // return a1(graph);

        // APPROACH 1:- USING BFS
        return a2(graph);
    }
};
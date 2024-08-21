class Solution {
public:
    bool check(vector<vector<int>> &graph,vector<int> &color,int curr,int currColor){
        
        queue<int> que;
        color[curr]=currColor;
        que.push(curr);

        while(!que.empty()){
            int front=que.front();
            que.pop();

            for(auto &v:graph[front]){

                if(color[v]==color[front]) return false;
                if(color[v]==-1){
                    que.push(v);
                    color[v]=1-color[front];
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(check(graph,color,i,1)==false) return false;
            }
        }
        return true;
    }
};
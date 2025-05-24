class Solution {
public:
    bool check(vector<vector<int>> & graph,int curr,vector<int>& color,int currColor){

        queue<int> que;
        color[curr]=currColor;

        que.push(curr);

        while(!que.empty()){

            int node=que.front();
            que.pop();

            for(auto &v:graph[node]){

                if(color[v]==color[node]) return false;

                if(color[v]==-1){
                    que.push(v);
                    color[v]=1-color[node];
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1 && check(graph,i,color,1)==false){
                return false;
            }
        }

        return true;
    }
};
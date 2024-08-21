class Solution {
public:
    bool isCheck(vector<vector<int>> &graph,vector<int> &color,int curr,int currColor){

        color[curr]=currColor;
        
        for(auto &v:graph[curr]){
            if(color[v]==color[curr]) return false;
            if(color[v]==-1){

                int colorOfV=1-currColor;
                if(isCheck(graph,color,v,colorOfV)==false) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1 && isCheck(graph,color,i,1)==false) return false;
        }

        return true;
    }
};
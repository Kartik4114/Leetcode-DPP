class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<bool> inDegree(n,false);

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            inDegree[v]=true;
        }

        vector<int> result;
        for(int i=0;i<n;i++){
            if(inDegree[i]==false) result.push_back(i);
        }
        return result;
    }
};
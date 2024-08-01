class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        // unordered_map<int,vector<int>> mp;
        vector<int> inDegree(n,0);

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            inDegree[v]++;
        }

        vector<int> result;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0) result.push_back(i);
        }
        return result;
    }
};
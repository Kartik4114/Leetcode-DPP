class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int> inDegree(n,0);

        for(auto &edge:edges){

            int u=edge[0];
            int v=edge[1];

            inDegree[v]++;
        }

        int cnt=0;
        int champion=-1;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                cnt++;
                champion=i;
            }

            if(cnt>1) {
                return -1;
            }
        }

        return champion;
    }
};
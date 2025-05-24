class Solution {
public:
    bool check(unordered_map<int,vector<int>> &adj,int N){

        vector<int> inDegree(N);
        int cnt=0;

        for(int u=0;u<N;u++){
            for(auto &v:adj[u]){
                inDegree[v]++;
                
            }
        }

        queue<int> que;

        for (int i = 0; i < N; ++i) {      // iterate by index
            if (inDegree[i] == 0) {
                que.push(i);               // ✔ push the vertex ID
            }
        }

        while(!que.empty()){

            int node=que.front();
            que.pop();
            cnt++;
            

            for(auto &v:adj[node]){

                inDegree[v]--;
                if(inDegree[v]==0) {
                    que.push(v);
                    // cnt++;
                }
            }
        }

        if(cnt==N) return true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adj;

        for(auto &edge:prerequisites){

            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
        }

        bool ans=check(adj,numCourses);
        return ans;
    }
};
class Solution {
public:
    bool BFS(int n,unordered_map<int,vector<int>> &adj,vector<int> &inDegree){
        queue<int> que;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                que.push(i);
                cnt++;
            }
        }

        while(!que.empty()){
            int u=que.front();
            que.pop();

            for(auto &v:adj[u]){

                inDegree[v]--;
                if(inDegree[v]==0){
                    que.push(v);
                    cnt++;
                }
            }
        }

        if(cnt==n) return true;
        return false;
    }
    bool a1(int numCourses, vector<vector<int>>& prerequisites){
        unordered_map<int,vector<int>> adj;

        vector<int> inDegree(numCourses,0);

        for(auto &vec:prerequisites){
            int a=vec[0];
            int b=vec[1];

            adj[b].push_back(a);
            inDegree[a]++;
        }

        return BFS(numCourses,adj,inDegree);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // APPROACH 1:- USING BFS
        // IT IS DETECT CYCLE IN DIRECTED GRAPH(KAHN'S ALGORITHM)

        return a1(numCourses,prerequisites);

    }
};
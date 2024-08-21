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
    
    bool isCycleDFS(unordered_map<int,vector<int>> &adj,vector<bool> &visited,int u,
                    vector<bool> &inRecursion){
        visited[u]=true;
        inRecursion[u]=true;

        for(auto &v:adj[u]){
            if(!visited[v] && isCycleDFS(adj,visited,v,inRecursion))
            return true;

            else if(inRecursion[v]==true) return true;
        }
        inRecursion[u]=false;
        return false;

    }
    bool a2(int numCourses, vector<vector<int>>& prerequisites){
        unordered_map<int,vector<int>> adj;

        vector<bool> visited(numCourses,false);
        vector<bool> inRecursion(numCourses,false);

        for(auto &vec:prerequisites){
            int a=vec[0];
            int b=vec[1];

            adj[b].push_back(a);
        }

        for(int i=0;i<numCourses;i++){

            if(!visited[i] && isCycleDFS(adj,visited,i,inRecursion))
             return false;
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // APPROACH 1:- USING BFS
        // IT IS DETECT CYCLE IN DIRECTED GRAPH(KAHN'S ALGORITHM)

        // return a1(numCourses,prerequisites);

        // APPROACH 2:- USING DFS

        // IT IS DETECT CYCLE IN DIRECTED GRAPH
        return a2(numCourses,prerequisites);

    }
};
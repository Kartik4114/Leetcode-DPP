class Solution {
public:
    vector<int> topologicalSort(int n,unordered_map<int,vector<int>> &adj,vector<int> &inDegree){
        queue<int> que;

        vector<int> result;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                result.push_back(i);
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
                    result.push_back(v);
                    que.push(v);
                    cnt++;
                }
            }
        }

        if(cnt==n) return result;
        return {};
    }
    vector<int> a1(int numCourses, vector<vector<int>>& prerequisites){
        unordered_map<int,vector<int>> adj;

        vector<int> inDegree(numCourses,0);

        for(auto &vec:prerequisites){
            int a=vec[0];
            int b=vec[1];

            adj[b].push_back(a);
            inDegree[a]++;
        }

        return topologicalSort(numCourses,adj,inDegree);
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // APPROACH 1:- USING BFS
        // IT IS DETECT CYCLE IN DIRECTED GRAPH(KAHN'S ALGORITHM)

        return a1(numCourses,prerequisites);

        // APPROACH 2:- USING DFS

        // IT IS DETECT CYCLE IN DIRECTED GRAPH
        // return a2(numCourses,prerequisites);

    }
};
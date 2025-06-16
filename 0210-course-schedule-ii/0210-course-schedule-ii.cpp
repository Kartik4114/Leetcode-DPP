class Solution {
public:
    bool hasCycle=false;

    void check(unordered_map<int,vector<int>> &adj,vector<bool> &visited,vector<bool> &inRecursion,int node,stack<int>&st){

        visited[node]=true;
        inRecursion[node]=true;

        for(auto &v:adj[node]){

            if(!visited[v]){
                check(adj,visited,inRecursion,v,st);
            }

            if(inRecursion[v]==true){
                hasCycle=true;
                return;
            }
        }
        st.push(node);
        inRecursion[node]=false;
        return;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adj;

        for(auto &edge:prerequisites){

            int u=edge[0];
            int v=edge[1];

            adj[v].push_back(u);
        }

        stack<int> st;
        vector<bool> visited(numCourses,false);
        vector<bool> inRecursion(numCourses,false);

        for(int i=0;i<numCourses;i++){

            if(!visited[i]){
                check(adj,visited,inRecursion,i,st);
            }
        }

        if(hasCycle) return {};

        vector<int> result;
        while(!st.empty()){

            result.push_back(st.top());
            st.pop();
        }

        return result;





    }
};
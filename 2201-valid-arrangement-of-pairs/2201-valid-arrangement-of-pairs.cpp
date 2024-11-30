class Solution {
public:

    vector<vector<int>> a1(vector<vector<int>>& pairs) {

        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> inDegree,outDegree;

        for(auto &pair:pairs){
            int u=pair[0];
            int v=pair[1];

            adj[u].push_back(v);
            inDegree[v]++;
            outDegree[u]++;
        }

        // Find the startNode of the Euler Path
        int startNode=pairs[0][0];

        for(auto &it:adj){
            int node=it.first;

            if(outDegree[node]-inDegree[node]==1){
                startNode=node;
                break;
            }
        }

        vector<int> EulerPath;
        
        // Doing DFS (Using Stack)
        stack<int> st;
        st.push(startNode);

        while(!st.empty()){
            
            int curr=st.top();
            if(!adj[curr].empty()){
                int ngbr=adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            } else {
                EulerPath.push_back(curr);
                st.pop();
            }
        } 

        reverse(EulerPath.begin(),EulerPath.end());

        vector<vector<int>> result;

        for(int i=0;i<EulerPath.size()-1;i++){
            result.push_back({EulerPath[i],EulerPath[i+1]});
        }
        return result;
    }
    
    //     vector<vector<int>> a1(vector<vector<int>>& pairs) {

    //     unordered_map<int,vector<int>> adj;
    //     vector<int,int> inDegree,outDegree;

    //     for(auto &pair:pairs){
    //         int u=pair[0];
    //         int v=pair[1];

    //         adj[u].push_back(v);
    //         inDegree[v]++;
    //         outDegree[u]++;
    //     }

    //     // Find the startNode of the Euler Path
    //     int startNode=pairs[0][0];

    //     for(auto &it:adj){
    //         int node=it.first;

    //         if(outDegree[node]-inDegree[node]==1){
    //             startNode=node;
    //             break;
    //         }
    //     }

    //     vector<int> EulerPath;
        
    //     // Doing DFS (Using Recursion)

    //     reverse(EulerPath.begin(),EulerPath.end());

    //     vector<vector<int>> result;

    //     for(int i=0;i<EulerPath.size()-1;i++){
    //         result.push_back({EulerPath[i],EulerPath[i+1]});
    //     }
    //     return EulerPath;
    // }
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        // APPROACH :- HEIRHODGER'S ALGORITHM
            // HERE WE ARE SOLVING USING DFS AS STACK
        return a1(pairs);
    }
};
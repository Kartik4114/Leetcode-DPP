class Solution {
public:

    void DFS(vector<int> &edges,vector<bool> &visited,vector<int> &dist,int node){
        visited[node]=true;
        
        int v=edges[node];
        if(v!=-1 && !visited[v]){
            dist[v]=1+dist[node];
            DFS(edges,visited,dist,v);
        }
    }
    int a1(vector<int>& edges, int node1, int node2) {
        
        int n=edges.size();
        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);

        vector<bool> visited1(n,false);
        vector<bool> visited2(n,false);

        dist1[node1]=0;
        dist2[node2]=0;
        
        DFS(edges,visited1,dist1,node1);
        DFS(edges,visited2,dist2,node2);

        int minDistNode=-1;
        int minDistTillNow=INT_MAX;
        
        for(int i=0;i<n;i++){

            int maxD=max(dist1[i],dist2[i]);

            if(minDistTillNow>maxD){
                minDistTillNow=maxD;
                minDistNode=i;
            }
        }

        return minDistNode;
    }

    void BFS(vector<int> &edges,vector<int> &dist,int node){
        
        int n=edges.size();
        vector<bool> visited(n,false);

        queue<int> que;
        que.push(node);
        visited[node]=true;

        while(!que.empty()){

            int front=que.front();
            que.pop();

            int v=edges[front];
            if(v!=-1 && !visited[v]){
                dist[v]=1+dist[front];
                que.push(v);
                visited[v]=true;

            }
        }
    }
    int a2(vector<int>& edges, int node1, int node2) {
        
        int n=edges.size();
        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);

        dist1[node1]=0;
        dist2[node2]=0;
        
        BFS(edges,dist1,node1);
        BFS(edges,dist2,node2);

        int minDistNode=-1;
        int minDistTillNow=INT_MAX;
        
        for(int i=0;i<n;i++){

            int maxD=max(dist1[i],dist2[i]);

            if(minDistTillNow>maxD){
                minDistTillNow=maxD;
                minDistNode=i;
            }
        }

        return minDistNode;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        // APPROACH 1:- USING DFS 
        // T.C :- O(2*n) bec as their is only one edge from each node so visiting only once
        // return a1(edges,node1,node2);

        // APPROACH 2:- USING BFS 
        // T.C :- O(2*n) bec as their is only one edge from each node so visiting only once
        return a2(edges,node1,node2);
    }
};
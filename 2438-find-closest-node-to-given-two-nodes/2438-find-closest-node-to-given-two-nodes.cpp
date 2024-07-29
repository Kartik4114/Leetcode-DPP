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
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        return a1(edges,node1,node2);
    }
};
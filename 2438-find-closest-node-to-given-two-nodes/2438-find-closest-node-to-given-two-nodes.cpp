class Solution {
public:

    void BFS(vector<int> &edge,vector<int> &dist,int node){

        int n=edge.size();

        vector<bool> visited(n,false);
        visited[node]=true;
        dist[node]=0;

        queue<int> que;
        que.push(node);

        while(!que.empty()){

            int front=que.front();
            que.pop();

            int v=edge[front];
            if(edge[front]!=-1 &&!visited[edge[front]]){
                dist[v]=1+dist[front];
                que.push(v);
                visited[v]=true;
            }
        }
        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n=edges.size();

        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);

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

        return minDistNode;

    }
};
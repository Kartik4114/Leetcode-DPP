class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);

    }

    void Union(int u,int v){

        int parent_u=find(u);
        int parent_v=find(v);

        if(parent_u==parent_v) return;

        if(rank[parent_u] > rank[parent_v]){
            parent[parent_v]=parent_u;
        }
        else if(rank[parent_u] < rank[parent_v]){
            parent[parent_u]=parent_v;
        }
        else {
            parent[parent_u]=parent_v;
            rank[parent_v]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size()<n-1) return -1;

        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        int components=n;
        for(vector<int> &vec:connections){

            if(find(vec[0])!=find(vec[1])){
                Union(vec[0],vec[1]);
                components--;
            }
        }
        return components-1;

    }
};
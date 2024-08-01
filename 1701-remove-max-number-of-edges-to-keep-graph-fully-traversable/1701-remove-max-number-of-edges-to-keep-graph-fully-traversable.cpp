class DSU{
    public:
        vector<int> parent;
        vector<int> rank;
        int components;

        DSU(int n){
            parent.resize(n+1);
            for(int i=0;i<n+1;i++){
                parent[i]=i;
            }
            rank.resize(n+1,0);
            components=n;
        }
        int find(int x){
            if(x==parent[x]) return x;

            return parent[x]=find(parent[x]);
        }
        void Union(int x,int y){
            
            int parent_x=find(x);
            int parent_y=find(y);

            if(parent_x==parent_y) return;

            if(rank[parent_x]>rank[parent_y]){
                parent[parent_y]=parent_x;
            } else if(rank[parent_y]>rank[parent_x]){
                parent[parent_x]=parent_y;
            } else {
                parent[parent_y]=parent_x;
                rank[parent_x]++;
            }
            components--;
        }

        bool isSingleComponent(){
            return components==1;
        }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        DSU Alice(n);
        DSU Bob(n);

        // auto lambda=[&](vector<int> &v1,vector<int> &v2){
        //     return v1[0]>v2[0];
        // };
        sort(edges.begin(),edges.end(),greater<vector<int>>());

        int edgeCount=0;
        for(auto &edge:edges){

            int type=edge[0];
            int u=edge[1];
            int v=edge[2];
            
            if(type==3){
                bool edgeAdded=false;
                if(Alice.find(u)!=Alice.find(v)){
                    Alice.Union(u,v);
                    edgeAdded=true;
                }

                if(Bob.find(u)!=Bob.find(v)){
                    Bob.Union(u,v);
                    edgeAdded=true;
                }
                if(edgeAdded){
                    edgeCount++;
                }
            } else if(type==2){
                if(Bob.find(u)!=Bob.find(v)){
                    Bob.Union(u,v);
                    edgeCount++;
                }
            } else{
                if(Alice.find(u)!=Alice.find(v)){
                    Alice.Union(u,v);
                    edgeCount++;
                }
            }
        }

        // cout<<edgeCount<<endl;
        if(Alice.isSingleComponent() && Bob.isSingleComponent()){
            return edges.size()-edgeCount;
        }
        return -1;
    }
};
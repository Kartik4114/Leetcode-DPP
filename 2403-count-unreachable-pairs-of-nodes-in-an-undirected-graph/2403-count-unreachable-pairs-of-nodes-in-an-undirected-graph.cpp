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

        if(rank[parent_u] < rank[parent_v]){
            parent[parent_u]=parent_v;
        }
        else if(rank[parent_u] > rank[parent_v]){
            parent[parent_v]=parent_u;
        }
        else {
            parent[parent_u]=parent_v;
            rank[parent_v]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto &vec:edges){
                Union(vec[0],vec[1]);
        }

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int papaji=find(i);
            mp[papaji]++;
        }

        long long size=n;
        long long result=0;
        for(auto it:mp){
            result+= (long long)it.second*(size-it.second);
            size-=it.second;
        }

        return result;
    }
};
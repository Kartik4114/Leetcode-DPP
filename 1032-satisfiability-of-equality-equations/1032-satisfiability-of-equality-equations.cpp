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
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        parent.resize(26);
        rank.resize(26,0);

        for(int i=0;i<26;i++){
            parent[i]=i;
            // rank[i]=1;
        }

        for(string &s:equations){
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a');
            }
        }

        for(string &s: equations){
            if(s[1]=='!'){
                int parent_x=find(s[0]-'a');
                int parent_y=find(s[3]-'a');

                if(parent_x==parent_y){
                    return false;
                }
            }
        }
        return true;
    }
};
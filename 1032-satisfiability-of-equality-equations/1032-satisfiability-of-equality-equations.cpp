class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){

        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){

        int parentX=find(x);
        int parentY=find(y);

        if(parentX==parentY) return;

        if(rank[parentX]>rank[parentY]){
            parent[parentY]=parentX;
        } else if(rank[parentY]>rank[parentX]){
            parent[parentX]=parentY;
        } else {
            parent[parentY]=parentX;
            rank[parentX]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        
        parent.resize(26);
        rank.resize(26,0);

        for(int i=0;i<26;i++){
            parent[i]=i;
        }

        for(auto &eq:equations){

            if(eq[1]=='='){
                Union(eq[0]-'a',eq[3]-'a');
            }
        }

        for(auto &eq:equations){

            if(eq[1]=='!'){
                
                char parentOf0=find(eq[0]-'a');
                char parentOf3=find(eq[3]-'a');

                if(parentOf0==parentOf3){
                    return false;
                }
            }
        }

        return true;
    }
};
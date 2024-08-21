class Solution {
public:
    vector<int> parent;
    vector<int> rank;

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
    }
    bool equationsPossible(vector<string>& s) {
        
        parent.resize(26);
        rank.resize(26,0);
        int n=s.size();

        for(int i=0;i<26;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){
            
            if(s[i][1]=='='){
                Union(s[i][0]-'a',s[i][3]-'a');
            }
        }

        for(int i=0;i<n;i++){
            if(s[i][1]=='!'){
                
                int parentOf0=find(s[i][0]-'a');
                int parentOf3=find(s[i][3]-'a');

                if(parentOf0==parentOf3){
                    return false;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int px=find(x);
        int py=find(y);

        if(px!=py){
            parent[py]=px;
        }
    }
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {

        int n=circles.size();
        parent.resize(n+2);
        for(int i=0;i<n+2;i++){
            parent[i]=i;
        }
        
        // n-> origin and n+1 is top-right corner
        for(int i=0;i<n;i++){
            
            long x=circles[i][0];
            long y=circles[i][1];
            long r=circles[i][2];

            if(x-r<=0 || y+r>=Y){
                Union(n,i);
            }

            if(x+r>=X || y-r<=0){
                Union(n+1,i);
            }

            // Intersecting circle
            for(int j=0;j<i;j++){

                long x2=circles[j][0];
                long y2=circles[j][1];
                long r2=circles[j][2];

                if(((x-x2)*(x-x2)+(y-y2)*(y-y2))<=((r+r2)*(r+r2))){
                    Union(i,j);
                }
            }
        }

        int parentOrigin=find(n);
        int parentTarget=find(n+1);

        if(parentOrigin==parentTarget) return false;
        return true;
    }
};
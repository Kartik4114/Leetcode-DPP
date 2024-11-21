class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> vec(m,vector<int>(n,0));

        for(auto &wall:walls){

            int x=wall[0];
            int y=wall[1];
            
            vec[x][y]=2;
        }
        for(auto &guard:guards){

            int x=guard[0];
            int y=guard[1];
            
            vec[x][y]=2;
        }


        for(auto &guard:guards){
            int u=guard[0];
            int v=guard[1];

            for(int j=v+1;j<n;j++){
                if(vec[u][j]==2) break;
                vec[u][j]=1;
            }
            for(int j=v-1;j>=0;j--){
                if(vec[u][j]==2) break;
                vec[u][j]=1;
            }

            for(int i=u+1;i<m;i++){
                if(vec[i][v]==2) break;
                vec[i][v]=1;
            }

            for(int i=u-1;i>=0;i--){
                if(vec[i][v]==2) break;
                vec[i][v]=1;
            }
        }

        int result=0;

        for(auto &row:vec){
            for(auto &cell:row){
                
                if(cell==0)
                result++;
            }
        }
        return result;
        
    }
};
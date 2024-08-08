class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> result(n,vector<int>(n));

        int cnt=1;

        int top=0;
        int down=n-1;
        int left=0;
        int right=n-1;

        int dir=0;
        while(cnt<=n*n){

            if(dir==0){
                for(int i=left;i<=right;i++){
                    result[top][i]=cnt;
                    cnt++;
                }
                top++;
            }

            if(dir==1){
                for(int i=top;i<=down;i++){
                    result[i][right]=cnt;
                    cnt++;
                }
                right--;
            }

            if(dir==2){
                for(int i=right;i>=left;i--){
                    result[down][i]=cnt;
                    cnt++;
                }
                down--;
            }

            if(dir==3){
                for(int i=down;i>=top;i--){
                    result[i][left]=cnt;
                    cnt++;
                }
                left++;
            }
            dir=(dir+1)%4;
        }

        return result;
    }
};
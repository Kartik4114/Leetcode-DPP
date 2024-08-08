class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        int top=0;
        int left=0;
        int right=n-1;
        int down=m-1;

        vector<int> result;
        int dir=0;
        while(result.size()<m*n){

            if(dir==0){
                for(int i=left;i<=right;i++){
                    result.push_back(matrix[top][i]);
                }
                top++;
            }

            if(dir==1){
                for(int j=top;j<=down;j++){
                    result.push_back(matrix[j][right]);
                }
                right--;
            }

            if(dir==2){
                for(int i=right;i>=left;i--){
                    result.push_back(matrix[down][i]);
                }
                down--;
            }

            if(dir==3){
                for(int j=down;j>=top;j--){
                    result.push_back(matrix[j][left]);
                }
                left++;
            }

            dir=(dir+1)%4;
        }
        return result;
    }
};
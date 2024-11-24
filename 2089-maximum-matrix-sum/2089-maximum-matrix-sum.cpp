class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();

        long long sum=0;
        int cntNegNum=0;

        int minNum=INT_MAX;
        bool isMinNumNeg=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);
                minNum=min(minNum,abs(matrix[i][j]));

                if(minNum<0) isMinNumNeg=true;
                else isMinNumNeg=false;

                if(matrix[i][j]<0) cntNegNum++;
            }
        }

        cout<<sum<<endl;
        cout<<cntNegNum<<endl;
        cout<<minNum<<endl;
        if(cntNegNum&1) {
            return sum-abs(minNum)-minNum;
        }
        return sum;
    }
};
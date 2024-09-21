class Solution {
public:
    int minimumOneBitOperations(int n) {
        
        if(n==0) return 0;

        vector<long long> F(31,0);
        // here f[i] denotes no.of operations for F[i]  to convert to zero
        // i==0 means 0th bit is set
        F[0]=1;
        for(int i=1;i<=30;i++){
            F[i]=2*F[i-1]+1;
        }

        int bitCnt=0;

        int result=0;
        int sign=0;
        
        for(int i=30;i>=0;i--){
            
            if(n& (1<<i)){
                sign==0 ? result+=F[i] : result-=F[i];
                sign =1-sign;
            }
        }
        return result;
    }
};
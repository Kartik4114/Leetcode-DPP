class Solution {
public:
    int kthFactor(int n, int k) {
        
        int factorCnt=0;
        int factorAns=-1;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                factorCnt++;
                factorAns=i;
            }
            if(factorCnt==k) break;
        }

        return factorCnt<k ? -1 : factorAns;
    }
};
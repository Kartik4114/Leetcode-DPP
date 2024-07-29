class Solution {
public:
    int seive(int l,int r){

        int n=r;
        vector<int> primes(n+1,1);

        for(int i=2;i*i<=n;i++){

            if(primes[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    primes[j]=0;
                }
            }
        }

        int specialCnt=0;
        for(int i=l;i<=n;i++){
            if(i>=2 && primes[i]==1){
                specialCnt++;
            }
        }
        return specialCnt;


    }
    int nonSpecialCount(int l, int r) {
        
        int sqrtl=sqrt(l);
        int sqrtr=sqrt(r);

        if(sqrtl*sqrtl!=l) sqrtl++;
        int specialCnt=seive(sqrtl,sqrtr);

        return (r-l+1)-specialCnt;
    }
};
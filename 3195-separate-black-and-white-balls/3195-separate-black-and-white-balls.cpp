class Solution {
public:
    typedef long long ll;
     long long minimumSteps(string s) {
        
        int n=s.size();

        ll swaps=0;

        int i=n-1;
        int j=n-1;
        while(i>=0 && s[i]=='1') i--;

        if(i<=0) return 0;

        j=i;

        ll cntOne=0;
        while(i>=0){
            
            // int cntZero=0;
            while(i>=0 && s[i]=='0'){
                i--;
                // cntZero++;
            } 

            ll cntOne=0;
            while(i>=0 && s[i]=='1'){
                i--;
                cntOne++;
            } 
            
            ll cntZero=j-(cntOne+i);
            swaps+=cntOne*cntZero;
            j-=cntOne;

            if(i<=0) break;
        }
        return swaps;
    }
};
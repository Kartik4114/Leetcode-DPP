class Solution {
public:
    bool isUgly(int n) {
        
        if(n<=0) return false;
        long long count=0;
        while(n>1){

            if(n%2==0){
                n=n/2;
                count=0;
            }
            else count++;

            if(n%3==0){
                n=n/3;
                count=0;
            }
            else count++;

            if(n%5==0){
                n=n/5;
                count=0;
            }
            else count++;

            // if(count==0) break;
            if(count>=3) return false;
        }

        return true;
    }
};
class Solution {
public:
    bool a1(int n){
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
            if(count>=3) return false;
        }

        return true;
    }

    bool a2(int n){
        if(n<=0) return false;

        while(n%2==0) n=n/2;
        while(n%3==0) n=n/3;
        while(n%5==0) n=n/5;

        return n==1;
    }
    bool isUgly(int n) {
        
        // APPROACH 1:- 
        // return a1(n);

        // APPROACH 2:- 
        return a2(n);
    }
};
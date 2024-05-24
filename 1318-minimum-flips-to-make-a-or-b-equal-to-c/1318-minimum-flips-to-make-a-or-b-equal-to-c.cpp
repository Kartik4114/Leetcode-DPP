class Solution {
public:
    int a1(int a,int b,int c){
        int flips=0;

        while(a!=0 || b!=0 || c!=0){
            
            if(c&1){
                if((a&1)==0 && (b&1)==0) flips++;
            } else{
                if(a&1) flips++;
                if(b&1) flips++;
            }

            a>>=1;
            b>>=1;
            c>>=1;
        }
        return flips;
    }
    int a2(int a,int b,int c){

        int result=(a|b) ^c; // to check no. of flips but it is not complete so
                            // we have to do and also

        
        int result1=(a&b); // to check if both bits are 1
        int result2=(result & result1);

        return __builtin_popcount(result) + __builtin_popcount(result2);

        
    }
    int minFlips(int a, int b, int c) {
        
        // APPROACH 1:- by counting no. of flips
        // T.C:- O(n) ,S.C:- O(1)
        // return a1(a,b,c);

        // APPROACH 2:- NICE APPROACH
        // T.C:- O(1) ,S.C:- O(1) 

        return a2(a,b,c);

        

    }
};
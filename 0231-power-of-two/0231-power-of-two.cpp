class Solution {
public:
    bool a1(int n){
            double ans=log2(n);
            if(ans==0) return true;

            int ans1=log2(n);

            if(ans/ans1==1) return true;
            else return false;

    }
    bool isPowerOfTwo(int n) {
        
        if(n<=0) {
            return false;
        }
        // APPROACH 1 (USING LOG), TC:- O(1)
        // return a1(n); 

    //    APPROACH 2 USING BUILT-IN FUNCTION , TC:- O(logn)
        int count=__builtin_popcount(n);
        if(count==1) return true;
        else return false;

    // APPROACH 3:- BIT MAGIC
    // as we know that 4 i.e.(100) and 3 i.e.(011) their and will always be zero so

        return (n&(n-1))==0;
    
    // APPROACH 4:- Aree bhai-bhai approach :- TC:- O(1)
    // only tell when interviewer asks
    // As in constraint it is written that 2^31 -1
    // so we cant take  2^30

    int ans=pow(2,30);
    return ans%n==0;



        

    }
};
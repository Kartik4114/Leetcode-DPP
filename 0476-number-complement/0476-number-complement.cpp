class Solution {
public:
    int a1(int num){

        int numBits=(int)(log2(num))+1;

        for(int i=0;i<numBits;i++){
            num=(num^(1<<i));
        }
        return num;
    }

    int a2(int num){

        int numBits=(int)log2(num)+1;

        unsigned int mask=(1U << numBits)-1; // using simple int is giving overflow integer

        return (mask^num);
    }
    int findComplement(int num) {

        //Approach-1 (Using bit magic of XOR)
        //T.C : O(log2(num)) // BEC. FOR LOOP IS RUNNING LOGN TIMES
        //S.C : O(1)
        // return a1(num);

        //Approach-2 (Using XOR mask)
        //T.C : O(log2(num))
        //S.C : O(1)
        return a2(num);

        // APPROACH 3:- 
    }
};
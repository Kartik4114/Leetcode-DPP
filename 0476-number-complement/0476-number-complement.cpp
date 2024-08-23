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

    int a3(int num){
        int i=0;
        int compliment=0;

        while(num>0){
            int bit=num&1;
            // If the current bit is 0, set the corresponding bit in ans to 1
            if(bit==0){
                compliment |= 1<<i;
            }

            i++;
            num>>=1;
        }
        return compliment;
    }
    int findComplement(int num) {

        //Approach-1 (Using bit magic of XOR)
        //T.C : O(log2(num)) // BEC. FOR LOOP IS RUNNING LOGN TIMES
        //S.C : O(1)
        // return a1(num);

        //Approach-2 (Using XOR mask)
        //T.C : O(log2(num))
        //S.C : O(1)
        // return a2(num);

        // Approach-3 (Iterate digit by digit and create complement)
        // T.C : O(log2(num))
        // S.C : O(1)
        return a3(num);


    }
};
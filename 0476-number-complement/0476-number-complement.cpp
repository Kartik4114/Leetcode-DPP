class Solution {
public:
    int a1(int num){

        int numBits=(int)(log2(num))+1;

        for(int i=0;i<numBits;i++){
            num=(num^(1<<i));
        }
        return num;
    }
    int findComplement(int num) {
        // APPROACH 1:- USING XOR
        return a1(num);
    }
};
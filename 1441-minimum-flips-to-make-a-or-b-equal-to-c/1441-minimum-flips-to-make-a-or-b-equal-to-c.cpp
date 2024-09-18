class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int flips=0;
        while(c>0 || a>0 || b>0){

            if((c&1)==0){
                flips+=(a&1) + (b&1);
            } else {

                if((a&1)==0 && (b&1)==0) flips+=1;
            }

            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return flips;
    }
};
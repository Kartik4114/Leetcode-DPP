class Solution {
public:
    int findClosest(int x, int y, int z) {
        
        int x1=abs(z-x);
        int x2=abs(y-z);

        if(x1<x2){
            return 1;
        } else if(x1==x2) return 0;

        return 2;
    }
};
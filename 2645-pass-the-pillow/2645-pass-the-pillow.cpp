class Solution {
public:
    int a1(int n,int time){

        int idx=1;
        int dir=1;

        while(time>0){
            if(idx+dir>=1 && idx+dir<=n){
                idx+=dir;
                time--;
            } else dir=-dir;
        }
        return idx;
    }
    int passThePillow(int n, int time) {
        
        // APPROACH 1:- DO AS QUESTION SAY
        // T.C :- O(n) 
        return a1(n,time);
    }
};
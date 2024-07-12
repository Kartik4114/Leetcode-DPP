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

    int a2(int n,int time){

        int fullRound=time/(n-1);
        int timeLeft=time%(n-1);

        if(fullRound%2==0){
            return timeLeft+1;
        } else return n-timeLeft;

    }
    int passThePillow(int n, int time) {
        
        // APPROACH 1:- DO AS QUESTION SAY
        // T.C :- O(n) 
        // return a1(n,time);

        // APPROACH 2: USING MATHS
        // T.C :- O(1)
        return a2(n,time);
    }
};
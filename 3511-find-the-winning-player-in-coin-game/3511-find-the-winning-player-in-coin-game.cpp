class Solution {
public:
    string losingPlayer(int x, int y) {
        
        
        int mini=min(x,y/4);

        if(mini%2==1) return "Alice";
        else return "Bob";
    }
};
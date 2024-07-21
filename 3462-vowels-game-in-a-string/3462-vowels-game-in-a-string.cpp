class Solution {
public:
    bool doesAliceWin(string s) {
        
        int vowelCnt=0;
        for(auto &ch:s){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                vowelCnt++;
            }
        }

        if(vowelCnt==0) return false;
        else return true;
    }
};
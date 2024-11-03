class Solution {
public:
    bool a1(string &s,string &goal){

        int m=s.size();
        int n=goal.size();

        if(m!=n) return false;

        for(int i=1;i<=n;i++){
            rotate(s.begin(),s.begin()+1,s.end());
            if(s==goal) return true;
        }
        return false;
    }
    // bool a2(string &s,string &goal){
        
    // }
    bool rotateString(string s, string goal) {
        
        // APPROACH 1:- BRUTE FORCE APPROACH (USING C++ STL)
        return a1(s,goal);


    }
};
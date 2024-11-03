class Solution {
public:
    bool a1(string &s,string &goal){

        int m=s.size();
        int n=goal.size();

        if(m!=n) return false;

        for(int i=1;i<=n;i++){
            if(s==goal) return true;

            rotate(s.begin(),s.begin()+1,s.end());
        }
        return false;
    }
    bool a2(string &s,string &goal){
        
        string temp=s;
        temp+=s;

        int m=s.size();
        int n=goal.size();

        if(m!=n) return false;

        if(temp.find(goal)!=string::npos) return true;

        return false;
    }
    bool rotateString(string s, string goal) {
        
        // APPROACH 1:- BRUTE FORCE APPROACH (USING C++ STL)
        // T.C :- O(n^2) , S.C :- O(n)
        // return a1(s,goal);

        // APPROACH 2:- OPTIMISED APPROACH
        // T.C :- O(N) , S.C :- O(2*N)
        return a2(s,goal); 


    }
};
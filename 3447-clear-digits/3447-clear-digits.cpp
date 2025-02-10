class Solution {
public:
    string a1(string &s){

        // int n=s.size(); // Don't do this because s.length() is changing every time 

        int i=0;
        while(i<s.size()){
            if(isdigit(s[i])){
                s.erase(i,1);
                
                if(i>=0){
                    s.erase(i-1,1);
                }
                i--;
            } else i++;
        }
        return s;

    }
    string clearDigits(string s) {
        
        // APPROACH 1:- BRUTE FORCE APPROACH
        return a1(s);
    }
};
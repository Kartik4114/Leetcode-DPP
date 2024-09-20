class Solution {
public:
    string a1(string &s){
        int n=s.size();

        string revStr=s;
        reverse(revStr.begin(),revStr.end());

        int i;
        for(i=0;i<n;i++){
            
            if(s.substr(0,n-i)==revStr.substr(i)){
                break;
            }
        }

        string result=revStr.substr(0,i) +s;
        return result;
    }

    string a2(string &s){
        int n=s.size();

        string revStr=s;
        reverse(revStr.begin(),revStr.end());

        for(int i=0;i<n;i++){

            if(memcmp(s.c_str(),revStr.c_str()+i,n-i)==0){
                return revStr.substr(0,i) +s;
            }
        }
        return revStr+s;
    }
    string shortestPalindrome(string s) {
        
        // APPROACH 1:- USING SIMPLE APPROACH (MEMORY LIMIT EXCEEDED)
        // IT IS GIVING MLE BEC. substr function every time create string in tempory function
        // T.C :- O(n^2) // bec. every time in for loop we are calling substr function
        // S.C :- O(n) 
        // return a1(s);

        // APPROACH 2:- USING MEMCMP FUNCTION
        // MEMCMP func. doesn't use extra variable like substr but it has pointer to actual string
        // and it returns 0 if condition is true
        return a2(s);
    }
};
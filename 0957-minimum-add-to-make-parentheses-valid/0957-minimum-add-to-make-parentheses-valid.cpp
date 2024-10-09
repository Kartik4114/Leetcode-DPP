class Solution {
public:
    int a1(string &s){

        stack<char> st;

        for(auto &ch:s){

            if(!st.empty() && st.top()=='(' && ch==')')
                st.pop();
            else st.push(ch);
        }

        return st.size();
    }

    int a2(string &s){

        int openCnt=0;
        int closeCnt=0;

        for(auto &ch:s){

            if(ch=='(') openCnt++;
            else {
                if(openCnt>0) openCnt--;
                else closeCnt++;
            }
        }

        return openCnt+closeCnt;
    }
    int minAddToMakeValid(string s) {
        
        // approach 1:- using stack (T.C :- O(n) , S.C :- O(n))
        // return a1(s);

        // Approach 2:-
        return a2(s);
    }
};
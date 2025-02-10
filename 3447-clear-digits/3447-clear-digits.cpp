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

    string a2(string &s){

        int n=s.size();
        stack<char> st;

        for(auto &ch:s){

            if(!st.empty() && isdigit(ch)){
                st.pop();
            } else {
                st.push(ch);
            }
        }

        string result="";
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }

        reverse(result.begin(),result.end());
        return result;
    }
    string clearDigits(string s) {
        
        // APPROACH 1:- BRUTE FORCE APPROACH
        // T.C :- O(n^2)
        // return a1(s);

        // APPROACH 2:- USING STACK
        // T.C :- O(n) , S.C :- O(n)
        return a2(s);


    }
};
class Solution {
public:
    string a1(string s){
         stack<int> st;
        queue<int> que;

        int n=s.size();

        for(int i=0;i<n;i++){

            if(s[i]!=')'){
                st.push(s[i]);
            }
            else{
                while(!st.empty() && st.top()!='('){
                    que.push(st.top());
                    st.pop();
                }
                st.pop();

                while(!que.empty()){
                    st.push(que.front());
                    que.pop();
                }
            }
        }
        string result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
    string a2(string s){
        
        // here we are storing where openBracket is and then reversing the string 
        // front open bracket till end
        stack<int> lastSkipLength; // storing count of openBracket
        int n=s.size();
        

        string result="";
        for(int i=0;i<n;i++){

            if(s[i]=='('){
                lastSkipLength.push(result.length());
            }
            else if(s[i]==')'){
                int l=lastSkipLength.top();
                reverse(result.begin()+l,result.end());
                lastSkipLength.pop();
            } 
            else {
                result+=s[i];
            }
        }
        return result;
    }
    string a3(string s){

        int n=s.size();
        stack<int> openBracketIdx;
        vector<int> door(n);

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                openBracketIdx.push(i);
            }

            else if(s[i]==')'){
                int j=openBracketIdx.top();
                openBracketIdx.pop();
                door[i]=j;
                door[j]=i;
            }
        }

        string result;
        int flag=1;
        for(int i=0;i<n;i+=flag){

            if(s[i]=='(' || s[i]==')'){
                i=door[i];
                flag=-flag;
            } else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
    string reverseParentheses(string s) {
        
        // APPROACH 1:- MY APPROACH (LITTLE LENGTHY) USING STACK
        // T.C :- O(n^2) , S.C :- O(N)
        // return a1(s);

        // APPROACH 2:- BETTER APPROACH USING STACK
        // T.C :- O(n^2) , S.C :- O(N)
        // return a2(s);

        // APPROACH 1:-OPTIMISED APPROACH (IMP.)
        // T.C :- O(n) , S.C :- O(N)
        return a3(s);
    }
};
class Solution {
public:
    string reverseParentheses(string s) {
        
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
};
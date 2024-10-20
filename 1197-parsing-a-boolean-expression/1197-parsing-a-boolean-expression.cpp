class Solution {
public:
    bool parseBoolExpr(string expression) {
        
        // T.C :- O(2*n) , S.C :- O(n)

        stack<char> st; // stack for storing other element
        stack<char> operation; // stack for operator 

        for(auto &ch:expression){
            
            if(ch=='&' || ch=='|' || ch=='!') {
                operation.push(ch);
            } else {

                if(ch==')'){
                    char op=operation.top();

                    int falseCnt=0; // for checking
                    int trueCnt=0;

                    while(!st.empty() && st.top()!='('){
                        if(st.top()=='f') falseCnt++;
                        if(st.top()=='t') trueCnt++;
                        st.pop();
                    }

                    if(!st.empty()) st.pop();
                    if(!operation.empty()) operation.pop();

                    if(op=='|') {
                        if(trueCnt>0) st.push('t');
                        else st.push('f');
                    } else if(op=='&') {
                        if(falseCnt>0) st.push('f');
                        else st.push('t');
                    } else {
                        if(falseCnt>0) st.push('t');
                        else st.push('f');
                    }
                } else {
                    st.push(ch);
                }
            }
        }

        return st.top()=='t';
    }
};
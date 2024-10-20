class Solution {
public:
    bool parseBoolExpr(string expression) {
        
        stack<char> st;
        stack<char> operation;

        for(auto &ch:expression){
            
            if(ch=='&' || ch=='|' || ch=='!') {
                operation.push(ch);
            } else {

                if(ch==')'){
                    char op=operation.top();

                    int falseCnt=0;
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

        // cout<<st.top()<<endl;
        if(st.top()=='t') return true;
        return false; 
    }
};
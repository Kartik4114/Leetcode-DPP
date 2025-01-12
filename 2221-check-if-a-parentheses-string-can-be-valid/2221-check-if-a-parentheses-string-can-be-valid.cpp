class Solution {
public:
    bool a1(string &s,string &locked){
        
        int n=s.size();
        if(n&1) return false;

        stack<int> open;
        stack<int> openClose;

        for(int i=0;i<n;i++){
            
            if(locked[i]=='0') {
                openClose.push(i);
            } else if(s[i]=='('){
                open.push(i);
            } else  {

                if(!open.empty()){
                    open.pop();
                } else if(!openClose.empty()){
                    openClose.pop();
                } else return false;
            }
        }

        while(!open.empty() && !openClose.empty() && open.top()<openClose.top()){
            open.pop();
            openClose.pop();
        }

        return open.empty();
    }
    bool a2(string &s,string &locked){
        
        int n=s.size();

        if(n&1) return false;

        int open=0;
        for(int i=0;i<n;i++){

            if(s[i]=='('){
                open++;
            } else if(locked[i]=='0') open++;
            else open--;

            if(open<0) return false;
        }

        int close=0;
        for(int i=n-1;i>=0;i--){

            if(s[i]==')'){
                close++;
            } else if(locked[i]=='0') close++;
            else close--;

            if(close<0) return false;
        }

        return true;
    }
    bool canBeValid(string s, string locked) {
        
        // APPROACH 1:- USING STACKS
        // T.C :- O(n), S.C :- O(n)
        // return a1(s,locked);

        // APPROACH 1:- USING STACKS
        // T.C :- O(n), S.C :- O(1)
        return a2(s,locked);


    }
};
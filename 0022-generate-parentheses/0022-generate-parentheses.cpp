class Solution {
public:
    void helper(int n,string &s,vector<string> &temp){

        if(s.size()==2*n){
            int cnt=0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='('){
                    cnt++;
                } else cnt--;

                if(cnt<0) break;
            }

            if(cnt==0){
                temp.push_back(s);
            }  
            return; 
        }

        s.push_back('(');
        helper(n,s,temp);
        s.pop_back();

        s.push_back(')');
        helper(n,s,temp);
        s.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> temp;
        string s="";

        helper(n,s,temp);
        return temp;
    }
};
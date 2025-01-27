class Solution {
public:
    vector<string> result;
    void helper(int n,string &temp,int open,int close){

        if(temp.size()==2*n){
            result.push_back(temp);
        }

        if(open<n){
            temp.push_back('(');
            helper(n,temp,open+1,close);
            temp.pop_back();
        }

        if(close<open){
            temp.push_back(')');
            helper(n,temp,open,close+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        
        string temp="";
        helper(n,temp,0,0);

        return result;
    }
};
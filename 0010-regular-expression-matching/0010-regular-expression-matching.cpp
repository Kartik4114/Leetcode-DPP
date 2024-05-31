class Solution {
public:
    bool a1(string s,string p){

        if(p.length()==0){
            return s.length()==0;
        }

        bool first_char_matched=false;

        if(s.length()>0 && (p[0]==s[0] || p[0]=='.')){
            first_char_matched=true;
        }

        if(p[1]=='*'){

            bool not_take=a1(s,p.substr(2));
            bool take=first_char_matched && a1(s.substr(1),p);

            return not_take || take;
        }

        return first_char_matched && a1(s.substr(1),p.substr(1));
    }

    int memo[21][21];
    bool a2(string s,string p,int i,int j){

        if(j==p.length()){
            return i==s.length();
        }

        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        bool first_char_matched=false;

        if(i<s.length() && (p[j]==s[i] || p[j]=='.')){
            first_char_matched=true;
        }

        if(p[j+1]=='*'){

            bool not_take=a2(s,p,i,j+2);
            bool take=first_char_matched && a2(s,p,i+1,j);

            return memo[i][j]= not_take || take;
        }

        return memo[i][j]=first_char_matched && a2(s,p,i+1,j+1);
    }

    bool isMatch(string s, string p) {
        
        // APPROACH 1:- 
        // here it will give TLE bec. we are using substr st every time 
        //  so we can do it by using i and j pointer
        // t.c :- O(2^n) , S.C = max(s.size(),p.size());
        // return a1(s,p);

        // APPROACH 2:- USING i and j pointer
        // here we are doing memoization also
        memset(memo,-1,sizeof(memo));
        return a2(s,p,0,0);
    }
};
class Solution {
public:
    
    string a1(string &s,string &part){

        int n=part.length();
        while(true){

            int idx=s.find(part);

            if(idx == string::npos){
                break;
            }

            s.erase(idx,n);
        }

        return s;
    }

    bool check(stack<char> &st,string &part){
        
        int n=part.size();

        auto tempSt=st;
        for(int idx=n-1;idx>=0;idx--){
            if(tempSt.top()!=part[idx]){
                return false;
            }
            tempSt.pop();
        }
        return true;
    }
    string a2(string &s,string &part){

        int m=s.size();
        int n=part.size();

        stack<char> st;

        for(int i=0;i<m;i++){

            st.push(s[i]);

            if(st.size()>=n && check(st,part)==true){
                for(int j=0;j<n;j++){
                    st.pop();
                }
            }
        }

        string result="";

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(),result.end());
        return result;

    }

    string a3(string &s,string &part){

        int n=part.size();
        string result="";

        for(auto &ch:s){

            result.push_back(ch);

            if(result.length()>=n && result.substr(result.length()-n)==part){
                result.erase(result.length()-n);
            }
        }
        return result;
    }
    string removeOccurrences(string s, string part) {
        
        // APPROACH 1:- Brute Force Approach
        // T.C :- O(m*n)
        // return a1(s,part);

        // APPROACH 2:- Using Stack 
        // T.C :- O(m*n)
        // return a2(s,part);

        // APPROACH 3:- Using string as stack
        // T.C :- O(m*n)
        return a3(s,part);
    }
};
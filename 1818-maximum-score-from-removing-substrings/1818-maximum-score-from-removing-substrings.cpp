class Solution {
public:
    string removeSubstr_a1(string &s,string &matchStr){

        stack<char> st;
        for(auto ch:s){
            if(ch==matchStr[1] && !st.empty() && st.top()==matchStr[0]){
                st.pop();
            } else st.push(ch);
        }

        string temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }

        reverse(temp.begin(),temp.end());
        return temp;
    }
    int a1(string s,int x,int y){
        int n=s.length();
        int score=0;

        string maxStr= (x>y) ? "ab" : "ba";
        string minStr= (x<y) ? "ab" : "ba";

        // first pass

        string temp_first=removeSubstr_a1(s,maxStr);
        int L=temp_first.length();

        int charRemoved=n-L;
        score+=(charRemoved/2)*max(x,y);

        string temp_second=removeSubstr_a1(temp_first,minStr);
        charRemoved=L-temp_second.length();
        
        score+=(charRemoved/2)*min(x,y);

        return score;
    }

    string removeSubstr_a2(string &s,string &matchStr){
        
        int n=s.size();
        int i=0; // used for writing purpose

        for(int j=0;j<n;j++){
            s[i]=s[j];
            i++;

            if(i>=2 && s[i-2]==matchStr[0] && s[i-1]==matchStr[1]){
                i-=2;
            }
        }

        s.erase(s.begin()+i,s.end());
        return s;
    }

    int a2(string s,int x,int y){
        int n=s.length();
        int score=0;

        string maxStr= (x>y) ? "ab" : "ba";
        string minStr= (x<y) ? "ab" : "ba";

        // first pass

        string temp_first=removeSubstr_a2(s,maxStr);
        int L=temp_first.length();

        int charRemoved=n-L;
        score+=(charRemoved/2)*max(x,y);

        string temp_second=removeSubstr_a2(temp_first,minStr);
        charRemoved=L-temp_second.length();
        
        score+=(charRemoved/2)*min(x,y);

        return score;
    }
    int maximumGain(string s, int x, int y) {
        
        // APPROACH 1:- USING STACKS
        // T.C :- O(N) , S.C :- O(N)
        // return a1(s,x,y);

         // APPROACH 2:- USING TWO POINTERS (MOST OPTIMISED APPROACH)
        // T.C :- O(N) , S.C :- O(N)
        return a2(s,x,y);

    }
};
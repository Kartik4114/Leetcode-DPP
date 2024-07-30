class Solution {
public:
    int a1(string s){
        int n=s.size();
        stack<char> st;

        int cnt=0;
        for(int i=0;i<n;i++){

            if(!st.empty() && st.top()=='b' && s[i]=='a'){
                st.pop();
                cnt++;
            }
            else st.push(s[i]);
        }
        return cnt;
    }
    int minimumDeletions(string s) {
        
        // Approach 1:- using stacks
        // Here we don't want which to delete we just have to increase the count
        return a1(s);
    }
};
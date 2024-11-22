class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.size();

        set<char> st;

        int i=0;
        int j=0;
        int maxLen=0;

        while(j<n){

            while(i<n && st.find(s[j])!=st.end()){
                // cout<<i<<endl;
                st.erase(s[i]);
                i++;
            }
            // cout<<i<<endl;

            st.insert(s[j]);
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};
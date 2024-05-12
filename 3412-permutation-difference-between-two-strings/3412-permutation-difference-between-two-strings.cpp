class Solution {
public:
    int findPermutationDifference(string s, string t) {
        
        int n=s.size();
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        
        for(int i=0;i<n;i++){
            mp1[s[i]]=i;
            mp2[t[i]]=i;
        }
        
        int diff=0;
        for(auto ch:s){
            diff+=abs(mp2[ch]-mp1[ch]);
        }
        
        return diff;
    }
};
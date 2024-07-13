class Solution {
public:
    string getEncryptedString(string s, int k) {
        
        string result="";
        
        int n=s.size();
        for(int i=0;i<s.size();i++){
            int idx=(i+k)%n;
            result+= s[idx];
        }
        return result;
    }
};
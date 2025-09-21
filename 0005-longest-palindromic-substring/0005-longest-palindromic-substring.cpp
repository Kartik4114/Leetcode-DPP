class Solution {
public:
    bool solve(string &s,int i,int j){

        int n=s.size();

        if(i>=j) return true;

        if(s[i]==s[j]){
            return solve(s,i+1,j-1);
        }
        return false;
    }
    string longestPalindrome(string s) {
        
        int n=s.size();

        int maxLen=INT_MIN;
        int sp=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){

                if(solve(s,i,j)==true){
                    if(j-i+1>maxLen){
                        maxLen=max(maxLen,j-i+1);
                        sp=i;
                    }
                }
            }
        }

        return s.substr(sp,maxLen);
    }
};
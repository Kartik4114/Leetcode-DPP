class Solution {
public:
    string smallestPalindrome(string s) {
        
        int n=s.size();
        string result=s;

        sort(result.begin(),result.begin()+n/2);

        if(n&1)
        sort(result.begin()+n/2+1,result.end(),greater<char>());
        else 
        sort(result.begin()+n/2,result.end(),greater<char>());

        return result;

    }
};
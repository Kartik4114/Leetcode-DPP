class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;

        for(auto ch:s){
            mp[ch]++;
        }

        int cnt=0;
        for(auto it:mp){
            if(it.second%2==0){
                cnt+=it.second;
            } else {
                cnt+=it.second-1;
            }
        }

        if(cnt!=s.size()) return cnt+1;
        return cnt;
    }
};
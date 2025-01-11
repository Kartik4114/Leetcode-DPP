class Solution {
public:
    bool canConstruct(string s, int k) {
        
        int n=s.size();
        if(k>n) return false;

        map<char,int> mp;
        for(auto &ch:s){
            mp[ch]++;
        }

        int oddCnt=0;
        for(auto &it:mp){
            if(it.second%2==1) oddCnt++;
        }

        if(oddCnt<=k) return true;
        return false;
    }
};
class Solution {
public:
    int minimumLength(string s) {
                unordered_map<char,int> mp;
        int n=s.size();
        
        for(auto &ch:s){
            
            mp[ch]++;
        }
        
        int maxCnt=0;
        
        for(auto &it: mp){
            
            int toDelete=it.second;
            if(toDelete%2==0){
                maxCnt+=(toDelete-2);
            } else {
                maxCnt+=(toDelete-1);
            }
        }
        
        return n-maxCnt;
    }
};
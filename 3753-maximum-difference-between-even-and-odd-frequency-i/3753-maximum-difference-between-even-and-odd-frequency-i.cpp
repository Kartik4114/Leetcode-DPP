class Solution {
public:
    int maxDifference(string s) {
        
        int n=s.size();
        
        map<char,int> mp;
        
        for(auto &ch:s){
            mp[ch]++;
        }
        
        int minEven=INT_MAX;
        int maxOdd=-1;
        
        for(auto &it:mp){
            
            if(it.second&1){
                maxOdd=max(maxOdd,it.second);
            } else {
                minEven=min(minEven,it.second);
            }
        }
        
        return maxOdd-minEven;
    }
};
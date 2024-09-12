class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        unordered_set<char> st(allowed.begin(),allowed.end());

        int cnt=0;
        for(auto &word:words){

            bool isPresent=true;
            for(auto &ch:word){
                if(st.find(ch)==st.end()){
                    isPresent=false;
                    break;
                }
            }
            if(isPresent) cnt++;
        }

        return cnt;
    }
};
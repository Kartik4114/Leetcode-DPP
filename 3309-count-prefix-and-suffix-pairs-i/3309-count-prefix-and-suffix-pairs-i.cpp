class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        
        int count=0;
        
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                
                if(words[j].length()>=words[i].length()){
                    
                    string pre=words[j].substr(0,words[i].length());
                    string suf=words[j].substr(words[j].length()-words[i].length(),words[j].length());
                    
                    if(words[i]==pre && words[i]==suf) count++;
                }
            }
                
        }
        
        return count;
        
    }
};
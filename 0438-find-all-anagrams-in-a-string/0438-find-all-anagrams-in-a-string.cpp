class Solution {
public:
    bool allZeroCounter(vector<int> &counter){

        for(auto &c:counter){
            if(c!=0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        
        int n=s.size();

        vector<int> counter(26,0);
        vector<int> result;

        for(auto &ch:p) counter[ch-'a']++;

        int i=0,j=0;

        while(j<n) {

            counter[s[j]-'a']--;
            
            if(j-i+1==p.size()){
                if(allZeroCounter(counter)){
                    result.push_back(i);
                }

                counter[s[i]-'a']++;
                i++;
            }

            j++;
        }

        return result;
    }
};
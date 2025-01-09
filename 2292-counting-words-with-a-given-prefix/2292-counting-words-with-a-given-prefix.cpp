class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int n=words.size();

        int count=0;

        for(auto &word:words){

            if(pref.size()<=word.size()){
                
                bool check=true;
                for(int i=0;i<pref.size();i++){
                    if(pref[i]!=word[i]){
                        check=false;
                        break;
                    }
                }

                if(check) count++;
            }
        }

        return count;
    }
};
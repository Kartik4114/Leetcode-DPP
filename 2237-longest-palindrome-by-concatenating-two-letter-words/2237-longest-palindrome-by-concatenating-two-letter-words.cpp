class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        int n=words.size();

        unordered_map<string,int> mp;

        for(auto &word:words){
            mp[word]++;
        }

        int result=0;

        for(auto &word:words){

            if(word[0]!=word[1]){

                string s="";
                s+=word[1];
                s+=word[0];

                if(mp[s]>0 && mp[word]>0){ 
                    result+=2;
                    mp[word]--;
                    mp[s]--;
                }
            }
        }

        int checkOddCnt=false;

        for(auto &it:mp){
        
        string s=it.first;
            if(s[0]==s[1]){
                if(it.second%2==0){
                    result+=it.second;
                } else {
                    result+=it.second-1;
                    checkOddCnt=true;
                }
            }
        }

        if(checkOddCnt) result++;

        return result*2;
    }
};
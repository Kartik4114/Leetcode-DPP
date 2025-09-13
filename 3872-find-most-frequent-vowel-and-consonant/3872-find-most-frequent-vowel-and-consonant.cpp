class Solution {
public:
    int maxFreqSum(string s) {
        
        vector<int> alpha(26,0);

        for(auto &ch:s){

            alpha[ch-'a']++;
        }

        int maxCntVowel=0;
        int maxCntCons=0;

        for(int i=0;i<26;i++){

            char ch=i+'a';

            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                maxCntVowel=max(maxCntVowel,alpha[i]);
            } else {
                maxCntCons=max(maxCntCons,alpha[i]);
            }
        }

        return maxCntVowel+maxCntCons;
    }
};
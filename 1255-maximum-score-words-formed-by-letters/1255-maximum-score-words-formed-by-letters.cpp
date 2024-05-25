class Solution {
public:
    int n;
    int maxScore;

    void solve(vector<string>& words, vector<int>& freq, vector<int>& score,int i, int currScore){

        if(i>=n){
            maxScore=max(maxScore,currScore); // this line we can write outside also
            return;
        }

        // condition for taking the word
        int j=0;
        int tempScore=0;
        vector<int> tempFreq=freq;

        while(j<words[i].size()){
            char ch=words[i][j];
            tempFreq[ch-'a']--;
            tempScore+=score[ch-'a'];

            if(tempFreq[ch-'a']<0){ // this means that letter is not present so we can't take word
                break;
            }
            j++;
        }
        if(j==words[i].size()){ // take condition
            solve(words,tempFreq,score,i+1,tempScore+currScore);
        }

        // not take
        solve(words,freq,score,i+1,currScore);

    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        // solving this problem using backracking

        // T.C:- O(2^n *L) (L=length of word) , S.C:- O(n)
        n=words.size();
        maxScore=INT_MIN;

        vector<int> freq(26,0);

        for(auto ch:letters){
            freq[ch-'a']++;
        }

        solve(words,freq,score,0,0);
        return maxScore;

    }
};
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        int n=searchWord.size();
        stringstream ss(sentence);

        vector<string> words;

        string temp="";
        while(getline(ss,temp,' ')){
            words.push_back(temp);
        }

        for(int i=0;i<words.size();i++){
            
            string word=words[i];
            if(word.size()>=n){
                string toCompare=word.substr(0,n);
                if(toCompare==searchWord) return i+1;
            }
        }

        return -1;
    }
};
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        
        int n=words.size();

        vector<int> result;
        for(int i=0;i<n;i++){

            auto word=words[i];

            set<int> st(word.begin(),word.end());

            if(st.find(x)!=st.end()){
                result.push_back(i);
            }
        }

        return result;
    }
};
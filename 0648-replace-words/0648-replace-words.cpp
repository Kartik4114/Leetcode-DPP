class Solution {
public:
    string root(unordered_set<string> &st,string &word){

        for(int l=0;l<word.size();l++){

            string root=word.substr(0,l);
            if(st.count(root)){
                return root;
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        int n=sentence.size();
        unordered_set<string> st;

        for(auto &s:dictionary){
            st.insert(s);
        }

        stringstream ss(sentence);
        string word;

        string result;
        while(getline(ss,word,' ')){

            result+=root(st,word)+" ";
        }
        result.pop_back();

        return result;
    }
};
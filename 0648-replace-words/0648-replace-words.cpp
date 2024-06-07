class Solution {
public:
    string findRoot(unordered_set<string> &st,string &word){

        for(int l=0;l<word.size();l++){ // O(l*l)
            string root=word.substr(0,l); // O(l)

            if(st.count(root)) return root;
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        //T.C : o(n*l + m*l^2) , n = number of words in the dictionary,
        //  m be the number of words in the sentence, 
        // and l be the average length of each word.

        //S.C : O(n*l)
        
        int n=dictionary.size();

        unordered_set<string> st; // O(w*l)
        for(auto &s: dictionary){
            st.insert(s);
        }

        stringstream ss(sentence);
        string word;

        string result;

        while(getline(ss,word,' ')){ // O(w*l*l)
            result+=findRoot(st,word)+" ";
        }

        result.pop_back();
        return result;
    }
};
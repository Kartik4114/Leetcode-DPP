class Solution {
public:
    bool isVowel(string word){
        
        char ch1=word[0];
        char ch2=word[word.length()-1];

        bool check1=false;
        bool check2=false;
        if(ch1=='a' || ch1=='e' || ch1=='i' || ch1=='o' || ch1=='u'){
            check1=true;
        }

        if(ch2=='a' || ch2=='e' || ch2=='i' || ch2=='o' || ch2=='u'){
            check2=true;
        }

        return check1 && check2;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n=words.size();

        vector<int> temp(n,0);

        for(int i=0;i<n;i++){
            
            string word=words[i];
            if(isVowel(word)) {
                temp[i]=1;
            }

            if(i>0){
                temp[i]+=temp[i-1];
            }
        }

        vector<int> result;

        for(auto &query:queries){

            int start=query[0];
            int end=query[1];

            if(start-1>=0){
                
                int total=temp[end]-temp[start-1];
                result.push_back(total);
            } else {
                result.push_back(temp[end]);
            }
        }

        return result;




    }
};
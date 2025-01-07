class Solution {
public:
    vector<string> a1(vector<string> &words){

        int n=words.size();
        vector<string> result;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(i==j) continue;

                if(words[j].find(words[i])!=string::npos){
                    result.push_back(words[i]);
                    break;
                }
            }
        }

        return result;
    }
    vector<string> stringMatching(vector<string>& words) {
        
        // APPROACH 1:- 
        // T.C :- O(n^2*m) , S.C :- O(1)
        return a1(words);

        // APPROACH 2:- USING KMP 
        // T.C :- O(n^2*m) , S.C :- O(1)
        // return a2(words);


    }
};
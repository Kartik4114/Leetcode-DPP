class Solution {
public:
    string a1(string &word,int numFriends){

        int n=word.size();

        if(numFriends==1) return word;
        
        string result;
        int largestPossible=n-(numFriends-1);

        for(int i=0;i<n;i++){

            int canTake=min(largestPossible,n-i);
            result=max(result,word.substr(i,canTake));
        }

        return result;
    }
    string answerString(string word, int numFriends) {
        
        // APPROACH 1:- USING BRUTE FORCE APPROACH
        // T.C :- O(n^2) , S.C :- O(1)
        return a1(word,numFriends);

        // APPROACH 2:- MOST OPTIMISED APPROACH
        // T.C :- O(n) , S.C :- O(n)
        // return a2(word,numFriends);
        
    }
};
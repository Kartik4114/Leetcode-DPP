class Solution {
public:
    string answerString(string word, int numFriends) {
        
        int n=word.size();
        if(numFriends==1) return word;

        int windowSize=n-(numFriends-1);

        string result;
        for(int i=0;i<n;i++){

            int largestPossibleSize=min(windowSize,n-i);

            string currStr=word.substr(i,largestPossibleSize);
            result=max(result,currStr);
        }

        return result;
    }
};
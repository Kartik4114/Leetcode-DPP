class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        int n=sentence.size();
        bool check=true;

        for(int i=0;i<n;i++){
            
            char ch=sentence[i];
            
            if(ch==' '){

                char prevCh=sentence[i-1];
                char nextCh=sentence[i+1];

                if(prevCh!=nextCh){
                    check=false;
                    break;
                }
            }
        }

        return (sentence[0]==sentence[n-1]) && check;
    }
};
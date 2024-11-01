class Solution {
public:
    string makeFancyString(string s) {
        
        int n=s.size();
        string result="";

        int consCnt=0;
        for(int i=0;i<n;i++){
            
            if(result.size()>0){
                char ch=result.back();
                if(ch==s[i]) consCnt++;
                else consCnt=1;
            } else consCnt=1;

            if(consCnt>2) continue;
            result+=s[i]; 
        }
        return result;

    }
};
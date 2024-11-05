class Solution {
public:
    string compressedString(string word) {
        
        int n=word.size();
        string comp="";

        int i=0;
        while(i<n){

            int cnt=0;
            int ch=word[i];
            while(i<n && word[i]==ch && cnt<9){
                cnt++;
                i++;
            }
            comp+=to_string(cnt);
            comp+= ch;
        }
        return comp;
    }
};
class Solution {
public:
    string compressedString(string word) {
        
        int n=word.size();
        string result="";

        int i=0;
        while(i<n){

            int cnt=1;
            while( i+1<n && word[i]==word[i+1] && cnt<9){
                cnt++;
                // cout<<"In"<<endl;
                i++;
            }
            // cout<<"out"<<endl;
            result+=to_string(cnt);
            result+=word[i];
            i++;
        }
        return result;
    }
};
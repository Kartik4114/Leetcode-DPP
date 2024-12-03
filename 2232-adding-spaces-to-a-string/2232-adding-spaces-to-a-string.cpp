class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        int m=s.length();
        int n=spaces.size();

        string result="";

        int j=0;
        for(int i=0;i<m;i++){
            if(j<n && spaces[j]==i){
                result+=' ';
                j++;
            }
            result+=s[i];

        }
        return result;

    }
};
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        int n=spaces.size();
        int len=s.size();

        for(int i=0;i<n;i++){
            spaces[i]+=i;
        }

        set<int> st(spaces.begin(),spaces.end());

        string result="";

        int j=0;
        for(int i=0;i<len+n;i++){

            if(st.find(i)!=st.end()){
                result+=' ';
                continue;
            } 
            result+=s[j];
            j++;
        }


        return result;
    }
};
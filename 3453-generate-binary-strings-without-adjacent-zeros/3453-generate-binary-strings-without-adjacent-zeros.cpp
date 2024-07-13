class Solution {
public:
    vector<string> ans;
    void generateString(string s, int n ,int last){
        if(n<=0){
            ans.push_back(s);
            return;
        }

        if(last==1){
            generateString(s+"1",n-1,1);
            generateString(s+"0",n-1,0);
        }

        else {
            generateString(s+"1",n-1,1);
        }
    }
    vector<string> validStrings(int n) {
        
        generateString("0",n-1,0);
        generateString("1",n-1,1);
        return ans;
    }
};
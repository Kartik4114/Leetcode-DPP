class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        int n=part.length();
        while(true){

            int idx=s.find(part);

            if(idx == string::npos){
                break;
            }

            s.erase(idx,n);
        }

        return s;
    }
};
class Solution {
public:
    bool isValid(string s) {
        
        // MOST OPTIMMISED APPROACH 
        // here we have to keep two pointers of i and j 
        // i for writing and j for reading

        int i=0;
        int n=s.size();
        for(int j=0;j<n;j++){
            
            s[i]=s[j];
            i++;

            if(i>=3 && s[i-3]=='a' && s[i-2]=='b' && s[i-1]=='c'){
                i-=3;
            }
        }

        s.erase(s.begin()+i,s.end());
        if(s.size()==0) return true;
        else return false;
    }
};
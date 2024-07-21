class Solution {
public:
    int maxOperations(string s) {
        
        int n=s.size();
        
        int cntZero=0;
        for(auto &ch:s){
            if(ch=='0') cntZero++;
        }
        
        int i=0;
        int j=0;
        
        int result=0;
        int cntOne=0;
        while(i<n && j<n){
            
            if(s[i]=='1' && i<n-1) j=i;
            
            if(s[j]=='1'){
                while(j<n && s[j]=='1'){
                    j++;
                    
                }
                cntOne+=j-i;
                if(cntZero>0){
                    result+=cntOne;
                }
                i=j;
            }
            if(s[i]=='0') cntZero--;
            
            i++;
            
        }
        return result;
    }
};
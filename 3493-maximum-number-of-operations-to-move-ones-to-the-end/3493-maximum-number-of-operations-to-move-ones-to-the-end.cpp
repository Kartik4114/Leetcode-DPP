class Solution {
public:
    int a1(string s){
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

    int a2(string s){
        
        int n=s.size();
        reverse(s.begin(),s.end());

        int startIndex=n;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                startIndex=i;
                break;
            }
        }

        int impact=1;
        int ans=0;
        int j=-1;
        for(int i=startIndex;i<n;i++){
            if(s[i]=='0') continue;
            int cntOne=0;

            for(j=i;j<n;j++){
                if(s[j]=='0') break;
                cntOne++;
            }

            ans+=(cntOne*impact);
            impact++;
            i=j;
        }
        return ans;

    }
    int maxOperations(string s) {
        
        // APPROACH 1:- USING TWO POINTERS
        // return a1(s);

        // APPROACH 2:- 
        return a2(s);
    }
};
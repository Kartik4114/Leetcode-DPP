class Solution {
public:
    int a1(string s,int k){
        int n = s.size();
        
        int totalCnt = 0;
        for(int i = 0; i < n; i++){
            int cntOne = 0;
            int cntZero = 0;
            for(int j = i; j < n; j++){
                
                if(s[j] == '1') cntOne++;
                else cntZero++;
                
                if(cntOne <= k || cntZero <= k) totalCnt++;
                else break;
            }
        }
        
        return totalCnt;
    }

    int a2(string s,int k){
        
        int n=s.size();
        
        int result=0;

        int cntZero=0;
        int cntOne=0;

        int i=0,j=0;
        while(j<n){

            if(s[j]=='0') cntZero++;
            else cntOne++;

            while(cntZero>k && cntOne>k){
                if(s[i]=='0') cntZero--;
                else cntOne--;
                i++;
            }

            result+=(j-i+1);
            j++;
        }
        return result;
    }
    int countKConstraintSubstrings(string s, int k) {
        
        // APPROACH 1:- USING BRUTE FORCE APPROACH
        // return a1(s,k);

        // APPROACH 2:- USING SLIDING WINDOW 
        return a2(s,k);
    }
};

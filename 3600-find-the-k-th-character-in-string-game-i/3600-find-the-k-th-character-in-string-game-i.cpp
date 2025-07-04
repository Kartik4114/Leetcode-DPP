class Solution {
public:
    char kthCharacter(int k) {
        
        char ch='a';
        
        
        while(k>1){
            
            int strLen=1;
            
            for(;strLen<(k+1)/2;strLen*=2);
            
            k-=strLen;
            
            if(ch=='z') ch='a';
            else ch=ch+1;
        }
        
        return ch;
    }
};
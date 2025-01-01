class Solution {
public:
    int maxScore(string s) {
        
        int n=s.size();
        int cntZero=0;
        int cntOne=0;

        for(auto &ch:s){
            if(ch=='1') cntOne++;
        }

        int maxSum=0;

        for(int i=0;i<n-1;i++){
            
            char ch=s[i];
            if(ch=='0'){
                cntZero++;
            } else cntOne--;

            maxSum=max(maxSum,cntZero+cntOne);
        }
        return maxSum;
    }
};
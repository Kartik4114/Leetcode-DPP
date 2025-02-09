class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        int n=s1.size();

        int cnt=0;
        int i=-1;
        int j=-1;

        for(int k=0;k<n;k++){

            if(s1[k]!=s2[k]){

                cnt++;
                if(i==-1){
                    i=k;
                } else if(j==-1){
                    j=k;
                }
            }
        }

        if(cnt==0) return true;
        if(cnt==2 && s1[i]==s2[j] && s1[j]==s2[i]) return true;
        return false;

    }
};
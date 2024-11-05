class Solution {
public:
    int minChanges(string s) {
        
        int n=s.size();

        int i=0;

        int totalChanges=0;
        while(i<n){
            
            char ch=s[i];
            int cnt=0;
            while(i<n && ch==s[i]){
                cnt++;
                i++;
            }
            if(cnt & 1){
                totalChanges++;
                i++;
            }

        }
        return totalChanges;
    }
};
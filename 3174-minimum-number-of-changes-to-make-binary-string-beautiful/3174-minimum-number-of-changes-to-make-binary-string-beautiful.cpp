class Solution {
public:
    int a1(string &s){
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

    int a2(string &s){

        int n=s.size();
        int minChanges=0;
        for(int i=0;i<n;i+=2){
            if(s[i]!=s[i+1]) minChanges++;
        }
        return minChanges;

    }
    int minChanges(string s) {
        
        // approach 1:- 
        // T.C :- O(n) , S.C :- O(1)

        // return a1(s);

        // approach 2:- very simple
        // T.C :- O(n) , S.C :- O(1)

        return a2(s);
    }
};
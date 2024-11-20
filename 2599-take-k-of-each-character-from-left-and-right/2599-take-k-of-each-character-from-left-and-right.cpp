class Solution {
public:
    int result=INT_MAX;
    void solve(string &s,int k,int i,int j,int minutes,vector<int> &freq){

        if(freq[0]>=k && freq[1]>=k && freq[2]>=k) {
            result=min(result,minutes);
            return;
        }
        if(i>j) return;

        // Option 1:- Delete from left
        freq[s[i]-'a']++;
        solve(s,k,i+1,j,minutes+1,freq);
        freq[s[i]-'a']--;

        freq[s[j] - 'a']++;
        solve(s,k,i,j-1,minutes+1,freq);
        freq[s[j] - 'a']--;
    }
    int a1(string &s,int k){

        int n=s.size();

        int i=0;
        int j=n-1;   
        int minutes=0;

        vector<int> freq(3,0);

        solve(s,k,i,j,minutes,freq);
        return result==INT_MAX ? -1 : result;
    }
    
    int a2(string &s,int k){

        int n=s.size();

        vector<int> freq(3,0);
        for(auto &ch:s) freq[ch-'a']++;

        for(auto &f:freq){
            if(f<k) return -1;
        }

        int i=0;
        int j=0;

        int delWindowSize=0;
        while(j<n) {
            
            freq[s[j]-'a']--;

            while(i<=j && freq[s[j]-'a']<k){
                freq[s[i]-'a']++;
                i++;
            }

            delWindowSize=max(delWindowSize,j-i+1);
            j++;
        }
        return n-delWindowSize;
    }
    int takeCharacters(string s, int k) {
        
        // APPROACH 1:- BRUTE FORCE APPROACH (USING RECURSION)
        // T.L.E :- O(2^n)
        // return a1(s,k);

        // APPROACH 2:- USING SLIDING WINDOW APPROACH
        return a2(s,k);
        
    }
};
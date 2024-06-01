class Solution {
public:
    vector<vector<string>> result;

    bool isPalindrome(string s,int idx,int i){

        while(idx<=i){
            if(s[idx]!=s[i]) return false;
            idx++;
            i--;
        }
        return true;
    }

    void helper(string &s,vector<string> &temp,int idx){
        int n=s.size();
        if(idx>=n){
            result.push_back(temp);
            return;
        }

        for(int i=idx;i<n;i++){
            
            if(isPalindrome(s,idx,i)){

                temp.push_back(s.substr(idx,i-idx+1));
                helper(s,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        // T.C :- O(n*2^n) , S.C:- O(n) auxillary space
        vector<string> temp;
        helper(s,temp,0);
        return result;
    }
};
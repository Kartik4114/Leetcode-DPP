class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        set<int> st(arr.begin(),arr.end());

        int cntZero=0;
        for(auto &a:arr) if(a==0) cntZero++;

        for(auto &a:arr){

            if(a==0 && cntZero==1) continue;
            if(st.find(2*a)!=st.end()) return true;
        }

        return false;
    }
};
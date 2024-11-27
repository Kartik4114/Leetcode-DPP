class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        // using technique that no. can only be in [1,n] so using indexes as numbers

        int maxEl=*max_element(arr.begin(),arr.end());
        
        set<int> st(arr.begin(),arr.end());
        
        for(int i=1;i<=maxEl;i++){
            
            if(st.find(i)==st.end()) return i;
        }
        
        if(maxEl<=0) return 1;
        return maxEl+1;
    }
};
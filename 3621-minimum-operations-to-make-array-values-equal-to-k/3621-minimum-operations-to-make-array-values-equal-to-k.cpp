class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int minEl=*min_element(nums.begin(),nums.end());
        
        if(k>minEl) return -1;
        
        set<int> st(nums.begin(),nums.end());
        st.insert(k);
        
        return st.size()-1;
    }
};
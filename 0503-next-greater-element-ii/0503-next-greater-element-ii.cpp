class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> temp=nums;
        stack<int> st;

        for(auto &num:nums) temp.push_back(num);
        vector<int> result(n,-1);

        for(int i=2*n-1;i>=0;i--){

            while(!st.empty() && st.top()<=temp[i]) {
                st.pop();
            }

            if(!st.empty()) result[i%n]=st.top();
            st.push(temp[i]);
        }

        return result;

    }
};
class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        
        int n=values.size();

        set<int> st;

        int i=0;
        long long ans=0;
        while(i>=0 && i<n && st.find(i)==st.end()){

            st.insert(i);
            if(instructions[i]=="add"){
                ans+=values[i];
                i++;
            } else {
                i=i+values[i];
            }

        }

        return ans;
    }
};
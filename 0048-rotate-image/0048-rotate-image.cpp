class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();

        stack<vector<int>> st;

        for(int i=0;i<m;i++){
            
            if(i%2==0){
                for(int j=0;j<n;j++){
                    st.push({i,j,matrix[i][j]});
                }
            } else {
                for(int j=n-1;j>=0;j--){
                    st.push({i,j,matrix[i][j]});
                }
            }
        }


        while(!st.empty()){

            auto top=st.top();
            st.pop();

            int i=top[0];
            int j=top[1];
            int val=top[2];

            matrix[j][n-i-1]=val;
        }
    }
};
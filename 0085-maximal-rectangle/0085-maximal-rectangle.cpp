class Solution {
public:
    vector<int> getNSL(vector<int> &height){

        int n=height.size();
        stack<int> st;

        vector<int> result(n,-1);

        for(int i=0;i<n;i++){

            if(st.empty()){
                result[i]=-1;
            } else {

                while(!st.empty() && height[st.top()]>=height[i]){
                    st.pop();
                }
                if(!st.empty()){
                    result[i]=st.top();
                } else {
                    result[i]=-1;
                }
            }
            st.push(i);
        }

        return result; 
    }

        vector<int> getNSR(vector<int> &height){

        int n=height.size();
        stack<int> st;

        vector<int> result(n,n);

        for(int i=n-1;i>=0;i--){

            if(st.empty()){
                result[i]=n;
            } else {

                while(!st.empty() && height[st.top()]>=height[i]){
                    st.pop();
                }
                if(!st.empty()){
                    result[i]=st.top();
                } else {
                    result[i]=n;
                }
            }
            st.push(i);
        }

        return result; 
    }

    int findMaxArea(vector<int> &height){

        int n=height.size();

        vector<int> NSL=getNSL(height);
        vector<int> NSR=getNSR(height);

        int maxArea=0;

        for(int i=0;i<n;i++){

            int width=NSR[i]-NSL[i]-1;
            maxArea=max(maxArea,width*height[i]);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();


        vector<int> heights(n,0);

        int maxArea=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(matrix[i][j]=='0'){
                    heights[j]=0;
                } else {
                    heights[j]+=1;
                }
            }

            maxArea=max(maxArea,findMaxArea(heights));
        }

        return maxArea;

    }
};
class Solution {
public:
    vector<int> getPSE(vector<int> &arr){

        int n=arr.size();
        stack<int> st;

        vector<int> result(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                result[i]=-1;
            } else {

                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }

                result[i]= st.empty() ? -1 : st.top();
            }
            st.push(i);
        }

        return result;
    }
    vector<int> getNSE(vector<int> &arr){

        int n=arr.size();
        stack<int> st;

        vector<int> result(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                result[i]=n;
            } else {

                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }

                result[i]= st.empty() ? n : st.top();
            }
            st.push(i);
        }

        return result;
    }
    int a1(vector<int> &heights){

        int n=heights.size();

        vector<int> NSE=getNSE(heights);
        vector<int> PSE=getPSE(heights);

        int maxi=-1;
        for(int i=0;i<n;i++){

            int currVal=heights[i]*(NSE[i]-PSE[i]-1);
            maxi=max(maxi,currVal);
        }

        return maxi;
    }

    // int a2(vector<int> &arr){
        
    // }
    int largestRectangleArea(vector<int>& heights) {
        
        // APPROACH 1:- It is a two pass solution
        // T.C :- O(n) , S.C :-O(n)
        return a1(heights);

        // APPROACH 2:- It is a one pass solution (MOST OPTIMISED)
        // T.C := O(2*n) , S.C :- 
        // return a2(heights);
    }
};
class Solution {
public:
    vector<int> a1(vector<int> &prices){
        int n=prices.size();
        vector<int> result;

        for(int i=0;i<n;i++){

            int currPrice=prices[i];

            for(int j=i+1;j<n;j++){
                if(prices[j]<=prices[i]){
                    currPrice-=prices[j];
                    break;
                }
            }
            result.push_back(currPrice);
        }

        return result;
    }

    vector<int> a2(vector<int> &prices){

        int n=prices.size();

        stack<int> st;
        vector<int> result=prices;
        for(int i=0;i<n;i++){

            while(!st.empty() && prices[i]<=prices[st.top()]){
                result[st.top()]-=prices[i];
                st.pop();
            }

            st.push(i);
        }

        return result;
    }
    vector<int> finalPrices(vector<int>& prices) {
        
        // APPROACH 1:- BRUTE FORCE APPROACH
        // return a1(prices);

        // APPROACH 2:- OPTIMISED APPROACH (MONOTONIC STACK)
        return a2(prices);
    }
};
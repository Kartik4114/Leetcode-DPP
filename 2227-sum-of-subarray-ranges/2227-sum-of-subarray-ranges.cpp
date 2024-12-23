class Solution {
public:
    long long a1(vector<int> &nums){

        int n=nums.size();
        long long ans=0;

        for(int i=0;i<n;i++){

            int largest=nums[i];
            int smallest=nums[i];
            for(int j=i+1;j<n;j++){

                largest=max(nums[j],largest);
                smallest=min(nums[j],smallest);

                ans+=(largest-smallest);
            }
        }

        return ans;
    }

    vector<int> getNSL(vector<int> &nums){
        int n=nums.size();

        stack<int> st;
        vector<int> result(n);

        for(int i=0;i<n;i++){

            if(st.empty()){
                result[i]=-1;
            } else {

                while(!st.empty() && nums[st.top()]>=nums[i]){
                    st.pop();
                }

                result[i]= st.empty() ? -1 : st.top();
            }
            st.push(i);

        }
        return result; 
    }

    vector<int> getNSR(vector<int> &nums){
        int n=nums.size();

        stack<int> st;
        vector<int> result(n);

        for(int i=n-1;i>=0;i--){

            if(st.empty()){
                result[i]=n;
            } else {

                while(!st.empty() && nums[st.top()]>nums[i]){
                    st.pop();
                }

                result[i]= st.empty() ? n : st.top();
            }
            st.push(i);

        }
        return result; 
    }
    long subArrayMin(vector<int> &nums){

        int n=nums.size();

        vector<int> NSL=getNSL(nums);
        vector<int> NSR=getNSR(nums);

        long long result=0;
        for(int i=0;i<n;i++){

            long long ls=i-NSL[i];
            long long rs=NSR[i]-i;

            long long totalWays=ls*rs;
            long long totalSum=nums[i]*totalWays;

            result+=totalSum;
        }

        return result;
    }

    vector<int> getNLR(vector<int> &nums){
        int n=nums.size();

        stack<int> st;
        vector<int> result(n);

        for(int i=n-1;i>=0;i--){

            if(st.empty()){
                result[i]=n;
            } else {

                while(!st.empty() && nums[st.top()]<nums[i]){
                    st.pop();
                }

                result[i]= st.empty() ? n : st.top();
            }
            st.push(i);

        }
        return result; 
    }

    vector<int> getNLL(vector<int> &nums){
        int n=nums.size();

        stack<int> st;
        vector<int> result(n);

        for(int i=0;i<n;i++){

            if(st.empty()){
                result[i]=-1;
            } else {

                while(!st.empty() && nums[st.top()]<=nums[i]){
                    st.pop();
                }

                result[i]= st.empty() ? -1 : st.top();
            }
            st.push(i);

        }
        return result; 
    }
    long subArrayMax(vector<int> &nums){

        int n=nums.size();

        vector<int> NLL=getNLL(nums);
        vector<int> NLR=getNLR(nums);

        long long result=0;
        for(int i=0;i<n;i++){

            long long ls=i-NLL[i];
            long long rs=NLR[i]-i;

            long long totalWays=ls*rs;
            long long totalSum=nums[i]*totalWays;

            result+=totalSum;
        }

        return result;
    }
    long long a2(vector<int> &nums){

        int n=nums.size();

        long long largestRange=subArrayMax(nums);
        long long smallestRange=subArrayMin(nums);

        return largestRange - smallestRange;

    }
    long long subArrayRanges(vector<int>& nums) {
        
        // APPROACH 1:- BRUTE FORCE APPROACH 
        // T.C :- O(n^2) , S.C :- O(1)
        // return a1(nums);

        // APPROACH 2:- OPTIMISED APPROACH
        return a2(nums);
    }
};
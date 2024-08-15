class Solution {
public:
    int a1(vector<int> &nums,int k){
         vector<int> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff=abs(nums[i]-nums[j]);
                v.push_back(diff);    
            }
        }

        sort(v.begin(),v.end());

        return v[k-1];
    }
    int a2(vector<int> &nums,int k){
        int n=nums.size();
        int maxElement=*max_element(nums.begin(),nums.end());

        vector<int> vec(maxElement+1,0);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                int diff=abs(nums[j]-nums[i]);
                vec[diff]++;
            }
        }

        for(int i=0;i<vec.size();i++){

            k-=vec[i];
            if(k<=0) return i;
        }
        return -1;
    }

    int a3(vector<int> &nums,int k){

        int n=nums.size();
        vector<int> vec;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                int diff=abs(nums[i]-nums[j]);
                vec.push_back(diff);
            }
        }

        nth_element(vec.begin(),vec.begin()+k-1,vec.end());
        return vec[k-1];
    }

    int slidingWindow(vector<int> &nums,int dist){

        int pairCount=0;
        int i=0;
        int j=1;
        int n=nums.size();

        while(j<n){

            while(nums[j]-nums[i]>dist){
                i++;
            }
            pairCount+=(j-i);
            j++;
        }
        return pairCount;
    }
    int a4(vector<int> &nums,int k){

        int n=nums.size();
        sort(nums.begin(),nums.end());

        int l=0;
        int r=nums[n-1]-nums[0];

        int result=0;
       while(l<=r){
            int mid=(l+r)/2;

            int countPairs=slidingWindow(nums,mid);
            if(countPairs<k){
                l=mid+1;
            } else {
                result=mid;
                r=mid-1;
            }
       }
       return result;

    }
    int smallestDistancePair(vector<int>& nums, int k) {
        
        // APPROACH 1:- O(n^2logn)  TLE
        // will give TLE

        // return a1(nums,k);

        // APPROACH 2:- 
        // T.C :- O(n^2+maxElement) , S.C :- O(maxElement);
        // Remember in this case O(n^2) is passing bec. contraint is 10^4 which is
        // borderline case in n^2 T.C and here computation are also less that's why it is passing
        // this constraint
        
        // return a2(nums,k);

        // APPROACH 3:- nth element approach
        // valid only for C ++ users

        // Avg. T.C :- O(n) , Worst T.C :- O(n^2)
        // Remember it will still take more time
        // return a3(nums,k); 

        // APPROACH 4:- USING SLIDING WINDOW + BINARY SEARCH
        return a4(nums,k);
    }
};
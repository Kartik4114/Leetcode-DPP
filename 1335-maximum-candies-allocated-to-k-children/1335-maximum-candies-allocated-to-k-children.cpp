class Solution {
public:
    int a1(vector<int>& candies, long long k){

        int n=candies.size();
        
        int maxC=0;
        for(int i=0;i<n;i++){
            maxC=max(maxC,candies[i]);
        }

        for(int c=maxC;c>=1;c--){
            long long count=0;

            for(int i=0;i<n;i++){
                count+=candies[i]/c;
            }

            if(count>=k) return c;
        }
        return 0;
    }

    bool canDist(vector<int> &candies,long long mid,long long k){

        int n=candies.size();

        for(int i=0;i<n;i++){
            k-=candies[i]/mid;

            // if(k<=0) return true;
        }

        return k<=0;
    }
    int a2(vector<int> &candies,long long k){

         int n=candies.size();
        
        int maxC=0;
        for(int i=0;i<n;i++){
            maxC=max(maxC,candies[i]);
        }

        int l=1;
        int r=maxC;

        int result=0;
        while(l<=r){
            int mid= l+ (r-l)/2;

            if(canDist(candies,mid,k)){
                result=mid;
                l=mid+1;
            } else {
                r=mid-1;
            }
        }

        return result;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        
        // Approach 1:- using brute force approach
        // T.C :- O(n^maxValue) ~ O(n^2)
        // return a1(candies,k);

        // Approach 2:- using binary search
        return a2(candies,k);



        
    }
};
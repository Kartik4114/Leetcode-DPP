class Solution {
public:
    bool isPossible(int mid,vector<int> &quantities,int n) {
        
        for(auto &q:quantities){

            n-=ceil(q*1.0/mid*1.0);
            if(n<0) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        // int size=quantities.size();

        int l=1;
        int r=*max_element(quantities.begin(),quantities.end());

        int result=0;
        while(l<=r) {

            int mid= l + (r-l)/2;

            if(isPossible(mid,quantities,n)){
                result=mid;
                r=mid-1;
            } else {
                l=mid+1;
            }
        }

        return result;
    }
};
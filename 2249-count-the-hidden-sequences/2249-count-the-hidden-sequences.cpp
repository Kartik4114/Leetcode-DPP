class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        int n= differences.size();

        vector<long long> prefix(n,0);

        prefix[0]=differences[0];
        for(int i=1;i<n;i++){

            prefix[i]=prefix[i-1]+differences[i];
        }

        // int minEl=*min_element(prefix.begin(),prefix.end());
        // int maxEl=*max_element(prefix.begin(),prefix.end());

        int minEl=INT_MAX;
        int maxEl=INT_MIN;

        for(auto &p:prefix){
            minEl=min((long long)minEl,p);
            maxEl=max((long long)maxEl,p);
        }
        

        int cnt=0;
        for(int i=lower;i<=upper;i++){

            if(i+minEl>=lower && i+maxEl<=upper){
                cnt++;
            }
        }

        return cnt;
    }
};
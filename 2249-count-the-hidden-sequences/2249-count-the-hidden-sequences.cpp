class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        int n= differences.size();

        vector<long long> prefix(n,0);

        prefix[0]=differences[0];
        for(int i=1;i<n;i++){

            prefix[i]=prefix[i-1]+differences[i];
        }

        long long minEl=*min_element(prefix.begin(),prefix.end());
        long long maxEl=*max_element(prefix.begin(),prefix.end());
        

        int cnt=0;
        for(int i=lower;i<=upper;i++){

            if(i+minEl>=lower && i+maxEl<=upper){
                cnt++;
            }
        }

        return cnt;
    }
};
class Solution {
public:
    int mod=1e9+7;
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        
        ll xXora=0;
        ll xXorb=0;

        // 49th bit to nth bit
        for(ll i=49;i>=n;i--){

            bool a_ith_bit=((a>>i) & 1) > 0; // Finding the ith bit of a
            bool b_ith_bit=((b>>i) & 1) > 0; // Finding the ith bit of b

            if(a_ith_bit==true){
                xXora = (xXora ^ (1ll<<i));
            }

            if(b_ith_bit==true){
                xXorb = (xXorb ^ (1ll<<i));
            }

        }

        for(ll i=n-1;i>=0;i--){

            bool a_ith_bit=((a>>i) & 1) > 0;
            bool b_ith_bit=((b>>i) & 1) > 0;

            if(a_ith_bit==b_ith_bit){
                xXora = (xXora ^(1ll << i));
                xXorb = (xXorb ^(1ll << i));
                continue;
            }

            if(xXorb > xXora){
                xXora =(xXora ^ (1ll << i));
            } else {
                xXorb =(xXorb ^ (1ll << i));
            }
        }

        xXora=xXora % mod;
        xXorb=xXorb % mod;

        return (xXora*xXorb) %mod;
    }
};
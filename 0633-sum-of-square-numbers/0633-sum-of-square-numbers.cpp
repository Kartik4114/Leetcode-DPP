class Solution {
public:
    bool judgeSquareSum(int c) {
        
        for(long long i=0;i*i<=c;i++){

            long long a=i*i;
            long long  b=c-a;
            
            long long root=sqrt(b);
            cout<<b<<" "<<root<<endl;
            if(b==root*root) return true;
        }

        return false;
    }
};
class Solution {
public:
    bool a1(int c){
        for(long long i=0;i*i<=c;i++){

            long long a=i*i;
            long long  b=c-a;
            
            long long root=sqrt(b);
            cout<<b<<" "<<root<<endl;
            if(b==root*root) return true;
        }

        return false;
    }
    
    bool a2(int c){

        long long left=0;
        long long right= sqrt(c);

        while(left<=right){

            long currSum=left*left+right*right;

            if(currSum==c) return true;
            if(currSum<c) left++;
            else right--;
        }

        return false;
    }
    bool judgeSquareSum(int c) {
        
        // approach 1:- using maths
        // return a1(c);

        // APPROACH 2:- USING BINARY SEARCH
        return a2(c);
        
    }
};
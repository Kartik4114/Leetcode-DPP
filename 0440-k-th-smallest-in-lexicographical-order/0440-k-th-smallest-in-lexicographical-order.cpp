class Solution {
public:
    void solve(int n,int lastNum,vector<int> &result){
        if(lastNum>n) return;
        
        result.push_back(lastNum);
        for(int i=0;i<=9;i++){

            int nextNum=lastNum*10+i;
            if(nextNum<=n){
                solve(n,nextNum,result);
            }
        }
    }

    int a1(int n,int k){
        vector<int> result;

        for(int i=1;i<=9;i++){
            solve(n,i,result);
        }

        return result[k-1];
    }

    bool solve(int n,int k,long lastNum,int &count,int &result){
        if(lastNum>n) return false;

        count++;
        if(count==k){
            result=lastNum;
            return true;
        }

        for(int i=0;i<=9;i++){
            long nextNum=lastNum*10+i;
            if(nextNum>n) break;

            if(solve(n,k,nextNum,count,result)) return true;
        }
        return false;
    }
    int a2(int n,int k){
        
        int result=0;
        int count=0;
        for(int i=1;i<=9;i++){
            if(solve(n,k,i,count,result)) break;
        }
        return result;
        
    }

    int count(long curr,long next,int n){

        int countNum=0;
        while(curr<=n){

            countNum+=(next-curr);

            curr*=10;
            next*=10;
            next=min(next,long(n+1));
        }
        return countNum;
    }
    int a3(int n,int k){

        int curr=1;
        k-=1; //Since we start from the first number (1), we need k-1 more numbers

        while(k>0){
            int countNum=count(curr,curr+1,n);

            if(countNum<=k){
                curr++;
                k-=countNum;
            } else {
                curr*=10;
                k--;
            }
        }
        return curr;
    }
    int findKthNumber(int n, int k) {
        
        // APPROACH 1:- TLE + MLE
        // T.C :- O(n) , S.C :- O(n+d) d=system stack space
        // (BEC. unable to compute 10 ^9 value and store 10^9 values in result vector)
        // return a1(n,k);

        // APPROACH 2:- TLE
        // T.C :- O(n) , S.C :- O(d) d=system stack space
        // (BEC. unable to compute 10 ^9 value)
        // but for resolving MLE we are using count vector
        // return a2(n,k);

        // APPROACH 3:- MOST OPTIMISED APPROACH
        // T.C :- O((logn)*(logn))
        // S.C :- O(logn)
        return a3(n,k);
    }
};
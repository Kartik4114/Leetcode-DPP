class Solution {
public:

    int fib_helper(int n,int*arr){
        
        if(n==0){
            return 0;  
        }
        if(n==1){
            return 1;
        }
        if(arr[n]!=-1){
            return arr[n];
        }

        int a=fib_helper(n-1,arr);
        int b=fib_helper(n-2,arr);
        arr[n]=a+b;

        return arr[n];
    }
    int fib(int n) {
        int *arr=new int[n+1];
        for(int i=0;i<=n;i++){
            arr[i]=-1;
        }
        return fib_helper(n,arr);
    }
};
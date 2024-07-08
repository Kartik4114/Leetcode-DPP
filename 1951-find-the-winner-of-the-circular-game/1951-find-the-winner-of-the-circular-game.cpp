class Solution {
public:
    int a1(int n,int k){

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }

        int i=0;
        while(arr.size()>1){
            
            int m=arr.size();
            int idx=(i+k-1)%m;

            arr.erase(arr.begin()+idx);
            i=idx;
        }

        return arr[0];

    }
    int a2(int n,int k){
                    queue<int> que;
            
            for(int i=1;i<=n;i++){
                que.push(i);
            }

            while(que.size()>1){ // O(N)
                
                int deleteElementTill=k-1;
                while(deleteElementTill>0 && !que.empty()){ // O(k)

                    int front=que.front();
                    que.pop();
                    que.push(front);
                    deleteElementTill--;
                }

                que.pop();
            }

            return que.front();
    }

    int a3(int n,int k){
        if(n==1) return 0;

        int idx=a3(n-1,k);
        idx=(idx+k)%n;

        return idx;
    }
    int findTheWinner(int n, int k) {
        
        // APPROACH 1:- USING ARRAY
        // T.C :- O(N^2)
        // return a1(n,k);

        // APPROACH 2:- USING QUEUES
        // T.C :- O(n*k);
        // return a2(n,k);

        // APPROACH 3:- USING RECURSION
        return 1+a3(n,k);


    }
};
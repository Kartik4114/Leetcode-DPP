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

            while(que.size()>1){
                
                int deleteElementTill=k-1;
                while(deleteElementTill>0 && !que.empty()){

                    int front=que.front();
                    que.pop();
                    que.push(front);
                    deleteElementTill--;
                }

                que.pop();
            }

            return que.front();
    }
    int findTheWinner(int n, int k) {
        
        // APPROACH 1:- USING ARRAY
        return a1(n,k);
        // APPROACH 2:- USING QUEUES


    }
};
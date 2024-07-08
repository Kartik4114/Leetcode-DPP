class Solution {
public:
    int findTheWinner(int n, int k) {
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
};
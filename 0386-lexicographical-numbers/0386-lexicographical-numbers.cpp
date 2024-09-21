class Solution {
public:
    void solve(int n,vector<int> &result,int lastNum){
        if(lastNum>n) return;

        result.push_back(lastNum);

            for(int i=0;i<=9;i++){
                int nextNum=lastNum*10+i;
                // if(nextNum>n) return; 
                solve(n,result,nextNum);
            }

    }
    vector<int> lexicalOrder(int n) {
        
        vector<int> result;
        for(int i=1;i<=9;i++){
            solve(n,result,i);
        }
        return result;
    }
};
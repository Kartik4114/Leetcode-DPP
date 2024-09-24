class Solution {
public:
    void solve(int n,int lastNum,int idx,vector<int> &result){
        if(idx>=n) return;
        if(lastNum>n) return;
        
        result.push_back(lastNum);
        for(int i=0;i<=9;i++){

            int nextNum=lastNum*10+i;
            if(nextNum<=n){
                solve(n,nextNum,i,result);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        
        vector<int> result;
        for(int i=1;i<=9;i++){
            solve(n,i,0,result);
        }

        return result;
    }
};
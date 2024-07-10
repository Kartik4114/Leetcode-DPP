class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int cnt=0;
        int n=logs.size();
        for(int i=0;i<n;i++){
            if(logs[i]=="../"){
                if(cnt>0) cnt--;
                else continue;
            } else if(logs[i]=="./") continue;

            else cnt++;
        }

        return cnt;
    }
};
class Solution {
public:
    int a1(vector<string>& logs){

        int cnt=0;
        int n=logs.size();
        for(int i=0;i<n;i++){
            if(logs[i]=="../"){
               cnt=max(cnt,cnt-1);
            } else if(logs[i]=="./") continue;

            else cnt++;
        }

        return cnt;
    }

    int a2(vector<string> &logs){
        stack<string> st;
        int n=logs.size();

        for(int i=0;i<n;i++){

            if(logs[i]=="../" ){
                if(!st.empty()){
                    st.pop();
                }
            } else if(logs[i] == "./") continue;
            else st.push(logs[i]);

        }

        return st.size();

    }
    int minOperations(vector<string>& logs) {
        
        // APPROACH 1:- USING SIMPLE TRAVERSE THE ARRAY
        // T.C:- O(n) , S.C :- O(1)
        // return a1(logs);

        // APPROACH 2:- USING STACK
        // T.C:- O(n) , S.C :- O(n)
        return a2(logs);
    }
};